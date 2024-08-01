#include <iostream>
#include <string>
using namespace std;

class book {
private:
    string aname;
    string edition;
    string bname;
    string yop;
    string genre;
    int isbn;
    float price;
    
      //these are the private keys in the class book
      
        int visbn(int isbn){
        int x=isbn, rem, i, sum=0;
        
        while(x>0){
            rem =x%10;
            sum+=(rem*i);
            i++;
            x = x/10;
        }     
        
        if(sum%11==0){
            return 0;
        }
        
        else return -1;
        
    }


public:
    book(string a, string e, string b, string y, string g, int i, float p) {
        if(visbn(i)== 0)
        {
        aname = a;
        bname = b;
        edition = e;
        yop = y;
        genre = g;
        isbn = i;
        price =p;
        }
        
        else{
            printf("Invalid ISBN. No details stored. \n");
        }
        
    }

    void dbook() {
        cout << "Author name: " << aname << endl;
        cout << "Book name: " << bname << endl;
        cout << "Edition: " << edition << endl;
        cout << "Genre: " << genre << endl;
        cout << "Year of Publication: " << yop << endl;
        cout << "ISBN code: " << isbn << endl;
        cout << "Book Price: " << price << endl;
        
    }//displays book details
    

};

int main() {
    float price;
    int isbn;
    string aname, bname, edition, genre, yop;

    cout << "Enter author name: ";
    cin >> aname;
    cout << "Enter book name: ";
    cin >> bname;
    cout << "Enter book edition: ";
    cin >> edition;
    cout << "Enter book genre: ";
    cin >> genre;
    cout << "Enter ISBN code of book: ";
    cin >> isbn;
    cout << "Enter year of publication: ";
    cin >> yop;
    cout << "Enter price of book: ";
    cin >> price;
    
    printf("\n");
    
        book b(aname, edition, bname, yop, genre, isbn, price);
        b.dbook();
        
        return 0;
    
}
