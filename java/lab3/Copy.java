package lab3;

import java.util.*;

public class Copy {
	String name;
	int id;
	
	Copy(String s,int i){
		this.name=s;
		this.id=i;
	}
	
	Copy(Copy other){
		this.name=other.name;
		this.id=other.id;
	}
	
	void display() {
		System.out.println(id + " " + name);
	}
	
	public static void main(String args[]) {
		Scanner sc=new Scanner(System.in);
		
		int t1=sc.nextInt();
		sc.nextLine();
		String t2=sc.nextLine();
		
		Copy o1 = new Copy(t2,t1);
		Copy o2 = new Copy(t2,t1);
		
		o1.display();
		o2.display();
		
	}
	
}
