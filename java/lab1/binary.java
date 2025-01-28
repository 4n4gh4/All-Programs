package lab1;
import java.util.*;

public class binary {
	
	public static void numbers(String out) {
		int flag=0, max=0;
		for(int i=0;i<out.length();i++) {
			if (out.charAt(i)=='0'){
				flag=flag+1;
			}
			
			if (out.charAt(i)=='1') {
				if(flag>max) {
					max=flag;
				}
				
				flag=0;
			}
		}
		
		if(flag>max) {
			max=flag;
		}
		
		System.out.println("Longest series of 0's is: "+ max);
	}
	
	public static String bin(int num) {
		String out="";
		while(num!=1) {
			
			if(num==0) {
				return "0";
			}
			
			if(num%2==0) {
				out="0" + out;
			}
			
			else
				out="1"+out;
			num=num/2;
		}
		
		return "1"+out;
	}

	public static void main(String args[]) {
		System.out.println("Enter the number: ");
		Scanner sc = new Scanner(System.in);
		
		int num = sc.nextInt();
		
		System.out.println(bin(num));
		numbers(bin(num));
	}
}
