const int N = 2e5+10;
struct ST {
    int t[4 * N]{};
    ST() {
        memset(t, 0, sizeof t);
    }
    void build(int n, int b, int e) {
        if (b == e) {
            t[n] = 0; ///////////
            return;
        }
        int mid = (b + e) >> 1, l = n << 1, r = l | 1;
        build(l, b, mid);
        build(r, mid + 1, e);
        t[n] = (t[l] + t[r]); ///////////
    }
    void upd(int n, int b, int e, int i, int x) {
        if (b > i || e < i) return;
        if (b == e && b == i) {
            t[n] = x; ///////////
            return;
        }
        int mid = (b + e) >> 1, l = n << 1, r = l | 1;
        upd(l, b, mid, i, x);
        upd(r, mid + 1, e, i, x);
        t[n] = (t[l] + t[r]); ///////////
    }
    int query(int n, int b, int e, int i, int j) {
        if (b > j || e < i) return 0.0; /////////////
        if (b >= i && e <= j) return t[n];
        int mid = (b + e) >> 1, l = n << 1, r = l | 1;
        int L = query(l, b, mid, i, j);
        int R = query(r, mid + 1, e, i, j);
        return (L + R); ///////////////
    }
}st;