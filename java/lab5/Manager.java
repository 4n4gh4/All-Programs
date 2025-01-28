package lab5;

import java.util.Scanner;

class Manager extends Employee {
    double bonus;

    public Manager(double basicSalary, double bonus) {
        super(basicSalary);
        this.bonus = bonus;
    }

    @Override
    public double calculateSalary() {
        return basicSalary + bonus;
    }
}

