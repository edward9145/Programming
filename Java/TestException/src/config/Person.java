package config;

import java.util.Date;

public class Person {
	
	String name;
	int age;
	Date birth;
	public Person(String string, int i, Date date) {
		this.name = string;
		this.age = i;
		this.birth = date;
	}
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public int getAge() {
		return age;
	}
	public void setAge(int age) {
		this.age = age;
	}
	public Date getBirth() {
		return birth;
	}
	public void setBirth(Date birth) {
		this.birth = birth;
	}
	
	

}
