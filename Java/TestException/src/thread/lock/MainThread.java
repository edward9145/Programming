package thread.lock;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class MainThread {

	public static void main(String[] args) {
		BankCard bc = new BankCard();
		Lock lock = new ReentrantLock();
		
		ExecutorService pool = Executors.newCachedThreadPool();
		Consumer cm = new Consumer(bc, lock);
		Provider pv = new Provider(bc, lock);
		pool.execute(cm);
		pool.execute(pv);
	}

}
