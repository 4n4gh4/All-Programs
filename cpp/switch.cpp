#include<iostream>
#include<string>
using namespace std;

class Complex{

    int real;
    int img;

    public:

    Complex(){
        real = 0;
        img = 0;
    }

    Complex(int a, int b){
        real = a;
        img = b;
    }

    Complex operator+(Complex const& two) const{
        return Complex(real+two.real, img+two.img);
    }

    Complex operator-(Complex const& two) const{
        return Complex(real-two.real, img-two.img);
    }

    Complex operator*(Complex const& two) const{
        return Complex(real*two.real, img*two.img);
    }

    Complex operator/(Complex const& two) const{
        return Complex(real/two.real, img/two.img);
    }

    void Display(){
        cout<<endl<<"The complex number is: "<<real<<" + "<<img<<"i"<<endl;
    }

    ~Complex(){
        cout<<endl<<endl<<"Object released!";
    }
};


int main(){
    int r, i, num;

    cout<< "Enter real coefficint 1: ";
    cin>>r;
    cout << "Enter imaginary coefficient 1: ";
    cin>>i;

    Complex b(r,i);

    cout<< "Enter real coefficint 2: ";
    cin>>r;
    cout << "Enter imaginary coefficient 2: ";
    cin>>i;

    Complex c(r,i);

    cout<<"Choose: "<<endl<<"1. Addition"<<endl<<"2. Subtraction"<<endl<<"3. Multiplication"<<endl<<"4.Division";
    cin>>num;

        
    cout<<endl;
    Complex a, d;
    a.Display();
    cout<<endl;
    b.Display();
    cout<<endl;
    c.Display();

    switch(num){
        case 1:
        d = b+c;
        break;

        case 2:
        d = b-c;
        break;
        
        case 3:
        d = b*c;
        break;
        
        case 4:
        d = b/c;
        break;
    }

    d.Display();

}