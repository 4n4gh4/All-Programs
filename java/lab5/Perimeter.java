package lab5;

import java.util.*;

public class Perimeter extends Maths{
		
	@Override
	void rectanglePerimeter(double l,double b) {
		System.out.println("Perimeter of rectangle: " + 2*(l+b));
	}
	
	@Override
	void squarePerimeter(double s) {
		System.out.println("Perimeter of square: " + 4*s);

	}
	
	@Override
	void trianglePerimeter(double s1,double s2, double s3) {
		System.out.println("Perimeter of triangle: " + (s1+s2+s3));

	}
	
	@Override
	void trapezoidPerimeter(double s1,double s2, double s3,double s4) {
		System.out.println("Perimeter of trapezoid: " + (s1+s2+s3+s4));

	}
	
	@Override
	void circlePerimeter(double r) {
		System.out.println("Perimeter of circle: " + 2*3.14*r);

	}
	
	public void calculateSum(double l,double b,double s,double s1,double s2, double s3,double p1,double p2, double p3,double p4,double r) {
		double sum = 2*(l+b);
		sum  = sum + 4*s;
		sum = sum + s1+s2+s3;
		sum  = sum + p1+p2+p3+p4;
		sum  = sum + 2*3.14*r;
		
		System.out.println("Sum of Perimeters: " + sum);
	}

	void sortPerimeter(double l, double b, double s, double s1, double s2, double s3, double p1, double p2, double p3, double p4, double r) {
	    double rect = 2 * (l + b);
	    double square = 4 * s;
	    double tri = s1 + s2 + s3;
	    double trap = p1 + p2 + p3 + p4;
	    double circ = 2 * 3.14 * r;

	    double[] perimeters = {rect, square, tri, trap, circ};

	    int n = perimeters.length;
	    for (int i = 0; i < n - 1; i++) {
	        for (int j = 0; j < n - i - 1; j++) {
	            if (perimeters[j] > perimeters[j + 1]) {
	                double temp = perimeters[j];
	                perimeters[j] = perimeters[j + 1];
	                perimeters[j + 1] = temp;
	            }
	        }
	    }

	    System.out.println("Sorted perimeters in ascending order:");
	    for (int i = 0; i < n; i++) {
	        System.out.print(perimeters[i] + "  ");
	    }
	}
	
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		
		System.out.println("Enter length and breadth of rectangle: ");
		double l = sc.nextDouble();
		double b = sc.nextDouble();
		
		System.out.println("Enter side length of square: ");
		double s = sc.nextDouble();
		
		System.out.println("Enter sides of triangle: ");
		double s1 = sc.nextDouble();
		double s2 = sc.nextDouble();
		double s3 = sc.nextDouble();
		
		System.out.println("Enter sides of trapezoid: ");
		double p1 = sc.nextDouble();
		double p2 = sc.nextDouble();
		double p3 = sc.nextDouble();
		double p4 = sc.nextDouble();

		System.out.println("Enter radius of circle: ");
		double r = sc.nextDouble();
		
		Perimeter p = new Perimeter();
		
		p.rectanglePerimeter(l, b);
		p.squarePerimeter(s);
		p.trianglePerimeter(s1, s2, s3);
		p.trapezoidPerimeter(p1, p2, p3, p4);
		p.circlePerimeter(r);
		p.calculateSum(l, b, s, s1, s2, s3, p1, p2, p3, p4, r);
		p.sortPerimeter(l, b, s, s1, s2, s3, p1, p2, p3, p4, r);
	}
}
