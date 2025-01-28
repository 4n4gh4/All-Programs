package lab4;

import java.util.*;

	class Bicycle {
	    private int gears;
	    private int speed;

	    // Constructor to initialize Bicycle attributes
	    public Bicycle(int gears, int speed) {
	        this.gears = gears;
	        this.speed = speed;
	    }

	    // Getter methods
	    public int getGears() {
	        return gears;
	    }

	    public int getSpeed() {
	        return speed;
	    }

	    // Overriding the toString() method
	    @Override
	    public String toString() {
	        return "Number of Gears: " + gears + "\nSpeed: " + speed;
	    }
	}
