#include<iostream>
#include<string>
using namespace std;

class BankAccount{
    
    private:
    int accountNumber;
    string accountHolderName;
    double balance;

    
    public:
    
    BankAccount(){
        accountNumber = 0;
        accountHolderName ="blank";                                  //default constructor
        balance = 0.0;
    }
    
    BankAccount(int a, string b, double c){
        accountNumber = a;
        accountHolderName = b;                                     //parameterised constructor
        balance = c;
    }
    
    double deposit(double dep){
        balance+= dep;                                      //public function to calculate deposit
        return balance;
    }
    
    double withdraw(double wit){
        
        if(balance<wit){
            cout<<"Insufficient funds to withdraw"<<endl;                   //function to calculate withdrawal
            return balance;
            }
        
        else{
            balance = balance - wit;
                return balance;

        }
        
        
    }
    
    double calculateInterest(double r, double t){
        double i = (balance * r * t)/100;
        balance = balance + i;                                  //calculates Interest
            return balance;
    }
    
    void display(){
        cout<<endl<<"Bank account number: "<<accountNumber;
           cout<<endl<<"Account holder name is: "<<accountHolderName;   //to display account details
              cout<<endl<<"Current bank balance: "<<balance;
    }
};

int main(){
    
    int a,r, choice;
    string b;
    double c,d,w,y;

    char flag='0';   //to repeat the code in a while loop

    BankAccount obj1;

    while(flag == '0'){
    
    cout<<"Enter bank account number: ";
    cin>>a;
    cout<<"Enter account holder name: ";
    cin>>b;
    cout<<"Enter account balance: ";
    cin>>c;
    
    BankAccount obj2(a,b,c), obj3(a,b,c);
    
    cout<<endl<<"Default constructor calling: "<<endl;
    obj1.display();
    
    cout<<endl;
    
    cout<<endl<<"Parametrised constructor calling: "<<endl;
    obj2.display();
    
    cout<<endl;
        
    
    cout<<"Enter your choice: "<<endl;              //menu driven choice
    cout<<"1. Deposit Money"<<endl<<"2. Withdraw money"<<endl<<"3. Simple Interest"<<endl;
    cin>>choice;

    switch (choice){                //using switch case

        case 1:
        cout<<"Enter the amount to deposit: ";
        cin>>d;
    
        c = obj3.deposit(d);
        cout<<"Balance after depositing: "<<c;
        cout<<endl;
        break;
        
        
        case 2:
        cout<<"Enter the amount to withdraw: ";
        cin>>w;
        
        c = obj3.withdraw(w);
        cout<<"Balance after withdrawing: "<<c;
        cout<<endl;
        break;
        
        case 3:
        cout<<"Enter the rate of interest: ";
        cin>>r;
        
        cout<<"Enter the interest time in years: ";
        cin>>y;
        
        c = obj3.calculateInterest(r,y);
        cout<<"Balance after adding interest: "<<c;
        break;


    }

    cout<<endl;
    cout<<"To repeat the program, enter 0. To exit, enter any key: ";
    cin>>flag;
    cout<<endl;
    cout<<endl;         //code asking user input to terminate/execute again

    }
    
   

    return 0;
    
}