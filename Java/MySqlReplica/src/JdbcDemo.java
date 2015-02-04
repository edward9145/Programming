import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.Properties;

import com.mysql.jdbc.Driver;
 
public class JdbcDemo {
	
  public static void main(String[] args) throws Exception {
    Driver driver = new Driver();
    Properties props = new Properties();
    ResultSet rs;
    String variable_value;
    Connection conn = null;
    String JDBC_URL = "jdbc:mysql:replication://192.168.1.81,192.168.1.85/sakila";
 
    props.put("replicationConnectionGroup", "rep_group");
    props.put("replicationEnableJMX", "true");
 
    props.put("user", "root");
    props.put("password", "freely");
 
    System.out.println("\n------------ MySQL Connector/J and MySQL Replication Testing ------------\n");
 
    try {
    	Class.forName("com.mysql.jdbc.ReplicationDriver");
    }
    catch (ClassNotFoundException e) {
    	System.out.println("Where is your MySQL JDBC Driver?");
	e.printStackTrace();
	return;
    }
 
    System.out.println("MySQL Connector/J driver loaded");
 
    System.out.println("Trying connection...");
 
    try {
		conn = driver.connect(JDBC_URL, props);
	}
	catch (SQLException e) {
		System.out.println("Connection Failed! Check output console");
		//e.printStackTrace();
		System.out.println("Error cause: "+e.getCause());
		System.out.println("Error message: "+e.getMessage());
		return;
	}
 
    System.out.println("Connection established...");
 
    for(int i=1; i <= 1000; i++) {
    	System.out.println("\nQuery "+i+": ");
    	// Fake Read Write SQL statement (just to see where it goes)
    	System.out.println("Read Write query...");
    	try {
    		conn.setReadOnly(false);
    	}
    	catch (SQLException e) {
    		System.out.println("Connection read write property set has has failed...");
    	}
 
    	try {
    		rs = conn.createStatement().executeQuery("SELECT variable_value FROM information_schema.global_variables where variable_name='hostname'");
    		while (rs.next()) {
    			variable_value = rs.getString("variable_value");
    			System.out.println("variable_value : " + variable_value);
    		}
	    }
    	catch (SQLException e) {
    		System.out.println("Read/write query has failed...");
    	}
 
    	// Read Only statement
    	System.out.println("Read Only query...");
    	try {
    		conn.setReadOnly(true);	
    	}
    	catch (SQLException e) {
    		System.out.println("Connection read only property set has has failed...");
    	}
 
    	try {
    		rs = conn.createStatement().executeQuery("SELECT variable_value FROM information_schema.global_variables where variable_name='hostname'");
    		while (rs.next()) {
    			variable_value = rs.getString("variable_value");
    			System.out.println("variable_value : " + variable_value);
    		}
    		}
    	catch (SQLException e) {
    		System.out.println("Read only query has failed...");
    	}
 
    	Thread.sleep(2000);
    }
  }
}