package lab3;

import java.util.*;

class Overloading {
    private String name;
    private String day;
    private int temp;

    public Overloading() {
        this.name = "Argentina";
        this.day = "idk";
        this.temp = 29;
    }

    public Overloading(String name, int temp) {
        this.name = name;
        this.day = "no idea";
        this.temp = temp;
    }

    public Overloading(String name, String day, int temp) {
        this.name = name;
        this.day = day;
        this.temp = temp;
    }

    public void display() {
        System.out.println(name + " " + day + " Temperature: " + temp + "°");
    }
}