package yahoo.api;

import java.io.IOException;

import org.jsoup.Jsoup;
import org.jsoup.nodes.Document;

public class KanjiParser {

	public static void main(String[] args) throws IOException {
		String url = "http://jlp.yahooapis.jp/MAService/V1/parse";
		String param = "?appid=dj0zaiZpPU13ZFdHcFJDY3E0TSZzPWNvbnN1bWVyc2VjcmV0Jng9NjM-&results=ma,uniq&uniq_filter=9%7C10&sentence=日本語形態素解析APIを使用したサンプルコードです";
		Document doc = Jsoup.connect(url + param)
				  .userAgent("Mozilla")
				  .timeout(10000)
				  .get();

		System.out.println(doc.html());
	}

}
