#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <cstdint>
using namespace std;

vector<int> thouDigitArray(){
    /*
    Here is where i will have to parse through a text file to generate the array
    containing the 1000 digits
    */
    ifstream inputFile("ThousandDigitNumber.txt");
    if (!inputFile.is_open()) {
        cerr << "Error: Could not open file!" << endl;
        return {};
    }

    vector<int> digits;
    char digit;

    while (inputFile.get(digit)){
        if (isdigit(digit)){
            digits.push_back(digit - '0');
        }
    }
        
    inputFile.close();
    return digits;
}

uint64_t largestProduct(){
    /*
    Here is where i will go through the array and search for the largest product of
    13 adjacent numbers
    - include logic for cases with "0"
    */
    vector<int> digits = thouDigitArray();

    if (digits.empty()){
        cerr << "Failed to read digits from the file" << endl;
    }

    uint64_t product = 1;
    uint64_t biggestProduct = 0;

    for (size_t i = 0; i < (digits.size() - 13); i++){
        for (size_t j = i; j < i + 13; j++){
            product = product * digits[j];
        }

        if (product > biggestProduct){
            biggestProduct = product;
        }
        product = 1;
    }
    return biggestProduct;

}

int main () {
    /*
    1. read from a csv or text file
    2. store it into an array
    3. go through array looking for the largest 13 product resulting in their product
      3i. if there is a skip the section and move away *13 spaces* (check exact math later)
    4. print result
    */
   cout << "The largest product is: " << largestProduct();
    
    return 0;
}