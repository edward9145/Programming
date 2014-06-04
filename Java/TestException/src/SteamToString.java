import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;

class StreamToString{
	public static String ConvertToString(InputStream inputStream){
		InputStreamReader inputStreamReader = new InputStreamReader(inputStream);
		BufferedReader bufferedReader = new BufferedReader(inputStreamReader);
		StringBuilder result = new StringBuilder();
		String line = null;
		try {
			while((line = bufferedReader.readLine()) != null){
				result.append(line + "\n");
			}
		} catch (IOException e) {
			e.printStackTrace();
		} finally {
			try{
				inputStreamReader.close();
				inputStream.close();
				bufferedReader.close();
			}catch(IOException e){
				e.printStackTrace();
			}
		}
		return result.toString();
	}


	public static String ConvertToString(FileInputStream inputStream){
		InputStreamReader inputStreamReader = new InputStreamReader(inputStream);
		BufferedReader bufferedReader = new BufferedReader(inputStreamReader);
		StringBuilder result = new StringBuilder();
		String line = null;
		try {
			while((line = bufferedReader.readLine()) != null){
				result.append(line + "\n");
			}
		} catch (IOException e) {
			e.printStackTrace();
		} finally {
			try{
				inputStreamReader.close();
				inputStream.close();
				bufferedReader.close();
			}catch(IOException e){
				e.printStackTrace();
			}
		}
		return result.toString();
	}
}
