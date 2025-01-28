package lab6;

import java.util.*;

public class Customer implements Product{
	
	int item_count;
	String name[];
	double cost[];
	String c_name;
	int c_id;
	
	
	Customer(){
		this.item_count=0;
		this.name[0]="blank";
		this.cost[0]=0.0;
		this.c_name="blank";
		this.c_id=0;
	}
	
	Customer(String c_n,int c_i,int i,String n[],double c[]){
		this.c_name=c_n;
		this.c_id=c_i;
		this.item_count=i;
		
		this.name = new String[item_count];
		for(int j=0;j<item_count;j++) {
			name[j] = n[j];
		}
		
		this.cost = new double[item_count];
		for(int j=0;j<item_count;j++) {
			cost[j]=c[j];
		}
	}
	
	public double ProductDetails() {
		
		double total=0.0;
		
		for(int i=0;i<item_count;i++) {
			total = total+cost[i];
		}
		
		return total;
	}
	
	
	
	public void show_Bill() {
		double total=ProductDetails();
		double gst=0.0;
		
		if(total>10000 &&total<=30000) {
			gst = (total*5)/100;
		}
		
		else if(total>30000 && total<=50000) {
			gst=(total*7)/100;
		}
		
		else if(total>50000) {
			gst=(total*9)/100;
		}
		
		total=total+gst;
		System.out.println(total);
	}
	
	public String getName() {
		return c_name;
	}
	
	public int getID() {
		return c_id;
	}
	
	public void showdetails() {
		System.out.println("ID: "+ c_id);
		System.out.println("Name: "+ c_name);
		System.out.print("Bill: ");
		this.show_Bill();
	
	}
}
