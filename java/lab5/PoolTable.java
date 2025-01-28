package lab5;

import java.util.Scanner;

class PoolTable {
    double length, width, pocketSize;

    public PoolTable(double length, double width, double pocketSize) {
        this.length = length;
        this.width = width;
        this.pocketSize = pocketSize;
    }

    public double calculatePerimeter() {
        return 2 * (length + width);
    }

    public double calculatePocketPerimeter() {
        return Math.PI * pocketSize;
    }
}
