#include <iostream>
using namespace std;

void multiby2( int &num ){
    num <<= 1;
}
void divideby2( int &num ){
    num >>= 1;
}

int main(){
    int num = 4;
    multiby2(num);
    cout << num << endl;
    divideby2(num);
    cout << num << endl;
}