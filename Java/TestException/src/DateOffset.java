import java.util.Calendar;
import java.util.Date;


public class DateOffset {

	static long DAY_MILI = 1000 * 60 * 60 * 24;
	
	public static void main(String[] args) {
		Date now = new Date();
		Date before = new Date(now.getTime() - DAY_MILI * 30 + 10);
		
		int days = (int) ((now.getTime() - before.getTime())/DAY_MILI);		
		System.out.println(days);
		
		
		Calendar cal = Calendar.getInstance();
		cal.set(Integer.parseInt("2014"), 3, 3);
//		Calendar calNow = Calendar.getInstance();
		System.out.println(cal.getTime());
		
		System.out.println(new Date(2014-1900,3,4));

	}

}
