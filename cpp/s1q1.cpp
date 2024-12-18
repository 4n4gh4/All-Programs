#include <iostream>
using namespace std;

class Matrix {
private:
    int row;
    int col;
    int **data;

public:
    Matrix() {
        row = 3;
        col = 3;
        data = new int*[row];
        for (int i = 0; i < row; i++) {
            data[i] = new int[col];
            for (int j = 0; j < col; j++) {
                data[i][j] = 0;
            }
        }
    }

    Matrix(int r, int c, int value) {
        row = r;
        col = c;
        data = new int*[row];
        for (int i = 0; i < row; i++) {
            data[i] = new int[col];
            for (int j = 0; j < col; j++) {
                data[i][j] = value;
            }
        }
    }

    Matrix(int r, int c, int arr[][3]) {
        row = r;
        col = c;
        data = new int*[row];
        for (int i = 0; i < row; i++) {
            data[i] = new int[col];
            for (int j = 0; j < col; j++) {
                data[i][j] = arr[i][j];
            }
        }
    }

    void print() {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }

};

int main() {
    cout << "Default constructor: " << endl;
    Matrix mat1;
    mat1.print();
    cout << endl;

    cout << "Parameterized constructor: " << endl;
    Matrix mat2(3, 3, 7);
    mat2.print();
    cout << endl;

    cout << "Array to matrix: " << endl;
    int arr[3][3], i, j;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            cout<<"Enter element ["<<i+1<<"]["<<j+1<<"] for array: ";
            cin>>arr[i][j];
        }
    }
    Matrix mat3(3, 3, arr);
    mat3.print();

    return 0;
}
