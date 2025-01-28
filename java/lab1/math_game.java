package lab1;
import java.util.*;

public class math_game {
	
	public static double fact(double x) {
		if(x==1) {
			return 1;
		}
		
		else {
			return x*fact(x-1);
		}
	}
	
	public static double series(int num) {
		double sum=0, i;
		
		for(i=1;i<=num;i++) {
			sum = sum+i/fact(i);
		}
		
		return sum;
	}
	public static void main(String args[]) {
		System.out.println("Enter the number: ");
		
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		
		System.out.println(series(n));
	}
}
