import java.lang.reflect.Field;
import java.util.Date;
import java.util.HashMap;
import java.util.Map;

import config.Person;


public class ObjectMap {

	public static String[] passFields = {"ID", "TS", "DR", "PERCENT","PATIENT_ID"};
	
	public static Map<String, String> objMap(Object obj, String[] passFields){
		Map<String, String> map = new HashMap<String, String>();
		Field[] fields = obj.getClass().getDeclaredFields();
		System.out.println(obj.getClass().getSimpleName());
		for(Field field : fields){
			boolean pass = false;
			for(String key : passFields){
				if(key.equals(field.getName()))
					pass = true;
			}
			if(pass) continue;
			
			try{
				field.setAccessible(true);
				map.put(field.getName(), (String) field.get(obj));
			} catch(Exception ex) { }
		}
		
		return map;
	}
	
	public static void main(String[] args) {
		Person p = new Person("Edw", 0, new Date());
		Map<String, String> map = ObjectMap.objMap(p, passFields);
		Object[] strArr = new String[map.size()];
		map.values().toArray(strArr);
		for(Object str : strArr){
			System.out.println(str);
		}
		for(String key : map.keySet()){
			System.out.println(map.get(key));
		}
	}

}
