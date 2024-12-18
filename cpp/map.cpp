#include<iostream>
#include<map>

int main(){

    std::map<int, std::string> mymap={{1,"apple"}, {45,"soffia"},{420,"ahon"}};

    mymap[3] = "Camera";
    mymap[52] = "music";

    for(const auto &elem : mymap){
        std::cout<<elem.first<<" : "<<elem.second;
    }

    auto it = mymap.find(420);

    if(it!= mymap.end()){
        std::cout<<"Element found: "<<it->first<<" "<<it->second;
    }
    else{
        std::cout<<"Element not found";
    }
}