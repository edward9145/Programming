import java.util.Random;


public class Numeric {

	public static void main(String[] args) {
		Float fn = null;
		Float f0 = 0f;
//		System.out.println(fn.isNaN());
		System.out.println(f0.isNaN(0f));
		System.out.println(f0 == 0f);

		System.out.println();
		
		for(int i=0;i<10000;i++) 
			System.out.println(String.format("%04d", i));
	}

}
