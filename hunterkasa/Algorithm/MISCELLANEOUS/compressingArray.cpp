set<int> st(a+1,a+1+n);
map<int,int> mp, mp1;
int cnt = 0;
for ( auto e : st ){
    if ( !mp.count(e) ){
        mp[e] = cnt;
        mp1[cnt] = e;
        cnt++;
    }
}
for ( int i = 1; i <= n; i++ ){
    a[i] = mp[a[i]];
}






    vll b(n); for ( int i = 0; i < n; i++ ) b[i] = a[i];
    int cnt = 0;
    map<int,int> mp, uncomp;
    sort(b.begin(), b.end());
    for ( int i = 0; i < n; i++ ) 
        if ( !mp.count(b[i]) ){
            mp[b[i]] = cnt;
            uncomp[cnt] = b[i];
            cnt++;
        } 
    for ( int i = 0; i < n; i++ ){
        a[i] = mp[a[i]];
    }
    for ( int i = 0; i < n; i++ ){
        cout << uncomp[a[i]] << ' ';
    }