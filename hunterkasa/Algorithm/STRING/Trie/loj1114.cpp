#include <bits/stdc++.h>
using namespace std;
 
#ifndef ONLINE_JUDGE
    #include "template.cpp"
#else
    #define debug(...)
    #define debugArr(arr, n)
#endif

#define io              ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl            '\n'

void fast(){
    io;
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    #endif
}
 
typedef long long ll;
typedef long double ld;
// #define int long long



map<char,int> mp;
void pre(){
    for ( char c = 'a'; c <= 'z'; c++ ) mp[c] = c-'a';
    for ( char c = 'A'; c <= 'Z'; c++ ) mp[c] = c-'A'+26;
}

struct node{
    node *head[60];
    int cnt = 0;
    node(){
        for ( int i = 0; i < 60; i++ ) head[i] = NULL;
        cnt = 0;
    }
};

void insert( node *root, string &s ){
    node *cur = root;
    for ( auto &c : s ){
        int x = mp[c];
        if ( cur->head[x] == NULL ) cur->head[x] = new node();
        cur = cur->head[x];
    }
    cur->cnt++;
}

void deleteNode(node *root){
    for ( int i = 0; i < 60; i++ ){
        if ( root->head[i] != NULL ){
            deleteNode(root->head[i]);
        }
    }
    delete(root);
}

int travarse(node *root, string &s){
    node *cur = root;
    for ( auto &c : s ){
        int x = mp[c];
        if ( cur->head[x] == NULL ) return 0;
        cur = cur->head[x];
    }
    return cur->cnt;
}

void tohka(){

    node *root = new node();
    
    int n;  cin >> n;
    for ( int i = 0; i < n; i++ ){
        string s;   cin >> s;
        if ( s.size() > 2 ) sort(s.begin()+1, s.end()-1);
        insert(root, s);
    }

    int q;  cin >> q;
    getchar();
    while ( q-- ){
        string s;   getline(cin,s);
        s.push_back(' ');
        string t = "";
        ll ans = 1;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] != ' ') t.push_back(s[i]);
            else 
            {
                if(t.size() > 2)
                sort(t.begin()+1,t.end()-1);

                if(t.size() == 0) continue;

                ans *= travarse(root,t);
                t.clear();
            }
        }
        cout << ans << endl;
    }

    deleteNode(root);

}

signed main(){
    pre();
    // fast();
    int tt = 1;
    cin >> tt;
    int i = 1;
    while ( tt-- > 0 ){
        cout << "Case " << i++ << ":\n";
        tohka();
    }      
    return 0;
}   