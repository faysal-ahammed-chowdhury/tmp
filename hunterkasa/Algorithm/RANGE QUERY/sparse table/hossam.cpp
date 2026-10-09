const int N = 3e5 + 5;
const int LOG = 20;

int n;
int a[N];
int LG[N + 1];             
int sparse[LOG][N];        

void build_sparse() {
    LG[1] = 0;
    for (int i = 2; i <= n; ++i)
        LG[i] = LG[i / 2] + 1;
        
    for (int i = 1; i <= n; ++i)
        sparse[0][i] = a[i];
        
    for (int lg = 1; (1 << lg) <= n; ++lg) {
        for (int i = 1; i + (1 << lg) - 1 <= n; ++i) {
            int left = sparse[lg - 1][i];
            int right = sparse[lg - 1][i + (1 << (lg - 1))];
            sparse[lg][i] = min(left, right);
        }
    }
}

int query(int l, int r) {
    if (l > r) swap(l, r);
    int len = r - l + 1;
    int lg = LG[len];
    int left = sparse[lg][l];
    int right = sparse[lg][r - (1 << lg) + 1]; 
    return min(left, right);
}