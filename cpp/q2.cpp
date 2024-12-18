#include<iostream>
#include<string>
using namespace std;

class ComplexRational{
    
    private:

    int numeratorReal;
    int numeratorImaginary;
    int denominatorReal;
    int denominatorImaginary;
    
    public:

    ComplexRational(){                      //default constructor
    numeratorReal=0;
    numeratorImaginary = 0;
    denominatorReal = 0;
    denominatorImaginary=0;
    }
    
    ComplexRational(int a, int b, int c, int d){            //parameterised constructor
    numeratorReal=a;
    numeratorImaginary = b;
    denominatorReal = c;
    denominatorImaginary=d;
    }
    
   ComplexRational operator+(ComplexRational const& o) const{          //addition of two rationals
       
       int nr,ni,dr,di;

       //here nr is the final numerator real after addition, ni is the imaginary numerator, dr is the real denominator and di is the imaginary denominator

       nr = numeratorReal*o.denominatorReal + o.numeratorReal*denominatorReal;
       dr = denominatorReal*o.denominatorReal;
       
       ni = numeratorImaginary*o.denominatorImaginary + o.numeratorImaginary*denominatorImaginary;
       di = denominatorImaginary*o.denominatorImaginary;
       
       return ComplexRational(nr,ni,dr,di);

            //operator overloading is done for + and returned as an object of type ComplexRational class
   }
    
   ComplexRational operator-(ComplexRational const& o) const{
       
       int nr,ni,dr,di;

       nr = numeratorReal*o.denominatorReal - o.numeratorReal*denominatorReal;
       dr = denominatorReal*o.denominatorReal;
       
       ni = (numeratorImaginary*o.denominatorImaginary) - (o.numeratorImaginary*denominatorImaginary);
       di = denominatorImaginary*o.denominatorImaginary;
       
       return ComplexRational(nr,ni,dr,di);

        //operator overloading is done for - and returned as an object of type ComplexRational class
   }
   
   ComplexRational operator*(ComplexRational const& o) const{
       
       int nr,ni,dr,di;
       
       int t1,t2,t3,t4,t5,t6,t7,t8;

       t1 = numeratorReal*o.numeratorReal;
       
       t2 = numeratorReal*o.numeratorImaginary;
       
       t3 = numeratorImaginary*o.numeratorReal;
       
       t4 = numeratorImaginary*o.numeratorImaginary;
       
       t5 = denominatorReal*o.denominatorReal;
       
       t6 = denominatorReal*o.denominatorImaginary;
       
       t7 = denominatorImaginary*o.denominatorReal;
       
       t8 = denominatorReal*o.denominatorImaginary;
       

       //where t1-t8 are the terms we get upon using distributive property
       

       
       nr = t1 * t8 - t4 * t5;
       dr = t5 * t8;
       
       ni = t2 * t7 + t3*t6;
       di = t6*t7;

       return ComplexRational(nr,ni,dr,di);


     //operator overloading is done for * and returned as an object of type ComplexRational class
   }
   
    ComplexRational operator<<(ComplexRational const& o) const{
        
        if(denominatorReal== 0 || denominatorImaginary == 0){
        cout<<endl<<"infinity"<<endl;
            
        }           //since any fraction with denominator 0 is infinity, adding infinity to any number will also be infinity
        
        else{
            
        cout<<endl<<numeratorReal<<"/"<<denominatorReal<<" + ("<<numeratorImaginary<<"/"<<denominatorImaginary<<") i"<<endl;
            
        }
     
       
       return ComplexRational(numeratorReal, numeratorImaginary,denominatorReal, denominatorImaginary);


    //operator overloading is done for << and returned as an object of type ComplexRational class

   }

};

int main(){
    
    int a,b,c,d, choice;
    char flag='0';                       //to repeat the code in a while loop

    ComplexRational x, obj1;

    while(flag == '0'){
    
    cout<<"Enter real numerator: ";
    cin>>a;
    cout<<"Enter imaginary numerator: ";
    cin>>b;
    cout<<"Enter real denominator: ";
    cin>>c;
    cout<<"Enter imaginary denominator: ";
    cin>>d;
    

    
    ComplexRational y(a,b,c,d),z(a,b,c,d);              

    cout<<endl;
    cout<<"Enter your choice: "<<endl;
    cout<<"1. Addition"<<endl<<"2. Subtraction"<<endl<<"3. Multiplication"<<endl;
    cin>>choice;

    switch(choice){                 //menu driven code using switch case

        case 1:
        obj1 = y + z;
        obj1 = obj1<<obj1;
        break;

        case 2:
        obj1 = y - z;
        obj1 = obj1<<obj1;
        break;

        case 3:
        obj1 = y * z;
        obj1 = obj1<<obj1;
        break;

    }

    cout<<endl;
    cout<<"To repeat the program, enter 0. To exit, enter any key: ";
    cin>>flag;
    cout<<endl;
    cout<<endl;                                   //code asking user input to terminate/execute again
    }

    return 0;
    
}