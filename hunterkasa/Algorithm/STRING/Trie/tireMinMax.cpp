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
        // freopen("output.txt","w",stdout);
    #endif
}
 
typedef vector<long long> vll;
typedef long long ll;
typedef long double ld;
#define int long long
 

struct trie {
    struct node{
        node *head[2];
        int cnt;
        node(){
            head[0] = head[1] = NULL;
            cnt = 0;
        }
    } *root;

    trie(){ root = new node(); }
    ~trie() { del(root); }
    
    void insert( int val ){
        node *cur = root;
        for ( int i = 30; i >= 0; i-- ){
            int x = (( val >> i ) & 1);
            if ( cur->head[x] == NULL ) cur->head[x] = new node();
            cur = cur->head[x];
            cur->cnt++;
        }
    }
    
    void erase( int val ){
        node *cur = root;
        for ( int i = 30; i >= 0; i-- ){
            int x = ( (val >> i) & 1 );
            cur = cur->head[x];
            cur->cnt--;
        }
    }
    
    int query_min( int val ){
        node *cur = root;
        int sum = 0;
        for ( int i = 30; i >= 0; i-- ){
            int x = (val >> i) & 1;
            if ( cur->head[x] != NULL && cur->head[x]->cnt > 0   ){
                cur = cur->head[x];
            } else {
                cur = cur->head[x^1];
                sum |= (1<<i);
            }
        }
        return sum;
    }

    int query_max( int val ){
        node *cur = root;
        int sum = 0;
        for ( int i = 30; i >= 0; i-- ){
            int x = ((val >> i) & 1) ^ 1;
            if ( cur->head[x] != NULL && cur->head[x]->cnt > 0 ){
                cur = cur->head[x];
                sum |= (1<<i);
            } else {
                cur = cur->head[x^1];
            }
        }
        return sum;
    }

    void del( node *cur ){
        if ( cur->head[0] ) del(cur->head[0]);
        if ( cur->head[1] ) del(cur->head[1]);
        delete(cur);
    }
    
} t;

int rec( vector<int> &a, int d ){
    
    if ( a.empty() || d < 0 ) return 0;
    
    vector<int> l,r;
    for ( auto c : a ){
        if ( c & ( 1 << d ) ) l.push_back(c);
        else r.push_back(c);
    }

    int ans = INT_MAX;
    for ( auto c : r ) t.insert(c);
    for ( auto c : l ) ans = min ( ans, t.query_min(c) );
    for ( auto c : r ) t.erase(c);

    if ( ans == INT_MAX ) ans = 0;

    return ans + rec( l, d-1 ) + rec( r, d-1 );

}

void samekoSaba(){

    int n; cin >> n;
    vector<int> a(n); for ( int i = 0; i < n; i++ ) cin >> a[i];

    t.insert(0);

    cout << rec( a, 30 ) << endl;

}


 
signed main(){
    Wah();
    int tt = 1;
    // cin >> tt;
    while ( tt-- > 0 ){
        samekoSaba();
    }      
    return 0;
}