package lab5;

import java.util.*;

public class Area extends Shape{
	
	@Override
	void rectangleArea(double l, double b) {
		System.out.println("The area of rectangle is: "+ l*b);
	}
	
	@Override
	void squareArea(double s) {
		System.out.println("The area of square is: "+ s*s);
	}
	
	@Override
	void circleArea(double r) {
		System.out.println("The area of circle is: "+ r*r*3.14);
	}
	
}
