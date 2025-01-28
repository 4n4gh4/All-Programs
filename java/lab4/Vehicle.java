package lab4;

import java.util.Scanner;

//Base class Vehicle
class Vehicle {
 protected String type;

 // Constructor to initialize type
 public Vehicle(String type) {
     this.type = type;
 }

 // Method to display type
 public void displayType() {
     System.out.println("Type: " + type);
 }
}