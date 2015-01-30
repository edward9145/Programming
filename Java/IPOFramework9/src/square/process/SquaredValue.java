package square.process;

import framework.process.Output;

public class SquaredValue implements Output {
	
	private double val = 0;

	public final double getVal() {
		return val;
	}

	public final void setVal(double val) {
		this.val = val;
	}

}
