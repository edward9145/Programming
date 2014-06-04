package annotation;

import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.util.Date;

public class TestObject {

	@RequestForEnhancement(id = 0, synopsis = "Enable time-travel")
	public static void travelThroughTime(Date destination){
		System.out.println("Traveling...");
	}
	
	public static void main(String[] args) throws IllegalAccessException, IllegalArgumentException, InvocationTargetException {
		Method[] methods = TestObject.class.getDeclaredMethods();
		for(Method method : methods){
//			if(method.isAnnotationPresent(RequestForEnhancement.class)){
				System.out.println("@");
				method.invoke(null, null);
//			}
			System.out.println(method.getName());
		}
		
	}

}
