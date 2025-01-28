package lab1;
import java.util.*;

public class lucky_pairs {
	
	public static int game(int A, int B, int N) {
		
		int j=1, C=A, D=B;
		for(int i=0;i<N;i++) {
			
			if(j==1) {
				C=C*2;
				j=0;
			}
			
			else {
				D=D*2;
				j=1;
			}	
			
		}
		
		return C+D;
		
	}
	
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter the number A: ");
		
		int A = sc.nextInt();
		
		System.out.print("Enter the number B: ");
		
		int B = sc.nextInt();
		
		System.out.print("Enter the number of turns: ");
		
		int N = sc.nextInt();
		
		System.out.print("The result is: " + game(A,B,N));

		
	}
}
