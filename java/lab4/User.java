package lab4;

import java.util.*;

class User extends Account {
    private String username;

    // Constructor to initialize user details
    public User(String username, int account_number, int account_balance) {
        super(account_number, account_balance);
        this.username = username;
    }

    public String getUsername() {
        return username;
    }
}
