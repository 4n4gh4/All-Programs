package lab4;

import java.util.*;

//Person Class
class Person {
 private String name;

 // Constructor
 public Person(String name) {
     this.name = name;
 }

 // Getter and Setter
 public String getName() {
     return name;
 }

 public void setName(String name) {
     this.name = name;
 }

 // Method to display name
 public void displayPersonDetails() {
     System.out.println("Name: " + name);
 }
}
