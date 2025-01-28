package lab1;
import java.util.*;
//making our input output functions to manipulate easily
import java.io.*;

public class prime_Range {
	
	public static Boolean isPrime(int num){

	    if(num<=1){
	        return false;
	    }

	    else{

	        for(int i=2;i<=Math.sqrt(num);i++){
	            if(num%i==0){
	                return false;
	            }
	        }

	        return true;
	    }


	}


	public static void main(String args[])
	{

	Scanner sc = new Scanner(System.in);
	
	System.out.print("Enter the 1st number: ");
	
	int num1 = sc.nextInt();
	System.out.print("Enter the 2nd number: ");
	int num2 = sc.nextInt();
	
	for(int j=num1;j<=num2;j++) {
		
		if (isPrime(j)==true) {
			System.out.println(j);
		}
		
	}


}
	
}
