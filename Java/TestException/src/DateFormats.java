import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;

import org.apache.commons.lang3.time.DateUtils;

public class DateFormats {

	public static Date getWeekFirstDay(Date date) {
		Date _date = DateUtils.truncate(date, Calendar.DAY_OF_MONTH);  
        Calendar c = Calendar.getInstance();  
        c.setTime(_date);
        // 星期：1，2，3，4，5，6，7  
        int iWeek = c.get(Calendar.DAY_OF_WEEK);  
        //时期日->星期八  
        if(iWeek == 1){  
            iWeek = 8;
        }
        return DateUtils.addDays(_date, 2 - iWeek);  
	}
	
	public static Date getNextWeekFirstDay(Date date) {
		Date _date = DateUtils.truncate(date, Calendar.DAY_OF_MONTH);  
        Calendar c = Calendar.getInstance();  
        c.setTime(_date);
        // 星期：1，2，3，4，5，6，7  
        int iWeek = c.get(Calendar.DAY_OF_WEEK);  
        //时期日->星期八  
        if(iWeek == 1){  
            iWeek = 8;
        }
        return DateUtils.addDays(_date, 8 - iWeek + 1);  
	}
	
	public static Week getWeekByDate(Date date) throws ParseException {  
        Date _date = DateUtils.truncate(date, Calendar.DAY_OF_MONTH);  
        Calendar c = Calendar.getInstance();  
        c.setTime(_date);  
        // 星期：1，2，3，4，5，6，7  
        int iWeek = c.get(Calendar.DAY_OF_WEEK);  
        //时期日->星期八  
        if(iWeek == 1){  
            iWeek = 8;  
        }  
        Week week = new Week(_date);  
        // 算出离星期一（2）的距离  
        week.setBeginDate(DateUtils.addDays(_date, 2 - iWeek));  
        // 算出离星期日（8）的距离  
        week.setEndDate(DateUtils.addDays(_date, 8 - iWeek + 1));  
        return week;  
    }
	
	/**
	* 得到指定日期当月的1号
	 * @throws ParseException 

	*/

	public static Date getBeforeMonthFirstDay(Date date) throws ParseException {
	        Calendar lastDate = Calendar.getInstance();
	        SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd");   
	        if(date == null){ 
	        	date = new Date();
	        }
	        lastDate.setTime(date);//设置日历时间   
	        lastDate.set(Calendar.DATE,1);//设为当前月的1 号
	    	lastDate.add(Calendar.MONTH,0);//当月1号
//	    	lastDate.add(Calendar.MONTH,1);//下月1号
	    	String strDate = sdf.format(lastDate.getTime());
	        return sdf.parse(strDate);
	 }
	/**
	* 得到指定日期下月的1号

	*/

	public static String  getNextMonthFirstDay(Date date) {
	        Calendar lastDate = Calendar.getInstance();
	        SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd");   
	        if(date == null){ 
	        	date = new Date();
	        }
	        lastDate.setTime(date);//设置日历时间   
	        lastDate.set(Calendar.DATE,1);//设为当前月的1 号
//	    	lastDate.add(Calendar.MONTH,-1);//上月1号
	    	lastDate.add(Calendar.MONTH,1);//下月1号
	        String strDate = sdf.format(lastDate.getTime());//的到你想要得6个月后的日期   
	        return strDate;
	 }
	/**
	* 得到指定日期当月的1号

	*/

	public static String  getMonthFirstDay(Date date) {
	        Calendar lastDate = Calendar.getInstance();
	        SimpleDateFormat sdf = new SimpleDateFormat("yyyy/MM");   
	        if(date == null){ 
	        	date = new Date();
	        }
	        lastDate.setTime(date);//设置日历时间   
	        lastDate.set(Calendar.DATE,1);//设为当前月的1 号
	    	lastDate.add(Calendar.MONTH,0);//当月1号
//	    	lastDate.add(Calendar.MONTH,1);//下月1号
	        String strDate = sdf.format(lastDate.getTime());//的到你想要得6个月后的日期   
	        return strDate;
	 }
	
	/**
	* 得到二个日期间的间隔天数
	*/
	public static String getTwoDay(String sj1, String sj2) {
		SimpleDateFormat myFormatter = new SimpleDateFormat("yyyy-MM-dd");
		
		long day = 0;
		try {
		java.util.Date date = myFormatter.parse(sj1);
		java.util.Date mydate = myFormatter.parse(sj2);
		day = (date.getTime() - mydate.getTime()) / (24 * 60 * 60 * 1000);
		} catch (Exception e) {
		return "";
		}
		return day + "";
	}
	
	public static void main(String[] args){
		Date now = new Date();
		System.out.println(getWeekFirstDay(now));
		System.out.println(getNextWeekFirstDay(now));
		
		try {
			System.out.println(getBeforeMonthFirstDay(now));
		} catch (ParseException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		}
		Week week;
		try {
			week = DateFormats.getWeekByDate(now);
			System.out.println(week.getBeginDate());
			System.out.println(week.getEndDate());
		} catch (ParseException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		
	}
}