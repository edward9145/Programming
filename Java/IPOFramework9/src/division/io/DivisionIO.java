package division.io;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

import division.process.DividendAndDivisor;
import division.process.QuotientAndRemainder;

import framework.io.InputAndOutput;
import framework.process.Input;
import framework.process.Output;

public class DivisionIO implements InputAndOutput {

	@Override
	public void input(Input input) throws IOException {
		// 割られる数と割る数を読み込む
		BufferedReader reader =
			new BufferedReader(new InputStreamReader(System.in));
		System.out.print("割られる数を入力してください：");
		String dividendString = reader.readLine();
		int dividend = Integer.parseInt(dividendString);
		System.out.print("割る数を入力してください：");
		String divisorString = reader.readLine();
		int divisor = Integer.parseInt(divisorString);
		
		DividendAndDivisor dd = (DividendAndDivisor)input;
		dd.setDividend(dividend);
		dd.setDivisor(divisor);
	}

	@Override
	public void output(Output output) {
		QuotientAndRemainder qr = (QuotientAndRemainder)output;
		
		// 割り算の結果を表示する
		System.out.print("商は" + qr.getQuotient() + "で余は" 
				+ qr.getRemainder() + "です");
	}

}
