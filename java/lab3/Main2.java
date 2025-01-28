package lab3;

import java.util.Scanner;

public class Main2 {

	    public static void main(String[] args) {
	        Scanner sc = new Scanner(System.in);

	        System.out.println("Name of StallCategory: ");
	        String name = sc.nextLine();

	        System.out.println("Detail of StallCategory:");
	        String detail = sc.nextLine();

	        StallCategory defaultConstructorObject = new StallCategory();
	        
	        System.out.println("Using Default Constructor");
	        defaultConstructorObject.display();

	        StallCategory parameterizedConstructorObject = new StallCategory(name, detail);

	        System.out.println("Using Parameterized Constructor");
	        parameterizedConstructorObject.display();
	    }
	}

