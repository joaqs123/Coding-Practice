#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <cstdint>
using namespace std;


// Function to find the nth prime number using a modified Sieve of Eratosthenes
long long sumPrimesBelow(int limit) {

    // Create a boolean vector for the sieve
    vector<bool> sieve(limit + 1, true);
    sieve[0] = sieve[1] = false; // 0 and 1 are not prime

    // Sieve of Eratosthenes
    for (int p = 2; p * p <= limit; p++) {
        if (sieve[p]) {
            for (int multiple = p * p; multiple <= limit; multiple += p) { //Start at the prime number squared. i.e: if at 3 start at 3x3 all previous multiples are accounted for
                sieve[multiple] = false;
            }
        }
    }

    // Collect primes and find the nth one
    long long sum = 0;
    for (int i = 2; i <= limit; i++) {
        if (sieve[i]) {
            sum += i;
        }
    }

    return sum;
}

int main(){
    const int LIMIT = 2000000;

    long long sum = sumPrimesBelow(LIMIT);
    cout << "The summation of all the prime numbers up to " << LIMIT << " is: " << sum << endl;

    return 0;
}