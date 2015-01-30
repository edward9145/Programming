package division.process;

import framework.process.Output;

public class QuotientAndRemainder implements Output {
	
	private int quotient;
	private int remainder;
	
	public final int getQuotient() {
		return quotient;
	}
	public final void setQuotient(int quotient) {
		this.quotient = quotient;
	}
	public final int getRemainder() {
		return remainder;
	}
	public final void setRemainder(int remainder) {
		this.remainder = remainder;
	}

}
