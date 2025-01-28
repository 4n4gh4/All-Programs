package lab4;

import java.util.*;

public class Main2 {
public static void main(String[] args) {
   java.util.Scanner scanner = new java.util.Scanner(System.in);

   // Input details for TemporaryStaff
   System.out.print("Enter Name: ");
   String name = scanner.nextLine();
   System.out.print("Enter Staff ID: ");
   int staffId = scanner.nextInt();
   System.out.print("Enter Days Worked: ");
   int days = scanner.nextInt();
   System.out.print("Enter Hours Worked Per Day: ");
   int hoursWorked = scanner.nextInt();

   // Create TemporaryStaff object
   TemporaryStaff tempStaff = new TemporaryStaff(name, staffId, days, hoursWorked);

   // Display details
   System.out.println("\nTemporary Staff Details:");
   tempStaff.displayTemporaryStaffDetails();

   scanner.close();
}
}

