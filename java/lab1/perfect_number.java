package lab1;
import java.util.*;

public class perfect_number {
	
	public static boolean Perfect(int num) {
		int j, sum=0;
		for(int i=2;i<=Math.sqrt(num);i++) {
			if(num%i==0) {
				j=num/i;
				sum = sum + i+j;
			}
		}
		
		if(sum+1==num) {
			return true;
		}
		
		else 
			return false;
	}
	
	public static void main(String args[]) {
		
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the number: ");
		
		int num = sc.nextInt();
		
		if (Perfect(num)==true){
			System.out.print("Perfect number");
		}
		
		else
			System.out.print("Not a perfect number");
	}

}
