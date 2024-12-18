#include<iostream>
#include<string>
using namespace std;

class Book{

    private:
    long bookID;
    string title;
    string author;
    float price;
    string genre;

    /*these are the variables in class book*/

    public:

    Book(){
        bookID=3248284233;
        genre="action";
        title="fun";
        author="jackson";
        price=0.0;

    }

    /*this is the default constructor where the values are already present*/


    Book(int b, string a, string t, string g, float p){

        bookID=b;
        genre=g;
        title = t;
        author=a;
        price=p;

    }

    /*the parametrised constructor where the user gives values*/

    void displayDetails(){
        cout<<"Book Title is: "<<title<<endl;
        cout<<"Book genre is: "<<genre<<endl;
        cout<<"Book ID is: "<<bookID<<endl;
        cout<<"Book author is: "<<author<<endl;
        cout<<"Book price is: "<<price<<endl;

    }

    /*function to display details*/

    void CalcualtePrice(){
        price+=500;

    }

    /*function to calculate price without discount*/

    void CalcualtePrice(float disc){
        price+=500;
        price = price - (disc/100*price);

    }

    /*function (overload) to calculate price with discount*/

    void updateDetails(float pr){
        cout<<"What is new price? ";
        cin>>pr;
        price = pr;
    }

    /*function to update price*/

    void updateDetails(string au){
        cout<<"What is the new author name: ";
        cin>>au;
        author = au;

    }

    /*function to update author name*/

    ~Book(){
        cout<<"Destructor called. \n";
    }

    /*destructor to destroy created objects in class book*/
};

int main(){
    string title, author, genre;
 long bookID;
    float price, disc;


    cout<<"Enter book title: ";
    cin>>title;
    cout<<"Enter author name: ";
    cin>>author;
    cout<<"Enter book ID: ";
    cin>>bookID;
    cout<<"Enter book genre: ";
    cin>>genre;
    cout<<"Enter book price: ";
    cin>>price;
    cout<<"What is the discount percentage? ";
    cin>>disc;


    Book b1;
    b1.displayDetails();

    /*object 1 is b1*/

    printf("\n \n");

    Book b2(bookID, author, title, genre, price);
    b2.CalcualtePrice();
    b2.displayDetails();

    printf("\n \n");

    /*object 2 is b2*/



    Book b3(bookID, author, title, genre, price);
    b3.CalcualtePrice(disc);
    b3.displayDetails();

    printf("\n \n");


    b2.updateDetails(price);
    b2.CalcualtePrice();
    b2.displayDetails();

    /*updates details of b2*/

    printf("\n \n");


    b3.updateDetails(author);
    b3.displayDetails();

    /*updates details of b3*/


return 0;

    
}