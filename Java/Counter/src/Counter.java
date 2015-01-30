import java.util.ArrayList;
import java.util.List;



public class Counter {

	CounterModel model;
	CounterView inputView;
	List<View> outputViews;
	
	/**
	 * @param args
	 * @throws Exception 
	 */
	public static void main(String[] args) throws Exception {
		Counter counter = new Counter();
		counter.run();
	}

	public Counter(){
		this.model = new CounterModel();
		this.inputView = new CounterView();
		
		this.outputViews = new ArrayList<View>();
		this.outputViews.add(new CounterView());
		this.outputViews.add(new CounterStarView());
	}
	
	// main()は省略    
    private void run() throws Exception {
        while(true) {
            Controller controller = inputView.input();
            
            controller.process(model, this);
            
            if(controller instanceof StopController){
            	break;
            }
        }
    }
    
    public void outputAll(){
    	for(View view : outputViews){
    		view.output(model);
    	}
    }
}
