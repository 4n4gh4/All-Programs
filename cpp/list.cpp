#include<iostream>
#include<list>

int main(){

    std::list<int> myl;
    std::list<float> myl2={1.1,3.4,5.6,67.4,9.56};

    myl.push_back(20);
    myl.push_back(10);
    myl.push_front(30);

    for(const int &elem : myl){
        std::cout<<elem<<" "<<std::endl;
        std::cout<<"Size of list: "<<myl.size()<<std::endl;
        
    }

    auto it=myl2.begin();
    std::advance(it,myl2.size()/2);
    myl2.insert(it,3.45);

    for(const int &elem : myl2){
        std::cout<<elem<<" "<<std::endl;
        std::cout<<"Size of list: "<<myl2.size()<<std::endl;
        
    }


}