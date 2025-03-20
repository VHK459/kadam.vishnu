#include <iostream>
#include <vector>
#include <utility> // For std::pair
using namespace std;

class SparseMatrix {
private:
    int _rows; // Number of rows
    int _cols; // Number of columns
    vector<pair<pair<int, int>, float>> _mat; // Vector of pairs: ((row, col), value)

public:
    // Constructor
    SparseMatrix(int r, int c) : _rows(r), _cols(c) {}

    // Insert a non-zero element
    void insert(int i, int j, float value) {
        if (i >= _rows || j >= _cols) {
            cout << "Invalid position!" << endl;
            return;
        }
        _mat.push_back({{i, j}, value}); // Add the element to the vector
    }

    // Get number of rows
    int rows() const { return _rows; }

    // Get number of columns
    int cols() const { return _cols; }

    // Overload << operator for printing the matrix
    friend ostream& operator<<(ostream& out, const SparseMatrix& m) {
        for (const auto& elem : m._mat) {
            out << "(" << elem.first.first << ", " << elem.first.second << ") = " << elem.second << endl;
        }
        return out;
    }
};

int main() {
    SparseMatrix m(4, 5); // Create a 4x5 sparse matrix

    // Insert some non-zero elements
    m.insert(0, 1, 3.5);
    m.insert(1, 2, 4.2);
    m.insert(3, 4, 7.8);

    // Print the sparse matrix
    cout << m;

    return 0;
}
