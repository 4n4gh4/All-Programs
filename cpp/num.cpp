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

    void Display(){
        cout<<endl<<"The complex number is: "<<real<<" + "<<img<<"i"<<endl;
    }

    ~Complex(){
        cout<<endl<<endl<<"Object released!";
    }
};

class Number: public Complex{

public:

    int num;

    Number(int a){
        num = a;
    }

   void Displaynum(){
        Display();
        cout<<endl<<"The number is: "<<num;

    }    

};



int main(){
    int r, i, num;


    cout<< "Enter real coefficint: ";
    cin>>r;
    cout << "Enter imaginary coefficient: ";
    cin>>i;

    

    Complex a;
    a.Display();

    Complex b(r,i);
    b.Display();

    Complex c = a + b;
    c.Display();

    
    cout<< "Enter a number : ";
    cin>>num;

    Number n(num);

    n.Display();





}