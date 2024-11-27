#include <iostream>
#include <cmath>
using namespace std;

/*
    Uses some sort of algorithim and search function to find
    prime numbers. Read up on it some more for a better understanding.
*/

// Function to find the largest prime factor
long long largestPrimeFactor(long long n) {
    long long largest = -1;

    // Divide n by 2 as many times as possible
    while (n % 2 == 0) {
        largest = 2;
        n /= 2;
    }

    // Now n must be odd, so we can skip even numbers
    for (long long i = 3; i <= sqrt(n); i += 2) {
        // While i divides n, divide n and update largest
        while (n % i == 0) {
            largest = i;
            n /= i;
        }
    }

    // If n is still greater than 2, then it must be prime
    if (n > 2) {
        largest = n;
    }

    return largest;
}

int main() {
    long long number = 600851475143;
    cout << "The largest prime factor of " << number << " is: " << largestPrimeFactor(number) << endl;
    return 0;
}