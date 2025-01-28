package lab4;

import java.util.Scanner;

class Employee {
    private int empId;
    private float salary;

    public Employee(int empId, float salary) {
        this.empId = empId;
        this.salary = salary;
    }

    public int getEmpId() {
        return empId;
    }

    public float getSalary() {
        return salary;
    }
}
