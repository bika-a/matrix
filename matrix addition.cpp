#include <iostream>
using namespace std;

class Matrix {
    int **data;
    int rlimit, climit;

public:
    // Dynamic constructor
    Matrix(int rows, int cols) : rlimit(rows), climit(cols) {
        data = new int*[rlimit];
        for (int i = 0; i < rlimit; ++i) {
            data[i] = new int[climit];
            for (int j = 0; j < climit; ++j) {
                data[i][j] = 0; // Initializing all elements to 0
            }
        }
    }

    // Copy constructor
    Matrix(const Matrix &other) : rlimit(other.rlimit), climit(other.climit) {
        data = new int*[rlimit];
        for (int i = 0; i < rlimit; ++i) {
            data[i] = new int[climit];
            for (int j = 0; j < climit; ++j) {
                data[i][j] = other.data[i][j];
            }
        }
    }

    // Destructor
    ~Matrix() {
        for (int i = 0; i < rlimit; ++i) {
            delete[] data[i];
        }
        delete[] data;
    }

    // Member function to add two matrices
    Matrix add(const Matrix &other) const {
        if (rlimit != other.rlimit || climit != other.climit) {
            cerr << "Matrix dimensions do not match for addition.";
            exit(1);
        }

        Matrix result(rlimit, climit);
        for (int i = 0; i < rlimit; ++i) {
            for (int j = 0; j < climit; ++j) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    // Function to fill the matrix with user input
    void fill() {
        cout << "Enter elements for " << rlimit << "x" << climit << " matrix:" ;
        for (int i = 0; i < rlimit; ++i) {
            for (int j = 0; j < climit; ++j) {
                cin >> data[i][j];
            }
        }
    }

    // Function to display the matrix
    void display() const {
        for (int i = 0; i < rlimit; ++i) {
            for (int j = 0; j < climit; ++j) {
                cout << data[i][j] << " ";
            }
            cout <<endl;
        }
    }
};

int main() {
    int rows, cols;
    cout << "Enter the number of rows and columns for the matrices: ";
    cin >> rows >> cols;

    Matrix mat1(rows, cols);
    Matrix mat2(rows, cols);

    cout << "Fill the first matrix:" ;
    mat1.fill();

    cout << "Fill the second matrix:" ;
    mat2.fill();

    Matrix mat3 = mat1.add(mat2);

    cout << "The result of matrix addition is:";
    mat3.display();

    return 0;
}
