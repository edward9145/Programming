import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.LinkedHashMap;

public class PropertyMap{

	public static LinkedHashMap<String, String> crf = PropertyMap
			.fileToMap("crf.map");

	public static LinkedHashMap<String, String> fileToMap(String filename) {
		OrderedProperties properties;
		properties = new OrderedProperties();
		try {
			InputStream inputStream = new PropertyMap().getClass()
					.getResourceAsStream("/" + filename);
			BufferedReader bf = new BufferedReader(new InputStreamReader(
					inputStream));
			properties.load(bf);
		} catch (Exception ex) {
			ex.printStackTrace();
		}

		LinkedHashMap<String, String> map = new LinkedHashMap<String, String>();
		for (Object key : properties.keySet()) {
			String val = properties.getProperty((String) key);
			map.put((String) key, val);
			System.out.print(key + "=" + val);
		}
		System.out.println();
		return map;
	}
}
