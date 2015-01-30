package controller;
import java.util.ArrayList;
import java.util.List;

import model.CounterValueObject;
import view.View;


public class ViewUpdater {
	
	List<View> views;
	
	public ViewUpdater(){
		this.views = new ArrayList<View>();
	}

	public void addView(View view) {
		this.views.add(view);
	}
	
	public void outputAll(CounterValueObject counterValueObject){
		for(View view : views){
			view.output(counterValueObject);
		}
	}

}
