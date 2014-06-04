package config;

import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;

public class MapCRF {

	public static OrderedProperties map;
	static{
		new MapCRF();
	}

	public MapCRF() {
		if (MapCRF.map != null) return;
		map = new OrderedProperties();
		try {
			InputStream inputStream = this.getClass().getResourceAsStream(
					"/crf.map");
			BufferedReader bf = new BufferedReader(new InputStreamReader(
					inputStream));
			map.load(bf);
		} catch (Exception eta) {
			eta.printStackTrace();
		}
	}

	public static String get(String key) {
		if (map == null)
			new Config();
		String value = map.getProperty(key);
		return value;
	}
}
