import java.lang.reflect.Method;

public class Main {
	
	public static void main(String[] args) {
		
		for(String key : PropertyMap.crf.keySet()){
			System.out.print(key + "=");
			System.out.println(PropertyMap.crf.get(key));
		}
		
	}

}
