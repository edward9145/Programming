package view;
import java.awt.Container;
import java.awt.FlowLayout;

import javax.swing.JButton;
import javax.swing.JFrame;

import model.CounterLogic;
import controller.CounterUpController;
import controller.StopController;
import controller.ViewUpdater;


public class CounterInputView {
	
	private JButton jbCountUp;
	private JButton jbStop;

	public CounterInputView(CounterLogic counterLogic, ViewUpdater viewUpdater) {
		// ボタンを表示するためのウィンドウを生成し，サイズとレイアウトを設定する
		JFrame frame = new JFrame("CounterInputView");
		frame.setBounds(0, 200, 200, 80);
		frame.setLayout(new FlowLayout());
		// カウント値を表示するためのコンポーネントを配置する
		Container contentPane = frame.getContentPane();
			// カウントアップボタンを配置する
		jbCountUp = new JButton("Count Up");
		jbCountUp.addActionListener(
				new CounterAdapter(counterLogic, viewUpdater,
						new CounterUpController()));
		
		contentPane.add(jbCountUp);
		// ストップボタンを配置する
		jbStop = new JButton("Stop");
		jbStop.addActionListener(
				new CounterAdapter(counterLogic, viewUpdater,
						new StopController()));
		
		contentPane.add(jbStop);
		// ウィンドウを可視化する
		frame.setVisible(true);
	}
}
