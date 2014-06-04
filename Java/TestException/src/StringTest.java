
public class StringTest {

	public static void main(String[] args) {
		String keyword = "sa";
		System.out.println("2000".contains(keyword) || "like".contains(keyword));
		
		String varname = "crf_demo_screen";
		String[] arr = varname.split("_");
		String VarName = "";
		for(String str : arr){
			VarName += str.substring(0, 1).toUpperCase() + str.substring(1);
		}
		System.out.println(VarName);
		
		int raise = 10;
		
		System.out.println("RAISE" + raise);
	}

}
