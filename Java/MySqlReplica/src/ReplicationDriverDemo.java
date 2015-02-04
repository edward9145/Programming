import java.sql.Connection;
import java.sql.ResultSet;
import java.util.Properties;

import com.mysql.jdbc.ReplicationDriver;

public class ReplicationDriverDemo {

  public static void main(String[] args) throws Exception {
    ReplicationDriver driver = new ReplicationDriver();

    Properties props = new Properties();

    // We want this for failover on the slaves
    props.put("autoReconnect", "true");

    // We want to load balance between the slaves
    props.put("roundRobinLoadBalance", "true");

    props.put("user", "root");
    props.put("password", "freely");

    //
    // Looks like a normal MySQL JDBC url, with a
    // comma-separated list of hosts, the first
    // being the 'master', the rest being any number
    // of slaves that the driver will load balance against
    //

    Connection conn =
        driver.connect("jdbc:mysql:replication://192.168.1.81,192.168.1.84,192.168.1.85/sakila",
            props);

//    driver.connect("jdbc:mysql:replication://192.168.1.81,192.168.1.85/sakila",
//            props);
    
    //
    // Perform read/write work on the master
    // by setting the read-only flag to "false"
    //
/*
    conn.setReadOnly(false);
    conn.setAutoCommit(false);
    conn.createStatement().executeUpdate("insert into master_tbl values (10, 'm10', 10)");
    conn.commit();
*/
    //
    // Now, do a query from a slave, the driver automatically picks one
    // from the list
    //

    conn.setReadOnly(true);

    ResultSet rs =
      conn.createStatement().executeQuery("SELECT * FROM master_tbl");
    
    while(rs.next()){
    	String name = rs.getString(2);
    	System.out.println(name);
    }
  }
}