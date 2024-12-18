#include<iostream>
using namespace std;

class Matrix{

    int row;
    int col;
    int **data;

    public:

     int i, j, k;
    
    Matrix(){
        row = 3;
        col = 3;


        data = new int*[row];

        for(i=0;i<3;i++){
            data[i] = new int[col];

            for(j=0;j<3;j++){
                data[i][j] = 0;
            }
        };

    }

    Matrix(int r, int c){
        row =r;
        col = c;

        data = new int*[r];

        for(i=0;i<r;i++){
            data[i] = new int[c];

            for(j=0;j<c;j++){
                data[i][j] = 0;
            }
        };
    }

    void setValue(int x, int y, int z){

        data[x][y] = z;
    }

    Matrix operator*(Matrix const& o) const{

        int i, j, k;

        if(row!=o.col){
            cout<<"Invalid dimensions";
            return Matrix(0,0);
        }

        else{

        Matrix result(row, o.col);
        
        for(i=0;i<row;i++){

            for(j=0;j<o.col;j++){

                result.data[i][j] = 0;

                for(k=0;k<col;k++){

                    result.data[i][j] = data[i][k]*o.data[k][j] + result.data[i][j];
                }

            }
        }

            return result;
        
        }

    }

    void display(){

        for(i=0;i<row;i++){
        for(j=0;j<col;j++){

            cout<<data[i][j]<<"  ";
        }
        cout<<endl;
        }
    }


};

int main(){
    int r, c, x, i, j;

    cout<<"For matrix 1: "<<endl;
    cout<<"Enter total no. of rows: ";
    cin>>r;
    cout<<"Enter total no. of columns: ";
    cin>>c;

    Matrix m2(r,c);

    for(i=0;i<r;i++){
        for(j=0;j<c;j++){

            cout<<"Value for ["<<i<<"]["<<j<<"]";
            cin>>x;
            m2.setValue(i,j,x);

        }
    }

    m2.display();

    cout<<"For matrix 2: "<<endl;
    cout<<"Enter total no. of rows: ";
    cin>>r;
    cout<<"Enter total no. of columns: ";
    cin>>c;

    Matrix m3(r,c);

    for(i=0;i<r;i++){
        for(j=0;j<c;j++){

            cout<<"Value for ["<<i<<"]["<<j<<"]";
            cin>>x;
            m3.setValue(i,j,x);

        }
    }

    m3.display();

    Matrix m4 = m2*m3;
    m4.display();
}





