
public class CounterStarView implements View {

	@Override
	public void output(CounterModel model) {
		for(int i = 0; i < model.count; i++) {
            System.out.print("*");
        }
        System.out.println();
	}

}
