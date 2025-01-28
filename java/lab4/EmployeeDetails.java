package lab4;

import java.util.*;

public class EmployeeDetails {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter employee ID and salary separated by space: ");
        try {
            int empId = scanner.nextInt();
            float salary = scanner.nextFloat();

            EmpLevel emp = new EmpLevel(empId, salary);
            emp.displayDetails();
        } catch (Exception e) {
            System.out.println("Invalid input. Please enter an integer for Employee ID and a float for salary.");
        } finally {
            scanner.close();
        }
    }
}
