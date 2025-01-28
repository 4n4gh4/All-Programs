package lab3;

import java.util.*;

public class Main3 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String placeTemp = sc.nextLine();
        String[] split1 = placeTemp.split(" ");
        if (split1.length < 2) {
            System.out.println("Invalid input format for place and temperature.");
            return;
        }
        String name1 = split1[0];
        int temp1 = Integer.parseInt(split1[1]);

        String placeDayTemp = sc.nextLine();
        String[] split2 = placeDayTemp.split(" ");
        if (split2.length < 3) {
            System.out.println("Invalid input format for place, day, and temperature.");
            return;
        }
        String name2 = split2[0];
        String day2 = split2[1];
        int temp2 = Integer.parseInt(split2[2]);

        Overloading obj1 = new Overloading();
        Overloading obj2 = new Overloading(name1, temp1);
        Overloading obj3 = new Overloading(name2, day2, temp2);

        System.out.println("Using Default Constructor: ");
        obj1.display();

        System.out.println("Using Parameterized Constructor1: ");
        obj2.display();

        System.out.println("Using Parameterized Constructor2: ");
        obj3.display();
    }
}
