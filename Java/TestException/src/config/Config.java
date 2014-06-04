package config;

import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;


public class Config {
	
	public static OrderedProperties configFile;

	public Config() {
		if(Config.configFile != null)
			return;
		configFile = new OrderedProperties();
		try {
			InputStream inputStream = this.getClass().getResourceAsStream("/config.properties"); 
			BufferedReader bf = new BufferedReader(new InputStreamReader(inputStream));  
			configFile.load(bf);
		} catch (Exception eta) {
			eta.printStackTrace();
		}
	}

		public static String prop(String key) {
			if(configFile == null) new Config();
			String value = configFile.getProperty(key);
			return value;
		}
}