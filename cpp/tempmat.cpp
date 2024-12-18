#include <iostream>
#include <string>
using namespace std;

template <typename T1>
class Matrix {
private:
    int row;
    int col;
    T1** data;

public:
    // Constructor
    Matrix() : row(3), col(3) {
        data = new T1*[row];
        for (int i = 0; i < row; ++i) {
            data[i] = new T1[col]();
        }
    }

    // Parameterized constructor
    Matrix(int r, int c) : row(r), col(c) {
        data = new T1*[row];
        for (int i = 0; i < row; ++i) {
            data[i] = new T1[col]();
        }
    }

    // Set element
    void set(int r, int c, T1 val) {
        if (r >= 0 && r < row && c >= 0 && c < col) {
            data[r][c] = val;
        } else {
            cout << "Invalid index!" << endl;
        }
    }

    // Getter for row
    int getRow() const {
        return row;
    }

    // Getter for column
    int getCol() const {
        return col;
    }

    // Getter for data element
    T1 getData(int r, int c) const {
        return data[r][c];
    }

    // Operator overloading for addition
    template<typename T2>
    Matrix<float> operator+(Matrix<T2>& o) {
        Matrix<float> result(row, col);
        for (int i = 0; i < getRow(); ++i) {
            for (int j = 0; j < getCol(); ++j) {
                result.set(i, j, getData(i, j) + o.getData(i, j));
            }
        }
        
        return result;

    }

    template<typename T2>
    Matrix<float> operator-(Matrix<T2>& o) {
        Matrix<float> result(row, col);
        for (int i = 0; i < getRow(); ++i) {
            for (int j = 0; j < getCol(); ++j) {
                result.set(i, j, getData(i, j) - o.getData(i, j));
            }
        }
        
        return result;

    }

    template<typename T2>
    Matrix<float> operator*(Matrix<T2>& o) {
        Matrix<float> result(row, col);
        for (int i = 0; i < getRow(); ++i) {    
            for (int j = 0; j < getCol(); ++j) {

                result.set(i,j,0);

                for(int k=0;k<getCol();k++){
                    result.set(i, j, result.getData(i, j) + data[i][k] * o.getData(k, j));            
                }
           }
        }

        return result;
    }



    // Friend function to overload << operator for printing matrix
    friend ostream& operator<<(ostream& os, const Matrix<T1>& o) {
        for (int i = 0; i < o.getRow(); ++i) {
            for (int j = 0; j < o.getCol(); ++j) {
                os << o.getData(i, j) << " ";
            }
            os << endl;
        }
        return os;
    }

};

int main() {
    int r1, c1, r2, c2, a, choice, c=0;
    float b;

    cout << "Enter total rows in matrix 1: ";
    cin >> r1;
    cout << "Enter total columns in matrix 1: ";
    cin >> c1;

    Matrix<int> m2(r1, c1);

    for (int i = 0; i < r1; ++i) {
        for (int j = 0; j < c1; ++j) {
            cout << "Enter element [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> a;
            m2.set(i, j, a);
        }
    }

    cout << "Enter total rows in matrix 2: ";
    cin >> r2;
    cout << "Enter total columns in matrix 2: ";
    cin >> c2;

    Matrix<float> m3(r2, c2);

    for (int i = 0; i < r2; ++i) {
        for (int j = 0; j < c2; ++j) {
            cout << "Enter element [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> b;
            m3.set(i, j, b);
        }
    }

    cout << endl << "The matrices are: " << endl;
    cout << "Matrix 1: " << endl;
    cout << m2;  // Print matrix 1
    cout << "Matrix 2: " << endl;
    cout << m3;  // Print matrix 2


    while(c==0){


    cout<<"Enter the operation choice: "<<endl<<"1. addition"<<endl<<"2. subtraction"<<endl<<"3. multiplication"<<endl<<"4. any key to exit"<<endl;
    cin>>choice;


    switch(choice){

        case 1:
            if (m2.getRow() == m3.getRow() && m2.getCol() == m3.getCol()) {
                Matrix<float> m4 = m2 + m3;  // Add matrices
                cout << "Resultant Matrix (Matrix 1 + Matrix 2):" << endl;
                cout << m4;  // Print resultant matrix
            } 
            
            else {
                cout << "Matrices cannot be added due to dimension mismatch." << endl;
            }
            break;
        
        case 2:
            if (m2.getRow() == m3.getRow() && m2.getCol() == m3.getCol()) {
                Matrix<float> m4 = m2 - m3;  // subtracts matrices
                cout << "Resultant Matrix (Matrix 1 + Matrix 2):" << endl;
                cout << m4;  // Print resultant matrix
            } 
            
            else {
                cout << "Matrices cannot be subtracted due to dimension mismatch." << endl;
            }
            break;

        case 3:
            if (m2.getRow() == m3.getRow() && m2.getCol() == m3.getCol()) {
                Matrix<float> m4 = m2 * m3;  // Add matrices
                cout << "Resultant Matrix (Matrix 1 + Matrix 2):" << endl;
                cout << m4;  // Print resultant matrix
            } 
            
            else {
                cout << "Matrices cannot be added due to dimension mismatch." << endl;
            }
            break;      

        default:
        c++;
        break;  


    }

    

    }

    return 0;
}
