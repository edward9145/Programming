
public class StopController implements Controller {

	@Override
	public void process(CounterModel model, Counter counter) {
		CounterView.stop();
	}

}
