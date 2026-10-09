#include<bits/stdc++.h>
using namespace std;


const int N = 1e6+10;
int a[N];
int tree[N];

int query( int idx ){
    int sum = 0;
    while ( idx > 0 ){
        sum += tree[idx];
        idx -= ( idx & -idx );
    }
    return sum;
}
int query( int l, int r ){
    return query(r)-query(l-1);
}
void update( int idx, int val, int n ){
    while ( idx <= n ){
        tree[idx] += val;
        idx += ( idx & -idx );
    }
}

int getmin( int idx ){
    // return the minimum from 1 to idx 
    // remember to set all the tree values to maximum before the buid
    int res = 1e9;
    while ( idx > 0 ){
        res = min( res, tree[idx] );
        idx -= ( idx & -idx ); 
    }
    return res;
}

int main(){
    a[0] = {0};
    a[1] = {1};
    a[2] = {2};
    a[3] = {3};
    a[4] = {4};
    a[5] = {5};
    // for ( int i = 1; i <= 5; i++ ) update(i,a[i],5);


    cout << query(1) << endl;
    cout << query(2) << endl;
    cout << query(2,5) << endl;

}