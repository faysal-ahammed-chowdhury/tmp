#include <iostream>
using namespace std;

bool set( int num, int pos ){
    return (num & (1<<pos));
}

int main(){
    int num = 4, pos = 2;
    cout << set(num,pos);
}