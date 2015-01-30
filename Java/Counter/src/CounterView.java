import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


public class CounterView implements View{
	
	public Controller input() throws IOException {
		System.out.print("カウントアップしますか？（Enterのみで終了）");
        BufferedReader reader =
            new BufferedReader(
                new InputStreamReader(System.in));
        String input = reader.readLine();
        
        if("".equals(input)){
        	return new StopController();
        }
        
        return new CounterUpController();

	}

	public void output(CounterModel model){
		System.out.println("現在の値は" + model.count + "です");
	}
	
	public static void stop(){
		System.out.println("終了します");
	}
	
}
