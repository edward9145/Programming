package controller;
import model.CounterLogic;


public class StopController implements Controller {

	@Override
	public void process(CounterLogic counterLogic, ViewUpdater viewUpdater) {
		System.exit(0);
	}

}
