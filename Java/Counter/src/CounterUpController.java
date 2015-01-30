
public class CounterUpController implements Controller {

	@Override
	public void process(CounterModel model, Counter counter) {
		model.countUp();
		counter.outputAll();
	}

}
