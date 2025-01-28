package lab3;

import java.util.*;

class ItemTypeBO {
    public void searchDetail(String search, ItemType[] items, int n) {
        for (int i = 0; i < n; i++) {
            if (items[i].getName().equalsIgnoreCase(search)) {
                items[i].display();
                return;
            }
        }
        System.out.println("Item not found");
    }

    public void display(ItemType[] items, int n) {
        for (int i = 0; i < n; i++) {
            items[i].display();
        }
    }
}
