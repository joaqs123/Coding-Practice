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