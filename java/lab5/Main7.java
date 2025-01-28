package lab5;

import java.util.Scanner;

public class Main7 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Icecream icecream = new Icecream();

        if (scanner.hasNextInt()) {
            int r = scanner.nextInt();
            if (scanner.hasNextInt()) {
                int h = scanner.nextInt();
                icecream.Quantity(r, h);
            }
        }

        else {
            int r = scanner.nextInt();
            icecream.Quantity(r);
        }
    }
}

