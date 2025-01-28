package lab2;

import java.util.*;

public class Time{
	private int hour;
	private int minute;
	private int second;
	
	public Time(int x, int y, int z) {
		this.hour = x;
		this.minute=y;
		this.second=z;
		
	}
	
	public Time add(Time o1, Time o2){
		int s = o1.second+o2.second;
		int h=o1.hour+o2.hour;
		int m=o1.minute+o2.minute;
		
		if(s/60 > 0) {
			m=m+(s/60);
			s=s%60;
		}
		
		if(m/60>0) {
			h=h+(m/60);
			m=m%60;
		}
		
		if(h%12!=0) {
			h=h%12;
		}
	
		Time o3 = new Time(h,m,s);
		return o3;
	}
	
	 public void display() {
		 System.out.println("Time: " + hour + " : " + minute + " : " + second);
	 }
	 
	 public static void main(String args[]) {
		 
		 Scanner sc = new Scanner(System.in);
		 
		System.out.println("For the 1st time: ");
		 
			System.out.println("Enter hour of T1: ");
			int hh = sc.nextInt();
			System.out.println("Enter minute of T1: ");
			int mm = sc.nextInt();
			System.out.println("Enter second of T1: ");
			int ss = sc.nextInt();
			
			Time o1 = new Time(hh,mm,ss);
			
			System.out.println("For the 2nd time: ");
			
			System.out.println("Enter hour of T1: ");
			hh = sc.nextInt();
			System.out.println("Enter minute of T1: ");
			mm = sc.nextInt();
			System.out.println("Enter second of T1: ");
			ss = sc.nextInt();
			
			Time o2 = new Time(hh,mm,ss);
			
			o1.display();
			o2.display();
			Time o3=o1.add(o1, o2);
			o3.display();
				
	 } 
}
