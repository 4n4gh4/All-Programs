#include<iostream>
#include<string>
using namespace std;

class Weather{
    int sID;
    double temp;
    double humid;
    int press;

    int tval(double t){
        if(t<=50 && t>= -50){
            return 0;
        }

        else{
            return 1;
        }

    }

    int hval(double h){
        if(h<=100 && h>= 0){
            return 0;
        }

        else{
            return 1;
        }

    }

    int pval(double p){
        if(p<=1100 && p>= 300){
            return 0;
        }

        else{
            return 1;
        }

    }

    
    public:

    int valt,valh,valp;

    Weather(){
        sID = 0;
        temp = 20.0;
        humid = 50.0;
        press = 1013.25;
    }

    
    Weather(int a, double b, double c, double d){

        sID = a;
        temp = b;
        humid = c;
        press = d;

        if(tval(temp) == 0){
            valt = 0;
        }

        else {
            valt = 1;
        }

        if(hval(humid) == 0){
            valh = 0;
        }

        else {
            valh = 1;
        }

        if(pval(press) == 0){
            valp = 0;
        }

        else {
            valp = 1;
        }



    }


        void display()
    {
        cout<<"The station ID is: "<<sID<<endl;
        cout<<"The temperature is: "<<temp<<endl;
        cout<<"The humidity is: "<<humid<<endl;
        cout<<"The pressure is: "<<press;

        if(valt==1){
            cout<<endl<<"Temperature is invalid"<<endl;

        temp = 20.0;
            
        }

        if(valh==1){
            cout<<endl<<"Humidity is invalid"<<endl;
            humid = 50.0;
            
        }

        if(valp==1){
            cout<<endl<<" Pressure is invalid"<<endl;
            press = 1013.25;

        }

        
        cout<<"The station ID is: "<<sID<<endl;
        cout<<"The temperature is: "<<temp<<endl;
        cout<<"The humidity is: "<<humid<<endl;
        cout<<"The pressure is: "<<press;

    }
    



};

int main(){

    double t, p, h;
    int s;

    cout<< "Enter station ID: ";
    cin>>s;
    cout << "Enter temperature: ";
    cin>>t;
    cout<< "Enter humidity: ";
    cin>>h;
    cout << "Enter pressure: ";
    cin>>p;

    Weather w(s,t,p,h), ww;
    cout<<endl;
    w.display();
    cout<<endl;
    ww.display();
}