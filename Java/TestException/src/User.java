import java.lang.reflect.Field;


public class User {
	private String name;
	private int weight;
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public int getWeight() {
		return weight;
	}
	public void setWeight(int weight) {
		this.weight = weight;
	}
	
	public String toString(){
		Field[] fields = this.getClass().getDeclaredFields();
		StringBuilder sb = new StringBuilder();
		for(Field field : fields){
			sb.append(field.getName());
			sb.append(":");
			try{ sb.append(field.get(this)); } catch(Exception ex) { }
			sb.append(" ");
		}
		return sb.toString();
	}

	public static void main(String args[]){
		User user = new User();
		user.setName("Edward");
		user.setWeight(10);
		
		System.out.println(user);
	}
}
