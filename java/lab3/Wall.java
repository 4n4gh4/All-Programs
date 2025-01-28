package lab3;

import java.util.*;

public class Wall {
	double length;
	double height;
	
	Wall(double l, double h){
		this.length=l;
		this.height=h;
	}
	
	double calculateArea() {
		return length*height;
	}
	
	public static void main(String args[]) {
		Scanner sc=new Scanner(System.in);
		
		double l = sc.nextDouble();
		double h = sc.nextDouble();
		sc.nextLine();
		
		Wall w1 = new Wall(l,h);
		
		l = sc.nextDouble();
		h = sc.nextDouble();
		sc.nextLine();
		
		Wall w2 = new Wall(l,h);
		
		System.out.println("Area of wall 1: "+w1.calculateArea());
		System.out.println("Area of wall 2: "+w2.calculateArea());

		
		
	}
	
}
