package lab4;

import java.util.*;

class Staff extends Person {
 private int staffId;

 // Constructor
 public Staff(String name, int staffId) {
     super(name); // Call Person constructor
     this.staffId = staffId;
 }

 // Getter and Setter
 public int getStaffId() {
     return staffId;
 }

 public void setStaffId(int staffId) {
     this.staffId = staffId;
 }

 // Method to display staff ID
 public void displayStaffDetails() {
     displayPersonDetails(); // Display name from Person
     System.out.println("Staff ID: " + staffId);
 }
}

