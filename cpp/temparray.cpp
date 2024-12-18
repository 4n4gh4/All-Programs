#include<iostream>
using namespace std;

template <typename a>

void sort(int n, a arr[]){
    a min;
    int j,i;

    for(i=0;i<n-1;i++){
        min=arr[i];
        for(j=i+1;j<n;j++){
            if(arr[j]<min){
                arr[i] = arr[j];
                arr[j] = min;
                min = arr[i];
            }
        }
    }


}

int main(){

    int n;
    cout<<"Enter total elements: ";
    cin>>n;
    int arr1[n],i;
    float arr2[n];

    for(i=0;i<n;i++){
        cout<<"Enter int element "<<i+1<<": ";
        cin>>arr1[i];
    }

    cout<<endl<<endl;

    for(i=0;i<n;i++){
        cout<<"Enter float element "<<i+1<<": ";
        cin>>arr2[i];
    }
    sort(n,arr1);
    
    sort(n,arr2);
    
    cout<<endl<<"The sorted int array is: ";
    
    for(i=0;i<n;i++){
        cout<<arr1[i]<<" ";
    }

    cout<<endl<<endl<<"The sorted float array is: ";
    
    for(i=0;i<n;i++){
        cout<<arr2[i]<<" ";
    }
}