package lab1;

import java.util.*;

public class string_space {

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the word: ");
        String word = sc.next();

        for (int i = 0; i < word.length(); i++) {
            if (i <= word.length() / 2) {
            	if(i==word.length()/2) {
    				System.out.println(word.charAt(i));
    			}
            	
            	else
            		System.out.println(word.charAt(i) + " " + word.charAt(word.length() - i - 1));
            } else {
                // For characters after the middle index (repeat output)
                System.out.println(word.charAt(word.length() - i - 1) + " " + word.charAt(i));
            }
        }
    }
}

