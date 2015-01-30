package framework.io;

import java.io.IOException;

import framework.process.Input;
import framework.process.Output;

public interface InputAndOutput {
	
	public void input(Input input) throws IOException;
	
	public void output(Output output);

}
