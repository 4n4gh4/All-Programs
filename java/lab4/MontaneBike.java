package lab4;

import java.util.*;

	public class MontaneBike extends Bicycle {
	    private int seatHeight;

	    // Constructor to initialize MontaneBike attributes
	    public MontaneBike(int gears, int speed, int seatHeight) {
	        super(gears, speed);
	        this.seatHeight = seatHeight;
	    }

	    public int getSeatHeight() {
	        return seatHeight;
	    }

	    // Overriding the toString() method to include seat height
	    @Override
	    public String toString() {
	        return super.toString() + "\nSeat Height: " + seatHeight;
	    }
	}
