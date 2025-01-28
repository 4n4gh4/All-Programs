package lab5;

import java.util.Scanner;

public class Main5 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        double length = sc.nextDouble();
        double width = sc.nextDouble();
        double pocketSize = sc.nextDouble();

        PoolTable poolTable = new PoolTable(length, width, pocketSize);

        System.out.printf("%.1f\n", poolTable.calculatePerimeter());
        System.out.printf("%.1f\n", poolTable.calculatePocketPerimeter());
    }
}

