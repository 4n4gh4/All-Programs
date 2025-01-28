package lab4;

import java.util.*;

public class Test {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);

        System.out.println("Enter Number of Gears, Speed of Bicycle, and Seat Height:");
        int gears = scanner.nextInt();
        int speed = scanner.nextInt();
        int seatHeight = scanner.nextInt();

        // Creating MontaneBike object
        MontaneBike bike = new MontaneBike(gears, speed, seatHeight);

        // Display the details using toString()
        System.out.println("\nBicycle Details:");
        System.out.println(bike);

        scanner.close();
    }
}
