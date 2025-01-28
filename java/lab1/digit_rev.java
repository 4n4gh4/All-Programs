package lab1;
import java.util.*;

public class digit_rev {
	
	public static void rev(int num) {
		while(num!=0) {
			System.out.print(num%10);
			num = num/10;
		}	
	}
	
	public static void main(String args[]) {
		System.out.println("Enter the number: ");
		Scanner sc = new Scanner(System.in);		
		int num = sc.nextInt();		
		rev(num);
	}
}
