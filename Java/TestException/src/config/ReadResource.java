package config;

import java.lang.reflect.Method;
import java.util.Date;



public class ReadResource {

	public static void main(String[] args) {
		ClassLoader loader = ReadResource.class.getClassLoader();
        System.out.println(loader.getResource("PushChat.p12").getPath());
        
        System.out.println(Config.prop("xmpp.ssl.storeType"));
        System.out.println(Config.prop("ACEI_ARB_NAMExx"));
        
        System.out.println();
        for(Object key : Config.configFile.keySet()){
        	System.out.print(key);
        	System.out.print("=");
        	System.out.println(Config.prop((String) key));
        }
        
        Person person = new Person("Edward", 20, new Date());
        
        for(Object key : Config.configFile.keySet()){
        	String keyStr = (String)key;
        	String[] arr = keyStr.split("\\.");
        	if(arr.length < 2) continue;
        	
        	String clz = arr[0];
        	String var = arr[1];
//        	System.out.println(Config.prop((String) key));
        	try{
        		Method method = Person.class.getDeclaredMethod("get" + var);
//        		System.out.println("get" + var);
				Object value = method.invoke(person);
				System.out.println(Config.prop(keyStr) + " " + var + " " + value);
        	}catch(Exception ex){
        		;
        	}
        }
        
        for(Object key : MapCRF.map.keySet()){
        	System.out.print(key);
        	System.out.print("=");
        	System.out.println(MapCRF.get((String) key));
        }
	}

}
