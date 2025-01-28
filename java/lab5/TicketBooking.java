package lab5;

import java.util.*;

class TicketBooking {
    private String stageEvent;
    private String customer;
    private int noOfSeats;

    public TicketBooking() {}

    public TicketBooking(String stageEvent, String customer, int noOfSeats) {
        this.stageEvent = stageEvent;
        this.customer = customer;
        this.noOfSeats = noOfSeats;
    }

    public String getStageEvent() {
        return stageEvent;
    }

    public void setStageEvent(String stageEvent) {
        this.stageEvent = stageEvent;
    }

    public String getCustomer() {
        return customer;
    }

    public void setCustomer(String customer) {
        this.customer = customer;
    }

    public int getNoOfSeats() {
        return noOfSeats;
    }

    public void setNoOfSeats(int noOfSeats) {
        this.noOfSeats = noOfSeats;
    }

    public void makePayment(double amount) {
        System.out.printf("Amount %.1f paid in cash\n", amount);
    }

    public void makePayment(double amount, String walletNumber) {
        System.out.printf("Amount %.1f paid using wallet number %s\n", amount, walletNumber);
    }

    public void makePayment(String cardHolderName, double amount, String cardType, String ccv) {
        System.out.printf("Holder name:%s\n", cardHolderName);
        System.out.printf("Amount %.1f paid using %s card\n", amount, cardType);
        System.out.printf("CCV:%s\n", ccv);
    }
}
