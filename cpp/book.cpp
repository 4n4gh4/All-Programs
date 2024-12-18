#include <iostream>
#include <string>
using namespace std;

class Book {

    private:
    string name;
    int yop;
    string author;
    float price;
    long isbn;

    int visbn(long isbn){
        long x = isbn;
        int i, sum=0, rem;

        for(i=1;i<=10;i++){
            rem = x%10;
            sum = sum + rem * i;
            x = x/10;
        }

        if(sum%11 == 0){
            return 0;
        }

        else {
            return 1;
        }

    }

    public:

    //default constructor
    Book(){
        name = "blank";
        yop = 0;
        author = "blank";
        price = 0.0;
        isbn = 0;
    }

    //parametrised constructor
    Book(string a, int b, string c, float d, int e){
        
        if (visbn(e) == 1){

            cout<<"Invalid ISBN. No details stored.";

        }

        else {
            
        name = a;
        yop = b;
        author = c;
        price = d;
        isbn = e;

        }
    }

    float calculatePrice() {
        return price;
    }

    float calculatePrice(int x){
        price = price - (x/100.0)*price;
        return price;
    }


    void print(){
        cout<<"The book name is: "<<name<<endl;
        cout<<"The year of publication: "<<yop<<endl;
        cout<<"The author of the book is: "<<author<<endl;
        cout<<"The book price is: "<<price<<endl;
        cout<<"The isbn is: "<<isbn;

    }

    ~Book(){
        cout<<"Object has been deleted";
    }

};

int main(){

    string n, auth;
    int year, disc;
    long is;
    float price;

    cout<<"Enter the book name: ";
    cin>>n;
    cout<<"Enter the year of publication: ";
    cin>>year;
    cout<<"Enter the author name: ";
    cin>>auth;
    cout<<"Enter the price of the book: ";
    cin>>price;
    cout<<"Enter the isbn of the book: ";
    cin>>is;


    Book obj1;
    obj1.print();
    cout<<endl;

    Book obj2(n, year, auth, price, is);
    obj2.calculatePrice();
    obj2.print();
    cout<<endl;

    cout<<"Enter the discount: ";
    cin>>disc;

    Book obj3("Marigold", 2020, "James", 500.0, 04);
    obj3.calculatePrice(disc);
    obj3.print();

    

    return 0;


}