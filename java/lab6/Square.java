package lab6;

public class Square implements ShapeCalculator{
	
	int n;
	
	Square(int n){
		this.n=n;
	}
	
	public void calc(int n) {
		System.out.println(n*n + " "+ 4*n);
	}

}
