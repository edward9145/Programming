import model.CounterLogic;
import view.CounterInputView;
import view.CounterNumberView;
import view.CounterStarView;
import controller.ViewUpdater;



public class Counter {

	// 現在のカウントを格納するモデルを操作するロジック
	CounterLogic counterLogic;
	// カウントアップするかどうか問い合わせるビュー
	CounterInputView counterInputView;	
	// ビューの一覧を保持し，更新をかけるコントローラー
	ViewUpdater counterViewUpdater;
	
	/**
	 * @param args
	 * @throws Exception 
	 */
	public static void main(String[] args) throws Exception {
		new Counter();
	}

	public Counter(){
		counterLogic = new CounterLogic();
		counterViewUpdater = new ViewUpdater();
		counterInputView = new CounterInputView(counterLogic, counterViewUpdater);

		counterViewUpdater.addView(new CounterNumberView());
		counterViewUpdater.addView(new CounterStarView());
	}
}
