package lab6;

public class Circle implements ShapeCalculator{
	
	int n;
	
	Circle(int n){
		this.n=n;
	}
	
	public void calc(int n) {
		System.out.println(3.14*Math.pow(n,2)+" "+2*3.14*n);
	}

}
