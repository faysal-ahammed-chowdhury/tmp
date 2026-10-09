const int N = 5e5;
int par[N];
int sz[N];

void make(){
    for ( int i = 0; i < N; i++ ){
        par[i] = i;
        sz[i] = 1;
    }
}

int find( int x ){
    if ( x == par[x] )  return x;
    return par[x] = find(par[x]);
} 

void Union( int a, int b ){
    a = find(a);
    b = find(b);

    if ( a != b ){
        if ( sz[a] < sz[b] )    swap(a,b);

        par[b] = a;
        sz[a] += sz[b];
    }
}