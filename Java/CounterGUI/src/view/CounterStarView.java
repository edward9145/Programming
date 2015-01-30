package view;

import java.awt.Container;
import java.awt.FlowLayout;

import javax.swing.JFrame;
import javax.swing.JLabel;

import model.CounterValueObject;


public class CounterStarView implements View {

	private JLabel jlStar;

	public CounterStarView() {
		// 星を表示するためのウィンドウを生成し，サイズとレイアウトを設定する
		JFrame frame = new JFrame("CounterStarView");
		frame.setBounds(0, 100, 300, 80);
		frame.setLayout(new FlowLayout());

		// 星を表示するためのコンポーネントを配置する
		Container contentPane = frame.getContentPane();
		// 星値を表示するラベルを追加する
		jlStar = new JLabel("");
		contentPane.add(jlStar);
		// ウィンドウを可視化する
		frame.setVisible(true);
	}

	public void output(CounterValueObject counterValueObject) {
		// 星を表示する
		StringBuffer sb = new StringBuffer();
		for (int i = 0; i < counterValueObject.getCount(); i++) {
			sb.append("*");
		}
		jlStar.setText(sb.toString());
	}


}
