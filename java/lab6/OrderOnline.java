package lab6;

import java.util.*;

public class OrderOnline {
	
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		
		int N = sc.nextInt();
		int i,j;
		String c_name,name[];
		int c_id,count;
		double cost[];
		
		
		Customer[] obj = new Customer[N];
		
		for(i=0;i<N;i++) {
			c_id = sc.nextInt();
			c_name = sc.next();
			
			count = sc.nextInt();
			
			name = new String[count];
			cost = new double[count];
			for(j=0;j<count;j++) {
				name[j] = sc.next();
				cost[j]=sc.nextDouble();
				
			}
			
			obj[i] = new Customer(c_name,c_id,count,name,cost);
		}
		
		for(i=0;i<N;i++) {
			obj[i].showdetails();
		}
	}

}
