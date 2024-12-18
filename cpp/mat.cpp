#include<iostream>
using namespace std;

class Matrix{
    private:
    int r;
    int c;
    int **data;

    public:
    Matrix(int rows, int cols) {
        r=rows;
        c=cols;
        data = new int*[r];
        for(int i = 0; i < r; i++) {
            data[i] = new int[c];
            for(int j = 0; j < c; j++) {
                data[i][j] = 0;
            }
        }
    }



    void Setvalue(int r, int c, int value){
        data[r][c]=value;

    }

     void print(){
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                cout<<data[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    Matrix operator*(Matrix const &other){
        if (c!=other.r){
            cout<<"Matrix multiplication not possible"<<endl;
            exit(1);
        }

        else{

            Matrix res(r, other.c);

            for (int i=0; i<r; i++){
                for (int j=0; j<other.c; j++){
                    res.data[i][j]=0;
                    for (int k=0; k<c; k++){
                        res.data[i][j]=res.data[i][j]+ data[i][k]*other.data[k][j];
                    }
                }
            }
            return res;
        }    
    
    }
       

};

int main() {
    Matrix m1(3, 2);
    Matrix m2(2, 3);

    m1.Setvalue(0, 0, 1);
    m1.Setvalue(0, 1, 3);
    m1.Setvalue(1, 0, 0);
    m1.Setvalue(1, 1, 2);
    m1.Setvalue(2, 0, 3);
    m1.Setvalue(2, 1, 4);

    cout << "Matrix m1:" << endl;
    m1.print();
    cout << "\n";

    m2.Setvalue(0, 0, 2);
    m2.Setvalue(0, 1, 1);
    m2.Setvalue(0, 2, 3);
    m2.Setvalue(1, 0, 4);
    m2.Setvalue(1, 1, 1);
    m2.Setvalue(1, 2, 2);

    cout << "Matrix m2:" << endl;
    m2.print();
    cout << "\n";

    Matrix m3 = m1 * m2;

    cout << "Matrix m3 (result of m1 * m2):" << endl;
    m3.print();

    return 0;
}