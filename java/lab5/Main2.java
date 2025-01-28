package lab5;

import java.util.*;

public class Main2{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        String bookingDetails = scanner.nextLine();
        String[] details = bookingDetails.split(",");
        TicketBooking booking = new TicketBooking(details[0], details[1], Integer.parseInt(details[2]));

        int paymentMode = scanner.nextInt();

        switch (paymentMode) {
            case 1: // Cash payment
                double cashAmount = scanner.nextDouble();
                System.out.printf("Stage event:%s\nCustomer:%s\nNumber of seats:%d\n",
                        booking.getStageEvent(), booking.getCustomer(), booking.getNoOfSeats());
                booking.makePayment(cashAmount);
                break;

            case 2: // Wallet payment
                double walletAmount = scanner.nextDouble();
                String walletNumber = scanner.next();
                System.out.printf("Stage event:%s\nCustomer:%s\nNumber of seats:%d\n",
                        booking.getStageEvent(), booking.getCustomer(), booking.getNoOfSeats());
                booking.makePayment(walletAmount, walletNumber);
                break;

            case 3: // Credit card payment
                scanner.nextLine(); // Consume newline
                String cardHolderName = scanner.nextLine();
                double cardAmount = scanner.nextDouble();
                scanner.nextLine(); // Consume newline
                String cardType = scanner.nextLine();
                String ccv = scanner.nextLine();
                System.out.printf("Stage event:%s\nCustomer:%s\nNumber of seats:%d\n",
                        booking.getStageEvent(), booking.getCustomer(), booking.getNoOfSeats());
                booking.makePayment(cardHolderName, cardAmount, cardType, ccv);
                break;

            default: // Invalid choice
                System.out.println("Invalid choice");
        }

        scanner.close();
    }
}

