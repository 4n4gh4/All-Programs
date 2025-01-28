package lab2;

import java.util.*;

public class prof {
	
	private int id;
	private String dept;
	private String name;
	private int age;
	private int salary;
	
	public prof(int i, String d, String n, int a, int s){
		this.id=i;
		this.dept=d;
		this.name=n;
		this.salary=s;
		this.age=a;
		
	}
	
	public void display() {
		System.out.println("ID: " + id);
		System.out.println("Name: " + name);
		System.out.println("Department: " + dept);
		System.out.println("Age: " + age);
		System.out.println("Salary: " + salary);
		
	}
	
	public static void main(String args[]) {
		
		Scanner sc = new Scanner(System.in);
		
		System.out.println("Enter number of entries: ");
		int n = sc.nextInt();
		
		prof[] professor = new prof[n];
		
		for(int i=0;i<n;i++) {
			
			System.out.println("For professor " + i + "-> ");
	
			System.out.println("Enter ID: ");
			int id_ = sc.nextInt();
			System.out.println("Enter name: ");
			String na = sc.next();
			System.out.println("Enter department: ");
			String d = sc.next();
			System.out.println("Enter age: ");
			int a = sc.nextInt();
			System.out.println("Enter salary: ");
			int s = sc.nextInt();
			
			professor[i] = new prof(id_,d,na,a,s);
			
		}
		
		int high = professor[0].salary;
		int x = 0;
		
		for(int i=0;i<n;i++) {
			if(professor[i].salary > high) {
				high=professor[i].salary;
				x=i;
			}
		}
		
		professor[x].display();
		
	}
}
