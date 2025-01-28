package lab5;

import java.util.Scanner;
public class Main6 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        String managerName = scanner.nextLine();
        double managerBasicSalary = scanner.nextDouble();
        double managerBonus = scanner.nextDouble();
        scanner.nextLine();  // Consume the newline character

        String engineerName = scanner.nextLine();
        double engineerBasicSalary = scanner.nextDouble();
        double engineerOvertimePay = scanner.nextDouble();

        Manager manager = new Manager(managerBasicSalary, managerBonus);
        Engineer engineer = new Engineer(engineerBasicSalary, engineerOvertimePay);

        System.out.printf("Manager Salary: %.2f\n", manager.calculateSalary());
        System.out.printf("Engineer Salary: %.2f\n", engineer.calculateSalary());
    }
}

