#include <iostream>
using namespace std;

class Matrix {
private:
    float** _mat; // Pointer to a 2D array
    int _rows;    // Number of rows
    int _cols;    // Number of columns

public:
    // Constructor
    Matrix(int r, int c) : _rows(r), _cols(c) {
        _mat = new float*[_rows]; // Allocate memory for rows
        for (int i = 0; i < _rows; i++) {
            _mat[i] = new float[_cols]; // Allocate memory for columns
        }
    }

    // Destructor
    ~Matrix() {
        for (int i = 0; i < _rows; i++) {
            delete[] _mat[i]; // Free memory for columns
        }
        delete[] _mat; // Free memory for rows
    }

    // Get number of rows
    int rows() const { return _rows; }

    // Get number of columns
    int cols() const { return _cols; }

    // Overload [] operator for accessing rows
    float* operator[](const int i) { return _mat[i]; }

    // Overload << operator for printing the matrix
    friend ostream& operator<<(ostream& out, const Matrix& m) {
        for (int i = 0; i < m._rows; i++) {
            for (int j = 0; j < m._cols; j++) {
                out << " " << m._mat[i][j];
            }
            out << endl;
        }
        return out;
    }
};

int main() {
    Matrix m(4, 5); // Create a 4x5 matrix

    // Fill the matrix with some values
    for (int i = 0; i < m.rows(); i++) {
        for (int j = 0; j < m.cols(); j++) {
            m[i][j] = i + j; // Example: Fill with i + j
        }
    }

    // Print the matrix
    cout << m;

    return 0;
}
