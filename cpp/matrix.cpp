#include <iostream>
#include <string>
using namespace std;

class Matrix{

    private:

    int r;
    int c;
    int **data;

    

    public:

    Matrix(int x, int y){
        r = x;
        c = y;
        int i,j;

        data = new int*[r];

        for(i=0;i<r;i++){
            data[i] = new int[i];
            for(j=0;j<c;j++){
                data[i][j] = 0;
            }
        }
        
    }

    void setValue(int a, int b, int c){
        data[a][b] = c;
    }

    void print(){
        int i,j;
        for(i=0;i<r;i++){
            cout<<endl;
            for(j=0;j<c;j++){
                cout<<data[i][j]<<" ";
            }
        }
    }

    ~Matrix(){
        cout<<"Obj deleted"<<endl;
    };

};

int main(){

    int row, col, value, i, j;

    cout<<"Enter the array rows: ";
    cin>>row;
    cout<<"Enter the array columns: ";
    cin>>col;

    Matrix obj1(3,3);
    obj1.print();

    cout<<endl;


    Matrix obj2(row,col);

    for(i=0;i<row;i++){
        for(j=0;j<col;j++){

            cout<<"Enter the value for ["<<i<<"]["<<j<<"]: ";
            cin>>value;

            obj2.setValue(i,j,value);
            
        }
    }

    obj2.print();

    return 0;
}