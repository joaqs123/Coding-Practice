#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// Find the square of each number up to n and sum them together
double sumOfSquares(double n) {
    long double sum = 0;
    for (double i = 1.0; i <= n; i++){
        sum += pow(i, 2);
    }
    return sum;
}

// Find the sum of all the numbers up to n and square them
double squareOfSums(double n) {
    long double sum = 0;
    for (double i = 1.0; i <= n; i++){
        sum += i;
    }
    sum = pow(sum, 2);
    return sum;
}

int main() {
    cout << fixed << setprecision(0); // To ensure it is not printed out in scientific notation

    cout << "Sum of Squares: " << sumOfSquares(100) << endl;
    cout << "Square of Sum: " << squareOfSums(100) << endl;
    cout << "The difference between the Sum of the Squares and the Square of the Sums is: " << squareOfSums(100) - sumOfSquares(100) << endl;
    return 0;
}