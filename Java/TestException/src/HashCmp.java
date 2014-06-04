import java.util.HashSet;
import java.util.Set;


public class HashCmp {
	
	
	public static void main(String[] args) {
		Obj a = new Obj(1);
		Obj b = new Obj(1);
		System.out.println(a);
		System.out.println(b);
		System.out.println(a==b);
		System.out.println(a.equals(b));
		Set<Obj> set = new HashSet<Obj>();
		set.add(a);
//		set.add(b);
		for(Obj o : set){
			System.out.println(o);
		}
		System.out.println(set.contains(b));
		
		String A = "A";
		String A_ = new String("A");
		System.out.println(A.hashCode() + " " + A_.hashCode());
		System.out.println(A==A_);
	}

}

class Obj{
	int prop;
	public Obj(int p){
		this.prop = p;
	}
	@Override
	public boolean equals(Object obj){
		Obj o = (Obj)obj;
		if(this.prop == o.prop)
			return true;
		return false;
	}
	@Override
	public int hashCode(){
		return prop*10;
	}
}