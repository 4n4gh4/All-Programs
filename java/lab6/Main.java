package lab6;

import java.util.*;

public class Main {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt();
		
		Square s = new Square(n);
		Circle c = new Circle(n);
		
		s.calc(n);
		c.calc(n);
	}
}
