package lab3;

import java.util.*;

class StallCategory {
    public String name;
    public String detail;

    public StallCategory() {    }

    public StallCategory(String name, String detail) {
        this.name = name;
        this.detail = detail;
    }

    public StallCategory(StallCategory o) {
        this.name = o.name;
        this.detail = o.detail;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getDetail() {
        return detail;
    }

    public void setDetail(String detail) {
        this.detail = detail;
    }

    public void display() {
        System.out.println(name);
        System.out.println(detail);
    }
}

