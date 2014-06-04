import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;


public class DateTest {
	
	public static void everyMonday(){
		Calendar cal = Calendar.getInstance();
//		cal.setFirstDayOfWeek(Calendar.MONDAY);
		cal.set(cal.DAY_OF_WEEK, Calendar.TUESDAY);
		cal.set(Calendar.HOUR_OF_DAY, Calendar.AM_PM);

		Date endDate = new Date(System.currentTimeMillis() + 24*60*60*1000 * 20);
		System.out.println(endDate);
		
		for(Date date = cal.getTime(); date.before(endDate); date = cal.getTime()){
			System.out.println(date);
			cal.add(Calendar.DATE, 7);
		}
		
//		cal.add(Calendar.DATE, Calendar.DAY_OF_WEEK);
//		cal.add(Calendar.DATE, Calendar.DAY_OF_WEEK);
//		cal.add(Calendar.DATE, Calendar.DAY_OF_WEEK);
//		cal.add(Calendar.DATE, Calendar.DAY_OF_WEEK);
		Date date = cal.getTime();
		System.out.println(date.before(endDate));
		System.out.println(date);
	}
	
	@SuppressWarnings("deprecation")
	public static void main(String[] args){
		int year = 2014;
		int month = 3;
		
		Calendar cal = Calendar.getInstance();
		cal.set(year, month, 1, 0, 0, 0);
		Date beginDate = cal.getTime();
		
		cal.add(Calendar.MONTH, 1);
		Date endDate = cal.getTime();
		
		System.out.println(beginDate);
		System.out.println(endDate);
		Date currDate = new Date();
		
		cal.setTime(beginDate);
		for(Date date = beginDate; date.before(endDate); date = cal.getTime()){
			System.out.print(date.getDate());
			SimpleDateFormat sdf = new SimpleDateFormat("yyyyMMdd");
			System.out.println(sdf.format(currDate).equals(sdf.format(date)));
			cal.add(Calendar.DATE, 1);
		}
		
		System.out.println(new Date().getYear() + 1900);
		System.out.println(new Date().getMonth());
		System.out.println(new Date().getHours());
		
		Date date = new Date();
		cal.set(date.getYear() + 1900, date.getMonth(), date.getDate(), 0, 0, 0); 
		System.out.println(cal.getTime());
		cal.add(Calendar.DATE, 1);
		System.out.println(cal.getTime());
	}

}
