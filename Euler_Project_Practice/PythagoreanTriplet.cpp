#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <cstdint>
using namespace std;

bool isWholeSquareRoot(int num){
    if (num < 0){
        return false; //Can't have a negative square root
    }

    double sqrtValue = sqrt(num);
    return floor(sqrtValue) == sqrtValue; //Check if the floored sqrt value is the same as the one computed

}

int isTriplet (){

    int a, b, c, sum, product;
    for (int i = 10; i < 495; i++){
        a = i;
        for (int j = 495; j > 10; j--){
            b = j;
            c = pow(a, 2) + pow(b, 2);

            if(isWholeSquareRoot(c)){
            sum = a + b + sqrt(c);
                if (sum == 1000){
                    return a*b*(sqrt(c));
                }
            }
        }
    }

    return 0;
}

int main (){
    /*
    1. Find a pythagorean triplet a^2 + b^2 = c^2
    2. Test for this addition a + b + c = 1000
    3. Find product abc
    */
    cout << "The product of is: " << isTriplet() << endl;
    return 0;
}

/*

===Alternate way===

Mathemtical way to find triplets:

a = m^2 - n^2
b = 2mn
c = m^2 + n^2

Where:
m > n > 0
(m and n are coprime and m-n is odd)

Using a + b + c = 1000:

m^2 - n^2 + 2mn + m^2 + n^2 = 1000

This simplifies to:

m(m+n) = 500

Assuming n to be the smallest (n = 1) and the equation is now m(m+1) <= 500
it breaks down to a quadratic forumla with the upper limit being m = 22 therefore the loop will have to go until m < 22

calculating n is just a rearrangement of the m(m+n) = 500 equation:
n = (500/m) - m
k is used a place holder

if (500 % m == 0) { this ensure that n is an integer as well

----------------------------------------------------------------
#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    for (int m = 1; m < 22; ++m) { // Limit derived from solving m(m + n) <= 500
        if (500 % m == 0) {
            int k = 500 / m;
            int n = k - m;
            if (n > 0 && (m > n)) {
                a = m * m - n * n;
                b = 2 * m * n;
                c = m * m + n * n;
                cout << "The triplet is: (" << a << ", " << b << ", " << c << ")" << endl;
                cout << "The product is: " << a * b * c << endl;
                return 0;
            }
        }
    }
    return 0;
}

*/