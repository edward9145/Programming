package thread.lock;

import java.util.concurrent.locks.Lock;

public class Consumer implements Runnable {

	BankCard bc;
	Lock lock;
	
	public Consumer(BankCard bc, Lock lock){
		this.bc = bc;
		this.lock = lock;
	}
	
	@Override
	public void run() {
		try{
			for(int i=0; i<10; i++){
			lock.lock();
			System.out.println("balance: " + bc.getBalance() + "\t ");
			bc.setBalance(bc.getBalance() - 2000);
			System.out.println("-2000: " + bc.getBalance());
			lock.unlock();
			Thread.sleep(1000);
			}
		}
		catch(Exception ex){
			ex.printStackTrace();
		}
	}

}
