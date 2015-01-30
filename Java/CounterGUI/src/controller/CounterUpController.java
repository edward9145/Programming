package controller;
import model.CounterLogic;


public class CounterUpController implements Controller {

	@Override
	public void process(CounterLogic counterLogic, ViewUpdater viewUpdater) {
		counterLogic.countUp();
		viewUpdater.outputAll(counterLogic.getCounterValueObject());
	}

}
