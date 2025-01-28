package lab4;

import java.util.*;

//Main class
public class Main {
public static void main(String[] args) {
 Scanner scanner = new Scanner(System.in);

 // Prompt user for input
 System.out.println("Enter the car type:");
 String type = scanner.nextLine();
 System.out.println("Enter the car brand:");
 String brand = scanner.nextLine();

 // Create an object of Car
 Car car = new Car(type, brand);

 // Display the type and brand
 car.displayType();
 car.displayBrand();

 scanner.close();
}
}
