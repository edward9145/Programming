package model;

public class CounterLogic {
	
	CounterValueObject counterValueObject;

	public CounterLogic(){
		this.counterValueObject = new CounterValueObject(0);
	}
	
	
	public final CounterValueObject getCounterValueObject() {
		return counterValueObject;
	}

	public final void setCounterValueObject(CounterValueObject counterValueObject) {
		this.counterValueObject = counterValueObject;
	}

	public void countUp(){
		this.counterValueObject.count ++;
	}

}
