import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.net.HttpURLConnection;
import java.net.URL;

public class RequestAPI {
	
	public static String get(String addr) throws IOException{
		URL url = new URL(addr);  
		HttpURLConnection urlConnection = (HttpURLConnection)url.openConnection();  
        //Post Request Define:   
        urlConnection.setRequestMethod("GET");  
        urlConnection.connect();  

        //Connection Response From Test Servlet  
        System.out.println("Connection Response From Test Servlet");  
        InputStream inputStream = urlConnection.getInputStream();  
          
        //Convert Stream to String  
        String responseStr = RequestAPI.streamToString(inputStream);  
        return responseStr;
	}
	
	public static String post(String addr, String param) throws IOException{
		URL url = new URL(addr);  
		HttpURLConnection urlConnection = (HttpURLConnection)url.openConnection();  
        //Post Request Define:   
        urlConnection.setRequestMethod("POST");
        
        // Send post request
        urlConnection.setDoOutput(true);
 		DataOutputStream wr = new DataOutputStream(urlConnection.getOutputStream());
 		BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(wr, "UTF-8"));
 		writer.write(param);
 		writer.flush();
 		writer.close();
// 		wr.writeBytes(param);
// 		wr.flush();
 		wr.close();
 		
 		BufferedReader in = new BufferedReader(
		        new InputStreamReader(urlConnection.getInputStream()));
		String inputLine;
		StringBuffer response = new StringBuffer();
 
		while ((inputLine = in.readLine()) != null) {
			response.append(inputLine);
		}
		in.close();
        return response.toString();
	}

	public static String streamToString(InputStream inputStream){
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
