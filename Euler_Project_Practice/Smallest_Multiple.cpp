#include <iostream>
using namespace std;

// Function to calculate GCD using the Euclidean algorithm
long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to calculate LCM of two numbers
long long lcm(long long a, long long b) {
    return (a * b) / gcd(a, b);
}

// Function to calculate LCM of numbers from 1 to n
long long lcmOfRange(long long n) {
    long long result = 1;
    for (long long i = 2; i <= n; ++i) {
        result = lcm(result, i);
    }
    return result;
}

int main() {
    int n = 20; // Find LCM of numbers from 1 to 10
    cout << "The smallest number divisible by all numbers from 1 to " << n << " is: " << lcmOfRange(n) << endl;
    return 0;
}