package division.process;

import framework.process.Input;
import framework.process.Output;
import framework.process.Process;

public class DivisionProcess implements Process {	

	@Override
	public void process(Input input, Output output) {
		DividendAndDivisor dd = (DividendAndDivisor)input;
		int dividend = dd.getDividend();
		int divisor = dd.getDivisor();
		
		// 商と余を計算する
		int quotient = dividend / divisor;
		int remainder = dividend % divisor;

		QuotientAndRemainder qr = (QuotientAndRemainder)output;
		qr.setQuotient(quotient);
		qr.setRemainder(remainder);
	}

}
