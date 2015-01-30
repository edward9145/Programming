package square.process;

import framework.process.Input;
import framework.process.Output;
import framework.process.Process;

public class SquareProcess implements Process {
	
	@Override
	public void process(Input input, Output output) {
		RootValue rootValue = (RootValue)input;
		SquaredValue squaredValue = (SquaredValue)output;
		double val = rootValue.getVal();
		squaredValue.setVal(val * val);
	}

}
