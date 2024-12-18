#include<iostream>
#include<set>

using namespace std;

int main(){
    std::set<int> mys={4,5,5,9,10};
    mys.insert(20);
    mys.insert(50);

    cout<<"The size of my set is: "<<mys.size()<<endl;

    for(const int &elem : mys){
        cout<<elem<<" ";
    }

    mys.erase(0);
    cout<<endl;

    for(const int &elem : mys){
        cout<<elem<<" ";
    }

    auto it=mys.find(50);

    if(it!=mys.end()){
        cout<<"Element found: "<<*it<<endl;
    }

    else{
        cout<<"Element not found";
    }
    
}   
