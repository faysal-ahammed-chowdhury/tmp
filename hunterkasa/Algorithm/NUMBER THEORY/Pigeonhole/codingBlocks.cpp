// https://www.youtube.com/watch?v=p5Cm_r4T1Rw&ab_channel=CodingBlocks
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int pre[N], a[N];


void pigeon(){
    long long n;  cin >> n;
    memset(pre, 0, sizeof(pre));
    
    pre[0] = 1;
    long long sum = 0;
    for ( long long i = 0; i < n; i++ ){
        cin >> a[i];
        sum += a[i];
        sum %= n;
        sum = (sum+n)%n;
        pre[sum]++;
    }
    long long ans = 0;
    for ( long long i = 0; i < n; i++ ){
        long long m = pre[i];
        ans += m*(m-1)/2;
    }

    cout << ans << endl;
}

int main(){
    int t = 1 ;
    cin >> t;
    while ( t-- ){
        pigeon();
    }
}