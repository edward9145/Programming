
public class Convertion {

	public static void main(String[] args) {
		String byteStr = "14 04 19 AA 0D 0C 0A AA 16 00 00 16 00 00 16 00 00 16 00 00 16 00 00 16 00 00 17 00 00 17 00 00 17 00 00 17 00 00 17 00 00 17 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 01 00 00 01 00 00 01 00 00 01 00 00 01 00 00 01 00 00 02 00 00 02 00 00 02 00 00 02 00 00 02 00 00 02 00 00 03 00 00 03 00 00 03 00 00 03 00 00 03 00 00 03 00 00 04 00 00 04 00 00 04 00 00 04 00 00 04 00 00 04 00 00 05 00 00 05 00 00 05 00 00 05 00 00 05 00 00 05 00 00 06 00 00 06 00 00 06 00 00 06 00 00 06 00 00 06 00 00 AA AA 00 00 45 AA AA";
		byte[] raw = ByteAndStr16.HexString2Bytes(byteStr);
		System.out.println(ByteAndStr16.Bytes2HexString(raw));
	}

	public static byte[] HexString2Bytes(String hexstr) {
		hexstr = hexstr.replace(" ", "");
		byte[] b = new byte[hexstr.length() / 2];
		int j = 0;
		for (int i = 0; i < b.length; i++) {
			char c0 = hexstr.charAt(j++);
			char c1 = hexstr.charAt(j++);
			b[i] = (byte) ((parse(c0) << 4) | parse(c1));
		}
		return b;
	}
	
	private static int parse(char c) {
		if (c >= 'a')
			return (c - 'a' + 10) & 0x0f;
		if (c >= 'A')
			return (c - 'A' + 10) & 0x0f;
		return (c - '0') & 0x0f;
	}
}
