package view;

import java.awt.Container;
import java.awt.FlowLayout;

import javax.swing.JFrame;
import javax.swing.JLabel;

import model.CounterValueObject;


public class CounterNumberView implements View {

	private JLabel jlNumber;
	
	public CounterNumberView() {
		// カウント値を表示するためのウィンドウを生成し，サイズとレイアウトを設定する
		JFrame frame = new JFrame("CounterNumberView");
		frame.setBounds(0, 0, 200, 80);
		frame.setLayout(new FlowLayout());
		
		// カウント値を表示するためのコンポーネントを配置する
		Container contentPane = frame.getContentPane();
		// カウント値を表示するラベルを追加する
		jlNumber = new JLabel("0");
		contentPane.add(jlNumber);
		// ウィンドウを可視化する
		frame.setVisible(true);
	}

	public void output(CounterValueObject counterValueObject) {
		jlNumber.setText(Integer.toString(counterValueObject.getCount()));
	}



}
