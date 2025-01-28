package lab3;

import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        ItemType[] item = new ItemType[10];
        ItemTypeBO itemTypeBO = new ItemTypeBO();

        System.out.println("Enter the number of items:");
        int n = sc.nextInt();
        sc.nextLine();

        for (int i = 0; i < n; i++) {
            System.out.println("Enter details of item " + (i + 1) + "->");

            System.out.println("Enter item name:");
            String name = sc.nextLine();

            System.out.println("Enter deposit:");
            double deposit = sc.nextDouble();

            System.out.println("Enter cost per day:");
            double costPerDay = sc.nextDouble();
            sc.nextLine();

            item[i] = new ItemType(name, deposit, costPerDay);
        }

        System.out.println("Enter the Name of the item to be searched:");
        String search = sc.nextLine();

        itemTypeBO.searchDetail(search, item, n);

        System.out.println("All item details:");
        itemTypeBO.display(item, n);
    }
}
