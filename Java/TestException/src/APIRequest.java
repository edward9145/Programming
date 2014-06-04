import java.io.IOException;
import java.io.InputStream;
import java.io.UnsupportedEncodingException;
import java.net.HttpURLConnection;
import java.net.URL;

import org.jsoup.Jsoup;
import org.jsoup.nodes.Document;


public class APIRequest {

	public static void test() throws IOException{
		URL url = new URL("http://app.hualuyikang.com/xyj/api/question/answer.htm?questionId=09");  
		HttpURLConnection urlConnection = (HttpURLConnection)url.openConnection();  
        //Post Request Define:   
        urlConnection.setRequestMethod("GET");  
        urlConnection.connect();  
          
        //Connection Response From Test Servlet  
        System.out.println("Connection Response From Test Servlet");  
        InputStream inputStream = urlConnection.getInputStream();  
          
        //Convert Stream to String  
        String responseStr = StreamToString.ConvertToString(inputStream);  
        System.out.println(responseStr);  
	}
	
	public static void callRecord() throws IOException{
		String responseStr = RequestAPI
				.get("http://callcenter.hualuyikang.com/admin/xyj_call_record.asp");
		char[] cs = responseStr.toCharArray();
		for(char c : cs){
			System.out.printf("%c  ", c);
		}
//		System.out.println();
		byte[] buf = responseStr.getBytes();
		for(byte b : buf){
			System.out.printf("%02x ", b);
		}
		System.out.println();
		String record = responseStr;
		try {
			record = new String(responseStr.getBytes("GB2312"), "UTF-8");
		} catch (UnsupportedEncodingException e) {
			e.printStackTrace();
		}
		System.out.println(record);
		
	}
	
	public static void main(String[] args) throws IOException {
		
		Document doc = Jsoup.connect("http://callcenter.hualuyikang.com/admin/xyj_call_record.asp")				  
				  .timeout(10000)
				  .get();
		System.out.println(doc.text());
	}

}
