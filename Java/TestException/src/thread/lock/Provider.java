package thread.lock;

import java.util.concurrent.locks.Lock;

public class Provider implements Runnable {

	BankCard bc;
	Lock lock;
	
	public Provider(BankCard bc, Lock lock){
		this.bc = bc;
		this.lock = lock;
	}
	
	@Override
	public void run() {
		try{
			for(int i=0; i<20; i++){
			lock.lock();
			System.out.println("balance: " + bc.getBalance() + "\t ");
			bc.setBalance(bc.getBalance() + 500);
			System.out.println("+500: " + bc.getBalance());
			lock.unlock();
			Thread.sleep(1000);
			}
		}
		catch(Exception ex){
			ex.printStackTrace();
		}
	}

}
