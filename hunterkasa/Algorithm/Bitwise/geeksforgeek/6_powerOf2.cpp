#include <iostream>
using namespace std;

bool isPowerOf2(int n){return (n&&!(n&n-1));}

int main(){
    int num = 512;
    
    cout << isPowerOf2(num) << endl;
}