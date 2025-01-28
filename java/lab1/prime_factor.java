package lab1;
import java.util.*;

public class prime_factor {
	
	public static Boolean isPrime(int num){



	        for(int i=2;i<=Math.sqrt(num);i++){
	            if(num%i==0){
	                return false;
	            }
	        }

	        return true;
	    }


	
	public static void Factors(int num) {		
		
		for(int i=2;i<=num;i++) {
			
			if (isPrime(i)==true) {
				while(num%i==0) {
					System.out.print(i+ " ");
					num=num/i;
				}
			}
		}
	}
		
	public static void main (String srgs[]) {
		
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the number: ");
		
		int num = sc.nextInt();
		
		Factors(num);
	}
}
