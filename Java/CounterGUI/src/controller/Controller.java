package controller;
import model.CounterLogic;


public interface Controller {
	
	public void process(CounterLogic counterLogic, ViewUpdater viewUpdater);

}
