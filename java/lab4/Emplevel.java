package lab4;

import java.util.*;

class EmpLevel extends Employee {
    public EmpLevel(int empId, float salary) {
        super(empId, salary);
    }

    public int getLevel() {
        if (getSalary() > 100) {
            return 1; // Top management
        } else {
            return 2; // Staff
        }
    }

    public void displayDetails() {
        System.out.println("Employee ID: " + getEmpId());
        System.out.println("Salary: " + getSalary());
        System.out.println("Level: " + getLevel());
    }
}
