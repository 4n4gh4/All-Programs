package lab2;

import java.util.*;

public class Occurence {
	
	    public int count(String str, char ch) {
	        int count = 0;
	        for (int i = 0; i < str.length(); i++) {
	            if (str.charAt(i) == ch) {
	                count++;
	            }
	        }
	        return count;
	    }

	    public static void main(String[] args) {
	        Scanner sc = new Scanner(System.in);

	        System.out.print("Enter the string: ");
	        String str = sc.next();

	        System.out.print("Enter the character: ");
	        char ch = sc.next().charAt(0);

	        Occurence occurence = new Occurence();
	        int result = occurence.count(str, ch);

	        System.out.println("Number of occurrences of '" + ch + "': " + result);
	    }
	}

