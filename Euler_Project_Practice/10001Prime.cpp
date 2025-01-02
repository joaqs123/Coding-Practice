#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Function to estimate an upper bound for the nth prime
int estimateUpperBound(int n) {
    if (n < 6) return 15; // Small fixed upper bound for small n
    return (int)(n * log(n) + n * log(log(n))); // Approximation for larger n
}

// Function to find the nth prime number using a modified Sieve of Eratosthenes
int findNthPrime(int n) {
    // Estimate an upper bound for the nth prime
    int upperBound = estimateUpperBound(n);

    // Create a boolean vector for the sieve
    vector<bool> sieve(upperBound + 1, true);
    sieve[0] = sieve[1] = false; // 0 and 1 are not prime

    // Sieve of Eratosthenes
    for (int p = 2; p * p <= upperBound; p++) {
        if (sieve[p]) {
            for (int multiple = p * p; multiple <= upperBound; multiple += p) { //Start at the prime number squared. i.e: if at 3 start at 3x3 all previous multiples are accounted for
                sieve[multiple] = false;
            }
        }
    }

    // Collect primes and find the nth one
    int count = 0;
    for (int i = 2; i <= upperBound; i++) {
        if (sieve[i]) {
            count++;
            if (count == n) return i; // Return the nth prime
        }
    }

    return -1; // If not found (shouldn't happen with a good upper bound)
}

// Driver code
int main() {
    int n;
    cout << "Enter the value of n to find the nth prime number: ";
    cin >> n;

    int nthPrime = findNthPrime(n);
    cout << "The " << n << " prime number is: " << nthPrime << endl;

    return 0;
}


/*
Visual representation:
- Have a list size 8 

[t][t][t][t][t][t][t][t][t][t]
 0  1  2  3  4  5  6  7  8  9

- skip 0 and 1 as they are not prime numbers
[f][f][t][t][t][t][t][t][t][t]
 0  1  2  3  4  5  6  7  8  9

 - starting at 2 make every multiple false
[f][f][t][t][f][t][f][t][f][t]
 0  1  2  3  4  5  6  7  8  9

 - move to 3 and start at 3x3 (3x2) is already taken care of and will be the case for every multiple where i<i*i
[f][f][t][t][f][t][f][t][f][f]
 0  1  2  3  4  5  6  7  8  9

 - this iteration only goes on while i < sqrt(n) where n is 9 in this case
 - after 3, the remaining numbers are prime numbers:

2, 3, 5, 7
*/
