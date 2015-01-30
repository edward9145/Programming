package square.io;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

import square.process.RootValue;
import square.process.SquaredValue;

import framework.io.InputAndOutput;
import framework.process.Input;
import framework.process.Output;

public class SquareIO implements InputAndOutput {

	@Override
	public void input(Input input) throws IOException {
		System.out.print("自乗を計算する値を入力してください：");
		BufferedReader reader =
			new BufferedReader(new InputStreamReader(System.in));
		String inputString = reader.readLine();
		double val = Double.parseDouble(inputString);
		RootValue rootValue = (RootValue)input;
		rootValue.setVal(val);
	}

	@Override
	public void output(Output output) {
		SquaredValue squaredValue = (SquaredValue)output;
		System.out.println("計算結果：" + squaredValue.getVal());
	}

}
