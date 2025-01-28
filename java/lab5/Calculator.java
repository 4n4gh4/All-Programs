package lab5;

import java.util.*;

public class Calculator extends AbstractClass{
	Scanner sc = new Scanner(System.in);
	@Override
	int getValue() {
		System.out.println("Enter the value: ");
		return sc.nextInt();
	}
	
	@Override
	int divisorSum(int n) {
		int sum = 0;

        for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                sum += i;
            }
        }
        return sum;
	}
	
	public static void main(String[] args) {
		Calculator calc = new Calculator();
		
		int n = calc.getValue();
		int sum = calc.divisorSum(n);
		
		System.out.println(sum);
	}
}
