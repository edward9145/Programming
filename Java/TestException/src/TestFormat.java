import java.sql.Timestamp;
import java.text.DateFormat;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;


public class TestFormat {

	public static void main(String[] args) {
		
		DateFormat formatter1;
		formatter1 = new SimpleDateFormat("yyyy-MM-dd");
		try {
			Date date = (Date)formatter1.parse("2013-12-03");
			System.out.println(date);
			System.out.println(date.getTime());
			System.out.println(new Timestamp(date.getTime()));
		} catch (ParseException e) {
			e.printStackTrace();
		}
		
		byte[] buf = {0x11, 0x22};
		String raw = new String(buf);
		System.out.println(raw);
		buf = raw.getBytes();
		System.out.println(String.format("%02x%02x", buf[0], buf[1]));
		
		Date date = new Date();
		System.out.println(date);
		System.out.println(new SimpleDateFormat("yyyy/MM/dd").format(new Date()));
		
		System.out.println(new Timestamp(System.currentTimeMillis() - 60 * 60 * 24 * 1000));
		String dateTime = new SimpleDateFormat("yyMMddHHmmss").format(new Date());
		System.out.println(dateTime);
		System.out.println(String.format("%02d", null));

		byte[] stepByte = {(byte) 0x11, 0x01, 0x10};
		 byte stepMask = (byte)0x80;
		 
		 boolean isToday = ((stepByte[0] & stepMask) == stepMask);
		System.out.println(isToday);
		 if(isToday) stepByte[0] ^= stepMask;
		 System.out.println(stepByte[0] + " " + stepByte[1] + " " + stepByte[2]);
		 System.out.println(0x80<<16);
		 System.out.println(stepByte[0]<<16);
		 System.out.println(stepByte[1]<<8);
		 System.out.println(stepByte[2]);
		 int step = (stepByte[0] << 16) + (stepByte[1] << 8) + stepByte[2];
		 System.out.println(step);
		 
		
	}

}
