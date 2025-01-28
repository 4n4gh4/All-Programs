package lab6;

import java.util.*;

public class Main2 implements Matrix{
	
	int arr[][];
	
	public void diagonalsMinMax(int arr[][],int n) {
		//1st diagonal
		int a1[]=new int[n],k=0,i,j;
		
		i=0;
		j=0;
		
		while(i<n&&j<n) {
			a1[k]=arr[i][j];
			i++;
			j++;
			k++;
		}
		
		int max = a1[0];
		int min = a1[0];
		
		for(i=0;i<n;i++) {
			if(a1[i]>max) {
				max=a1[i];
			}
			
			if(a1[i]<min) {
				min=a1[i];
			}
		}
		
		
		System.out.println("Smallest element - 1: "+min);
		System.out.println("Largest element - 1: "+max);
		
		
		//2nd diagonal
		
		int a2[]=new int[n];
		i=0;
		j=n-1;
		k=0;
		
		while(i<n&&j>=0) {
			a2[k]=arr[i][j];
			i++;
			j--;
			k++;
		}
		
		max = a2[0];
		min = a2[0];
		
		for(i=0;i<n;i++) {
			if(a2[i]>max) {
				max=a2[i];
			}
			
			if(a2[i]<min) {
				min=a2[i];
			}
		}
		
		System.out.println("Smallest element - 2: "+min);
		System.out.println("Largest element - 2: "+max);
		
	}
	
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt();
		int arr[][] = new int[n][n];
		
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				arr[i][j] = sc.nextInt();
			}
		}
		
		Main2 m = new Main2();
		
		m.diagonalsMinMax(arr, n);
	}
}
