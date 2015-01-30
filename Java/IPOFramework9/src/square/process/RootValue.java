package square.process;

import framework.process.Input;

public class RootValue implements Input {
	
	private double val = 0;

	public final double getVal() {
		return val;
	}

	public final void setVal(double val) {
		this.val = val;
	}	

}
