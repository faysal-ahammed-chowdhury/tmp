#include <iostream>
using namespace std;



int main(){

    int x = 1117;
    for (int i = 10; i >= 0; i--) {
        if (x&(1<<i)) cout << "1";
        else cout << "0";
    }   cout << endl;

    // sets the last one bit to zero (0)
    x = 1117;
    x &= (x-1);
    for (int i = 10; i >= 0; i--) {
        if (x&(1<<i)) cout << "1";
        else cout << "0";
    }   cout << endl;
    
    // sets all 1 bits to zero except the last one
    x = 1117;
    x &= -x;
    for (int i = 10; i >= 0; i--) {
        if (x&(1<<i)) cout << "1";
        else cout << "0";
    }   cout << endl;

    // inverts all the bits after last one bit
    x = 1024;
    x = x | (x-1);
    for (int i = 10; i >= 0; i--) {
        if (x&(1<<i)) cout << "1";
        else cout << "0";
    }   cout << endl;

}