#include <iostream>
using namespace std;

class Matrix1D {
private:
    float* _mat; // Pointer to a 1D array
    int _rows;   // Number of rows
    int _cols;   // Number of columns

public:
    // Constructor
    Matrix1D(int r, int c) : _rows(r), _cols(c) {
        _mat = new float[_rows * _cols]; // Allocate memory for the matrix
    }

    // Destructor
    ~Matrix1D() {
        delete[] _mat; // Free memory
    }

    // Get number of rows
    int rows() const { return _rows; }

    // Get number of columns
    int cols() const { return _cols; }

    // Overload () operator for accessing elements
    float& operator()(int i, int j) {
        return _mat[i * _cols + j]; // Access element using 1D index
    }

    // Overload << operator for printing the matrix
    friend ostream& operator<<(ostream& out, const Matrix1D& m) {
        for (int i = 0; i < m._rows; i++) {
            for (int j = 0; j < m._cols; j++) {
                out << " " << m._mat[i * m._cols + j];
            }
            out << endl;
        }
        return out;
    }
};

int main() {
    Matrix1D m(4, 5); // Create a 4x5 matrix

    // Fill the matrix with some values
    for (int i = 0; i < m.rows(); i++) {
        for (int j = 0; j < m.cols(); j++) {
            m(i, j) = i + j; // Example: Fill with i + j
        }
    }

    // Print the matrix
    cout << m;

    return 0;
}
