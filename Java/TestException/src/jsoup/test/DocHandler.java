package jsoup.test;

import java.io.IOException;

import org.jsoup.Jsoup;
import org.jsoup.nodes.Document;

public class DocHandler {
	
	public static void main(String[] args) throws IOException {
		String url = "http://localhost:8080/YiKangXYJ/api/report/html?patientId=001user1";
		Document doc = Jsoup.connect(url)
				  .timeout(10000)
				  .get();

//		System.out.println(doc.getElementById("reportBody"));
		System.out.println(doc.getElementById("reportBody").html());
		System.out.println(doc.getElementById("reportBody").text());
	}

}
