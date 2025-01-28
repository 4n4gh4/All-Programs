package lab2;

import java.util.*;

public class BMI{
	
	 private double weight;
	 private double height;
	 private double bmi;
	 private String grade;
	 
	 public BMI(double height, double weight){
		 this.height=height;
		 this.weight=weight;
		 this.bmi=calculateBMI();
		 this.grade=calculategrade();
	 }
	 
	 private double calculateBMI() {
		 return weight/(height*height);
	 }
	 
	 private String calculategrade() {
		if(bmi < 18.5) {
			return "Underweight [U]";
		}
		
		else if(18.5 <= bmi && bmi< 25.0) {
			return "Normal weight [N]";
		}
		
		else if(25.0 <= bmi && bmi < 30.0) {
			return "Heavyweight [H]";
		}
		
		else {
			return "Overweight [O]";
		}

	 }
	 
	 public void display() {
		 System.out.println("Your BMI is: " + bmi);
		 System.out.println("Your Grade is: " + grade);
	 }
	 
	 public static void main(String args[]) {
		 Scanner sc = new Scanner(System.in);
		 
		System.out.println("Enter your height: ");
		double h = sc.nextDouble();
		System.out.println("Enter your weight: ");
		double w = sc.nextDouble();
		
		BMI person1 = new BMI(h,w);
		person1.display();	
		 
	 }

}
