package framework;

import framework.io.InputAndOutput;
import framework.process.Input;
import framework.process.Output;
import framework.process.Process;


public class Framework {

	InputAndOutput io;
	Input input;
	Output output;
	Process process;
	
	@SuppressWarnings("unchecked")
	public Framework(String ioClassName, String processClassName, String inputClassName, String outputClassName) throws ClassNotFoundException, InstantiationException, IllegalAccessException{
		Class ioClass = Class.forName(ioClassName);
		this.io = (InputAndOutput)ioClass.newInstance();
		
		Class processClass = Class.forName(processClassName);
		this.process = (Process)processClass.newInstance();
		
		Class inputClass = Class.forName(inputClassName);
		this.input = (Input)inputClass.newInstance();
		
		Class outputClass = Class.forName(outputClassName);
		this.output = (Output)outputClass.newInstance();
	}
	
	public static void main(String[] args) throws Exception{
		String ioClassName = args[0];
		String processClassName = args[1];
		String inputClassName = args[2];
		String outputClassName = args[3];
		
		Framework framework = new Framework(ioClassName, processClassName, inputClassName, outputClassName);
		framework.run();
	}
	
	protected void run() throws Exception{
		io.input(input);
		process.process(input, output);
		io.output(output);
	}

}
