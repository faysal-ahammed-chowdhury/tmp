#include <iostream>
using namespace std;

void set( int &num, int pos ){
    num &= (~(1<<pos));
}

int main(){
    int num = 7, pos = 1;
    set(num,pos);
    cout << num << endl;
}