#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
    #include "template.cpp"
#else
    #define debug(...)
    #define debuga(a, n)
#endif
 
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); 
#define endl '\n'
 
void Wah(){
    io;
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        // freqopen("output.txt","w",stdout);
    #endif
}
 
typedef vector<long long> vll;
typedef long long ll;
typedef long double ld;
// #define int long long
 





struct node{
    node *head[2];
    node(){
        head[0] = head[1] = NULL;
    }
};

void insert( node *root, int val ){
    node *cur = root;
    for ( int i = 30; i >= 0; i-- ){
        int x = (((1<<i)&val) ? 1 : 0);
        if ( cur->head[x] == NULL ) cur->head[x] = new node();
        cur = cur->head[x];
    }
}

int findMax( node *root, int val ){
    node *cur = root;
    int ans = 0;
    for ( int i = 30; i >= 0; i-- ){
        int x = ((((1<<i)&val) ? 1 : 0) ^ 1);

        if ( cur->head[x] == NULL ){
            x ^= 1;
        } else {
            ans |= (1<<i);
        }
        cur = cur->head[x];
    }
    return ans;
}
int findMin( node *root, int val ){
    node *cur = root;
    int ans = 0;
    for ( int i = 30; i >= 0; i-- ){
        int x = (((1<<i)&val) ? 1 : 0);

        if ( cur->head[x] == NULL ){
            x ^= 1;
            ans |= (1<<i);
        } 
        cur = cur->head[x];
    }
    return ans;
}

void deleteNode(node *root){
    for ( int i = 0; i < 2; i++ ){
        if ( root->head[i] != NULL ){
            deleteNode(root->head[i]);
        }
    }
    delete(root);
}

void AmeDoko(){

    node *root = new node();
    insert(root,0);

    int n; cin >> n;
    int b = INT_MAX, a = INT_MIN;
    int cur = 0;
    for ( int i = 0; i < n; i++ ){
        int x; cin >> x;
        cur ^= x;
        a = max(findMax(root,cur), a);
        b = min(findMin(root,cur), b);
        insert(root,cur);
    }

    cout << a << ' ' << b << endl;

    deleteNode(root);

}   
 
signed main(){
    Wah();
    int tt = 1;
    cin >> tt;
    int i = 1;
    while ( tt-- > 0 ){
        cout << "Case " << i++ << ": ";
        AmeDoko();
    }      
    return 0;
}         