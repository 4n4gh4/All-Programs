#include<iostream>
#include<vector>

using namespace std;

int main(){
    vector<int> myv;
    myv.push_back(10);
    myv.push_back(20);
    myv.push_back(30);

    cout<<"1st element: "<<myv[0];

    for(auto it=myv.begin();it!=myv.end();it++){
        cout<<"\t"<<*it;
    }

    cout<<endl;

    for(int i=0;i<myv.size();i++){
        cout<<myv[i]<<" ";
    }

    myv.clear();
}