package lab3;

import java.util.*;

class ItemType {
    private String name;
    private double deposit;
    private double costPerDay;

    public ItemType() {}

    public ItemType(String name, double deposit, double costPerDay) {
        this.name = name;
        this.deposit = deposit;
        this.costPerDay = costPerDay;
    }

    public String getName() {
        return name;
    }
	void setName(String name) {
		this.name=name;
	}
	
	double getDep() {
		return deposit;
	}
	void setDep(double dep) {
		this.deposit=dep;
	}
	
	double getCost() {
		return costPerDay;
	}
	void setCost(double c){
		this.costPerDay=c;
	}

    public void display() {
        System.out.printf("%s %.1f %.1f\n", name, deposit, costPerDay);
    }
}
