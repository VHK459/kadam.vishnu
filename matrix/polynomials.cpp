#include <iostream>
#include <vector>
using namespace std;

class Polynomial {
private:
    vector<double> coefficients; // Coefficients of the polynomial
    int degree; // Degree of the polynomial

public:
    // Constructor to initialize a polynomial
    Polynomial(const vector<double>& coeffs) : coefficients(coeffs), degree(coeffs.size() - 1) {}

    // Get the degree of the polynomial
    int getDegree() const {
        return degree;
    }

    // Evaluate the polynomial at a given value of x
    double evaluate(double x) const {
        double result = 0.0;
        for (int i = 0; i <= degree; i++) {
            result += coefficients[i] * pow(x, i);
        }
        return result;
    }

    // Add two polynomials
    Polynomial operator+(const Polynomial& other) const {
        vector<double> resultCoeffs(max(degree + 1, other.degree + 1), 0.0);

        for (int i = 0; i <= degree; i++) {
            resultCoeffs[i] += coefficients[i];
        }

        for (int i = 0; i <= other.degree; i++) {
            resultCoeffs[i] += other.coefficients[i];
        }

        return Polynomial(resultCoeffs);
    }

    // Subtract two polynomials
    Polynomial operator-(const Polynomial& other) const {
        vector<double> resultCoeffs(max(degree + 1, other.degree + 1), 0.0);

        for (int i = 0; i <= degree; i++) {
            resultCoeffs[i] += coefficients[i];
        }

        for (int i = 0; i <= other.degree; i++) {
            resultCoeffs[i] -= other.coefficients[i];
        }

        return Polynomial(resultCoeffs);
    }

    // Multiply two polynomials
    Polynomial operator*(const Polynomial& other) const {
        vector<double> resultCoeffs(degree + other.degree + 1, 0.0);

        for (int i = 0; i <= degree; i++) {
            for (int j = 0; j <= other.degree; j++) {
                resultCoeffs[i + j] += coefficients[i] * other.coefficients[j];
            }
        }

        return Polynomial(resultCoeffs);
    }

    // Print the polynomial
    void print() const {
        for (int i = degree; i >= 0; i--) {
            if (coefficients[i] != 0) {
                if (i != degree) {
                    cout << " + ";
                }
                cout << coefficients[i];
                if (i > 0) {
                    cout << "x";
                    if (i > 1) {
                        cout << "^" << i;
                    }
                }
            }
        }
        cout << endl;
    }
};

int main() {
    // Create polynomials
    Polynomial p1({1, 2, 3}); // 1 + 2x + 3x^2
    Polynomial p2({4, 5});    // 4 + 5x

    // Print polynomials
    cout << "Polynomial 1: ";
    p1.print();
    cout << "Polynomial 2: ";
    p2.print();

    // Add polynomials
    Polynomial p3 = p1 + p2;
    cout << "Polynomial 1 + Polynomial 2: ";
    p3.print();

    // Subtract polynomials
    Polynomial p4 = p1 - p2;
    cout << "Polynomial 1 - Polynomial 2: ";
    p4.print();

    // Multiply polynomials
    Polynomial p5 = p1 * p2;
    cout << "Polynomial 1 * Polynomial 2: ";
    p5.print();

    // Evaluate polynomial at x = 2
    double result = p1.evaluate(2);
    cout << "Polynomial 1 evaluated at x = 2: " << result << endl;

    return 0;
}
