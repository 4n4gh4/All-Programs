package lab4;

import java.util.*;

public class AccountManagement {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the number of users: ");
        int n = scanner.nextInt();

        User[] users = new User[n];

        for (int i = 0; i < n; i++) {
            System.out.println("Enter details for user " + (i + 1) + ":");
            System.out.print("Username: ");
            String username = scanner.next();
            System.out.print("Account Number: ");
            int account_number = scanner.nextInt();
            System.out.print("Initial Deposit: ");
            int account_balance = scanner.nextInt();

            users[i] = new User(username, account_number, account_balance);
        }

        System.out.print("Enter the account number to check balance: ");
        int search_account = scanner.nextInt();

        boolean accountFound = false;
        for (User user : users) {
            if (user.getAccountNumber() == search_account) {
                System.out.println("Account Balance: " + user.getAccountBalance());
                accountFound = true;
                break;
            }
        }
        if (!accountFound) {
            System.out.println("Account Number Does Not Exist.");
        }

        scanner.close();
    }
}

