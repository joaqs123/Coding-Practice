#include <iostream>
using namespace std;

int main() {
    int sum = 0;
    int t1 = 1;
    int t2 = 1;
    int next = 0;
    while(t2 < 4000000){
        next = t1 + t2;
        if (t2 % 2 == 0) sum += t2;
        t1 = t2;
        t2 = next;
    }
    cout << "Final Sum: " << sum << endl;
}