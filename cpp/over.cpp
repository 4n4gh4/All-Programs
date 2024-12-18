#include<iostream>
using namespace std;

class Funcs{

    double x;
    double y;

    public:

    Funcs(){
        x=0;
        y=0;
    }

    Funcs(int xx, int yy){
        x=xx;
        y=yy;
    }

  

    Funcs operator+(Funcs const& other) const&{
        return Funcs(x+other.x,y+other.y);
    }

    Funcs operator-(Funcs const& other) const&{
        return Funcs(x-other.x,y-other.y);
    }

    Funcs operator*(Funcs const& other) const&{
        return Funcs(x*other.x,y*other.y);
    }

    Funcs operator/(Funcs const& other) const&{
        return Funcs(x/other.x,y/other.y);
    }

    void operator<<(Funcs const& other) const&{
        printf("(%.2f,%.2f)", other.x, other.y);
    }
    



    int add(int a, int b){
        return a+b;
    }

    double add(double a, double b){
        return a+b;
    }

    ~Funcs(){}

};

int main(){

    int choice = 0;

    double j, k;

    Funcs f, a,b,c;

    printf("The sum of 2 integers: 5 and 6: %d", f.add(5,6));
    printf("The sum of 2 decimals: 84.39 and 98.3: %f \n", f.add(84.39,98.3));

cout<<endl<<endl<<endl;


while(choice==0){

start:
    cout<<"Enter your choice: \n";
cout<<"1. Taking 1st input values\n";
cout<<"2. Taking 2nd input value\n";
cout<<"3. Displaying both point 1 and 2\n";
cout<<"4. Adding both point 1 and 2\n";
cout<<"5. Subtracting both point 1 and 2\n";
cout<<"6. Multiplying both point 1 and 2\n";
cout<<"7. Dividing both point 1 and 2\n";
cout<<"8. Exit menu\n";
cin>>choice;

    if(choice==8){
        cout<<"Thank you!";
        break;
    }

    else{
        

switch (choice){
    case 1:
    cout<<"Enter the x coordinate: \n";
    cin>>j;
    cout<<"Enter the y coordinate: \n";
    cin>>k;
    a= Funcs(j,k);
    goto start;

    case 2:
    cout<<"Enter the x coordinate: \n";
    cin>>j;
    cout<<"Enter the y coordinate: \n";
    cin>>k;
    b= Funcs(j,k);
        goto start;


    case 3:
    printf("Point 1: ");
    a<<a;
    cout<<endl;
    printf("Point 2: ");
    b<<b;
        goto start;


    case 4:
    printf("Point 1 + Point 2: ");
    c = a + b;
    c<<c;
        goto start;


    case 5:
    printf("Point 1 - Point 2: ");
    c = a - b;
    c<<c;
        goto start;


    case 6:
    printf("Point 1 * Point 2: ");
    c = a * b;
    c<<c;
        goto start;


    case 7:
    printf("Point 1 / Point 2: ");
    c = a / b;
    c<<c;
        goto start;


    default:
    printf("Incorrect Entry");
        goto start;
    
}

}

}


    return 0;
}