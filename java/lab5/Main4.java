package lab5;

import java.util.*;

public class Main4 {

    public void fun1(int a, int b) {
        System.out.println(a + b);
    }

    public void fun1(int a, int b, int c) {
        System.out.println(a * b * c);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        String input = scanner.nextLine();
        String[] parts = input.split(" ");
        int n = Integer.parseInt(parts[0]);

        if (n == 2) {
            int a = Integer.parseInt(parts[1]);
            int b = Integer.parseInt(parts[2]);
            Main4 main = new Main4();
            main.fun1(a, b);
        } else if (n == 3) {
            int a = Integer.parseInt(parts[1]);
            int b = Integer.parseInt(parts[2]);
            int c = Integer.parseInt(parts[3]);
            Main4 main = new Main4();
            main.fun1(a, b, c);
        } else {
            System.out.println("WRONG INPUT");
        }

        scanner.close();
    }
}
