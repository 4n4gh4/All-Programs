package lab4;

import java.util.*;

class TemporaryStaff extends Staff {
 private int days;
 private int hoursWorked;

 // Constructor
 public TemporaryStaff(String name, int staffId, int days, int hoursWorked) {
     super(name, staffId);
     this.days = days;
     this.hoursWorked = hoursWorked;
 }

 // Getter and Setter
 public int getDays() {
     return days;
 }

 public void setDays(int days) {
     this.days = days;
 }

 public int getHoursWorked() {
     return hoursWorked;
 }

 public void setHoursWorked(int hoursWorked) {
     this.hoursWorked = hoursWorked;
 }

 // Method to calculate salary
 public double calculateSalary() {
     return days * hoursWorked * 10.0; // Example: $10 per hour
 }

 // Method to display details
 public void displayTemporaryStaffDetails() {
     displayStaffDetails(); // Display name and staff ID
     System.out.println("Days Worked: " + days);
     System.out.println("Hours Worked: " + hoursWorked);
     System.out.println("Salary: $" + calculateSalary());
 }
}
