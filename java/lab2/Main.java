package lab2;

import java.util.Scanner;

public class Main {
	
	    public static void main(String[] args) {
	        Scanner sc = new Scanner(System.in);

	        Innings[] inningsArray = new Innings[2];

	        for (int i = 0; i < 2; i++) {
	            System.out.println("For Innings " + (i + 1) + "->");
	            System.out.print("Batting Team: ");
	            String bt = sc.next();
	            System.out.print("Runs: ");
	            int r = sc.nextInt();

	            inningsArray[i] = new Innings(bt,r);
	            inningsArray[i].setBattingTeam(bt);
	            inningsArray[i].setRuns(r);
	        }

	        for (int i = 0; i < 2; i++) {
	            System.out.println("Innings " + (i + 1) + "Details:");
	            System.out.println("Batting Team: " + inningsArray[i].getBattingTeam());
	            System.out.println("Runs scored: " + inningsArray[i].getRuns());
	        }

	    }
	}


