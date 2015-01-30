package division.process;

import framework.process.Input;

public class DividendAndDivisor implements Input {
	
	private int dividend;
	private int divisor;
	
	public final int getDividend() {
		return dividend;
	}
	public final void setDividend(int dividend) {
		this.dividend = dividend;
	}
	public final int getDivisor() {
		return divisor;
	}
	public final void setDivisor(int divisor) {
		this.divisor = divisor;
	}

}
