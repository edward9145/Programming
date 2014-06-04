package thread.pool;

public class MyThread implements Runnable {

	String id = "ID";
	
	public MyThread(String id){
		this.id = id;
	}
	
	@Override
	public void run() {
		System.out.println(Thread.currentThread().getName() + " running.... " + this.id);
	}
	

}
