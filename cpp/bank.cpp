#include <iostream>
#include <string>
using namespace std;

class BankAccount{

    private:
    string holder;
    long no;
    float balance;
    float dep;
    float with;

    public:

    BankAccount(string h, long n, float b){
        holder=h;
        no = n;
        balance = b;
    }

    void display(){
        
        cout<<"Account holder name: " << holder<<endl;
        cout<<"Account Number: " << no<<endl;
        cout<<"Current Balance: " << balance<<endl;
    }

    void deposit(float dep){
        balance += dep;
        cout<<"Deposited " << dep << " into the account" <<endl; 
    }

    void withdraw(float with){
            
        if(balance-with < 0){
            cout<<"Insufficient balance or invalid withdrawal amount"<<endl;
        }

        else{
            balance -= with;
            cout<<"Withdrawn "<<with<<" from the account"<<endl;
        }

    }
    
};

int main(){
    string holder;
    float balance, with[2], dep;
    long no;

    cout<<"Enter account holder name: ";
    cin>>holder;
    cout<<"Enter account number: ";
    cin>>no;
    cout<<"Enter account balance: ";
    cin>>balance;
    cout<<"Enter deposit amount: ";
    cin>>dep;
    cout<<"Enter withdrawl amount 1: ";
    cin>>with[0];
    cout<<"Enter withdrawal amount 2: ";
    cin>>with[1];

    BankAccount account(holder, no, balance);
    
    account.display();
    account.deposit(dep);
    account.withdraw(with[0]);
    account.withdraw(with[1]);
    account.display();
  

    return 0;


}
