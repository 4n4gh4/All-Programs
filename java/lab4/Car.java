package lab4;

import java.util.Scanner;

//Subclass Car extending Vehicle
class Car extends Vehicle {
private String brand;

// Constructor to initialize type and brand
public Car(String type, String brand) {
   super(type); // Initialize type in the base class
   this.brand = brand;
}

// Method to display brand
public void displayBrand() {
   System.out.println("Brand: " + brand);
}
}

