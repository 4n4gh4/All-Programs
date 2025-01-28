package lab1;
import java.util.*;

public class punctuality {
	
	public static void main(String args[]) {
		System.out.println("Enter the initial salary on Monday: ");
		Scanner sc = new Scanner(System.in);
		int x = sc.nextInt();
		int y=x;
		System.out.println("Enter total days of punctuality: ");
		int n = sc.nextInt();
		for(int i=0;i<n-1;i++) {
			x=x+200;
			y=y+x;
		}
		
		System.out.println("Total incentive: " + y);	
	}		
}
