package lab5;

import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		System.out.println("Enter length and breadth of rectangle: ");
		
		double l = sc.nextDouble();
		double b = sc.nextDouble();
		
		System.out.println("Enter side length of square: ");
		double s = sc.nextDouble();
		
		System.out.println("Enter radius of circle: ");
		double r = sc.nextDouble();
		
		Area a = new Area();
		
		a.rectangleArea(l,b);
		a.squareArea(s);
		a.circleArea(r);
	}
}
