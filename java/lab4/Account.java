package lab4;

import java.util.*;

class Account {
    private int account_number;
    private int account_balance;

    // Constructor to initialize account details
    public Account(int account_number, int account_balance) {
        this.account_number = account_number;
        this.account_balance = account_balance;
    }

    // Getter methods to access private fields
    public int getAccountNumber() {
        return account_number;
    }

    public int getAccountBalance() {
        return account_balance;
    }
}

