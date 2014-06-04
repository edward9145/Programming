
public class ClassLoaderTest {
	
	
	public static void main(String[] args){
		try{
			System.out.println(ClassLoader.getSystemClassLoader());
			System.out.println(ClassLoader.getSystemClassLoader().getParent());
			System.out.println(ClassLoader.getSystemClassLoader().getParent().getParent());
		}
		catch(Exception ex){
			ex.printStackTrace();
		}
	}

}
