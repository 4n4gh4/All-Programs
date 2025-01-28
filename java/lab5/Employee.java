package lab5;

import java.util.Scanner;

class Employee {
    double basicSalary;

    public Employee(double basicSalary) {
        this.basicSalary = basicSalary;
    }

    public double calculateSalary() {
        return basicSalary;
    }
}
