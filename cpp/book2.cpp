#include<iostream>
#include<string>
using namespace std;

class Book{
    string title;
    string author;
    double price;
    int isbn;

    int validate(int x){
        int y = x, rem, sum=0, i=1;

        while(y!=0){
            rem = y%10;
            sum += (rem*i);
            i++;
            y=y/10;
        }

        if(sum%11==0){
            return 0;
        }

        else {
            return 1;
        }
    }

    public:

    int val;

    Book(string a, string b, double c, int d){


        title = a;
        author = b;
        price = c;
        isbn = d;

        if( validate(d)== 0){
            val=0;
        }

        else{
            val =1;
        }
    }

    void display(){
        cout<<"The book name is: "<<title<<endl;
        cout<<"The author of the book is: "<<author<<endl;
        cout<<"The book price is: "<<price<<endl;
        cout<<"The isbn is: "<<isbn;

        if(val==0){
            cout<<endl<<"ISBN is valid";
        }

        else{
            cout<<endl<<"ISBN is invalid";
        }
    }


};

int main(){

    string a, b;
    double c;
    int d;

    cout<< "Enter book name: ";
    cin>>a;
    cout << "Enter author name: ";
    cin>>b;
    cout<< "Enter book price: ";
    cin>>c;
    cout << "Enter isbn no: ";
    cin>>d;

    Book b1(a,b,c,d);
    b1.display();
}