#include <iostream>
using namespace std;
int sum = 0;


/*
Can not do the sum function
with a recursive function.
*/


// Recursive function to calculate the nth Fibonacci number
int fibonacci(int n) {
    // Base cases
    if (n <= 1)
        return n;
    
    // Recursive case
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;
    
    // Ask the user for the number of terms
    cout << "Enter the number of terms: "; 
    cin >> n;

    fibonacci(n);
    
    // Print the Fibonacci sequence up to n terms
    cout << "Final Sum: " << sum << endl;
    
    return 0;
}