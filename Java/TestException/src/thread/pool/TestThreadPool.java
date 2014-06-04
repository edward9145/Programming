package thread.pool;

import java.io.IOException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class TestThreadPool {

	public static void main(String[] args) throws IOException {
		System.in.read();
		
		ExecutorService singlePool = Executors.newSingleThreadExecutor();
		Runnable r1 = new MyThread("r1");
		Runnable r2 = new MyThread("r2");
		Runnable r3 = new MyThread("r3");
		Runnable r4 = new MyThread("r4");
		Runnable r5 = new MyThread("r5");
		
//		singlePool.execute(r1);
//		singlePool.execute(r2);
//		singlePool.shutdown();
	
		ExecutorService fixedPool = Executors.newFixedThreadPool(2);
//		fixedPool.execute(r1);
//		fixedPool.execute(r2);
//		fixedPool.execute(r3);
//		fixedPool.execute(r4);
//		fixedPool.execute(r5);
//		fixedPool.shutdown();
		
		ExecutorService cachePool = Executors.newCachedThreadPool();
		cachePool.execute(r1);
		cachePool.execute(r2);
		cachePool.execute(r3);
		cachePool.execute(r4);
		cachePool.execute(r5);
		cachePool.shutdown();
	}

}
