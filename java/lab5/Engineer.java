package lab5;

import java.util.Scanner;

class Engineer extends Employee {
    double overtimePay;

    public Engineer(double basicSalary, double overtimePay) {
        super(basicSalary);
        this.overtimePay = overtimePay;
    }

    @Override
    public double calculateSalary() {
        return basicSalary + overtimePay;
    }
}
