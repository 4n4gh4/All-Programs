package lab3;

import java.util.*;

class student extends person{
	String major;
	
	student(String name,int id,String major){
		super(name,id);
		this.major=major;
		
	}
	
	void display() {
		super.display();
		System.out.print(" " + major);
	}
	
}

class faculty extends person{
	String dept;
	
	faculty(String name,int id,String dept){
		super(name,id);
		this.dept=dept;
		
	}
	
	void display() {
		super.display();
		System.out.print(" "+dept);
	}
	
}

public class person {
	
	static String qpcode;
	
	String name;
	int id;
	
	person(String name,int id){
		this.name=name;
		this.id=id;
				
	}
	
	void display() {
		System.out.print(name+" "+id);
	}
	

public static void main(String args[]) {
	Scanner sc=new Scanner(System.in);
	
	String role=sc.nextLine();
	String name=sc.nextLine();
	int id=sc.nextInt();
	sc.nextLine(); // Consume the leftover newline

	
	if (role.equalsIgnoreCase("student")) {
		String major=sc.nextLine();
		student s1= new student(name,id,major);
		s1.display();
	}
	
	else {
		String dept = sc.nextLine();
		student s2= new student(name,id,dept);
		s2.display();

	}
	
}

}
