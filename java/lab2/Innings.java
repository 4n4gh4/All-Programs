package lab2;

import java.util.*;

public class Innings {
	private String battingTeam;
	private int runs;
	
	public Innings(String bt,int r){
	this.battingTeam=bt;
	this.runs=r;
	}

		public String getBattingTeam() {
	        return battingTeam;
	    }

	    public void setBattingTeam(String battingTeam) {
	        this.battingTeam = battingTeam;
	    }

	    public int getRuns() {
	        return runs;
	    }

	    public void setRuns(int runs) {
	        this.runs = runs;
	    }
	}