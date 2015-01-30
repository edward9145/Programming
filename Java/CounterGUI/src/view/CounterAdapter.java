package view;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import controller.Controller;
import controller.ViewUpdater;

import model.CounterLogic;


public class CounterAdapter implements ActionListener {

	private CounterLogic counterLogic;
	private ViewUpdater viewUpdater;
	private Controller controller;
	
	public CounterAdapter(CounterLogic counterLogic,
			ViewUpdater viewUpdater, Controller controller) {
		this.counterLogic = counterLogic;
		this.viewUpdater = viewUpdater;
		this.controller = controller;
	}
	
	public void actionPerformed(ActionEvent ae) {
		this.controller.process(this.counterLogic, this.viewUpdater);
	}


}
