#include <iostream>
using namespace std;


int main() {
    int product;
    int reverse, remainder;
    int palindrome_highest = 0;

    for (int i = 999; i>100; i--){
        for (int j = 999; j>100; j--){
            product = i * j;
            int temp = product;
            reverse = 0;

            while(temp > 0){
                remainder = temp % 10;
                reverse = reverse * 10 + remainder;
                temp /= 10;
            }

            if (product == reverse){
                if (product > palindrome_highest){
                    palindrome_highest = product;
                    cout << "i: " << i << "\t" << "j: " << j << endl;
                    cout << "Product: " << palindrome_highest << endl;
                }
                
            }
        }
    }
    return 0;
}

/*
# Optimal answer found through research


#include <iostream>
using namespace std;

// Helper function to check if a number is a palindrome
bool isPalindrome(int num) {
    int original = num;
    int reversed = 0;
    
    // Reverse the digits of the number
    while (num > 0) {
        int digit = num % 10;
        reversed = reversed * 10 + digit;
        num /= 10;
    }
    
    // Check if original number equals its reverse
    return original == reversed;
}

int main() {
    int max_palindrome = 0;
    int factor1 = 0, factor2 = 0;

    // Iterate over all pairs of 3-digit numbers starting from 999 downwards
    for (int i = 999; i >= 100; --i) {
        for (int j = i; j >= 100; --j) { // Start j from i to avoid duplicate pairs
            int product = i * j;

            // If product is less than current max_palindrome, break inner loop
            if (product <= max_palindrome) {
                break;
            }

            // Check if the product is a palindrome
            if (isPalindrome(product)) {
                max_palindrome = product;
                factor1 = i;
                factor2 = j;
            }
        }
    }

    // Output the result
    cout << "Largest palindrome: " << max_palindrome << endl;
    cout << "Factors: " << factor1 << " and " << factor2 << endl;

    return 0;
}

*/