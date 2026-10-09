#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e6 + 10;
int a[N];
int n;
int jabo[N];

struct ST2 {
  int tree[N * 4], lazy[N * 4];
  void push( int n, int b, int e ) {
    if ( lazy[n] == -1 ) return;
    tree[n] = lazy[n] * (e - b + 1); /////////////
    if ( b != e ) {
      int l = n << 1, r = l + 1;
      lazy[l] = lazy[n];
      lazy[r] = lazy[n];
    }
    lazy[n] = -1;
  }
  void build( int n, int b, int e ) {
    lazy[n] = -1;
    if ( b == e ) {
      tree[n] = 0; //////////////////
      return;
    }
    int mid = ( b + e ) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = tree[l] + tree[r]; //////////////
  }
  void upd( int n, int b, int e, int i, int j, int x ) {
    push(n, b, e);
    if ( b > j || e < i ) return;
    if ( b >= i && e <= j ) {
      lazy[n] = x; /////////////////
      push(n, b, e);
      return;
    }
    int mid = ( b + e ) >> 1, l = n << 1, r = l + 1;
    upd(l, b, mid, i, j, x);
    upd(r, mid + 1, e, i, j, x);
    tree[n] = tree[l] + tree[r]; //////////////
  }
  int query( int n, int b, int e, int i, int j ) {
    push(n, b, e);
    if ( b > j || e < i ) return 0; ///////////
    if ( b >= i && e <= j ) return tree[n];
    int mid = ( b + e ) >> 1, l = n << 1, r = l + 1;
    int L = query(l, b, mid, i, j);
    int R = query(r, mid + 1, e, i, j);
    return  L + R ; ///////////////
  }
} st2;

struct ST {
  int tree[N * 4], lazy[N * 4];
  void build( int n, int b, int e ) {
    lazy[n] = 0;
    if ( b == e ) {
      tree[n] = a[b]; //////////////////
      return;
    }
    int mid = ( b + e ) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = max(tree[l], tree[r]); //////////////
  }
  int getLast( int n, int b, int e, int i, int j, int x ) { // return index
    if ( b > j || e < i ) return -1;
    if ( tree[n] <= x ) return -1;
    if ( b == e ) return b;
    int mid = ( b + e ) >> 1, l = n << 1, r = l + 1;
    int left = getLast(r, mid + 1, e, i, j, x);
    if ( left != -1 ) return left;
    return getLast(l, b, mid, i, j, x);
  }
} st;

void solve( int TEST ) {

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  for (int i = 1; i <= n; i++) {
    jabo[i] = min(i, a[i]);
  }

  int ans = 0;

  st.build(1, 1, n);
  st2.build(1, 1, n);
  for (int  r  = 1; r <= n; r++) {
    int l = st.getLast(1, 1, n, 1, r, r);
    if (l == -1) l = 1;
    else l++;

    int go = jabo[r];

    st2.upd(1, 1, n, go + 1, r, 0);
    if (go == r) st2.upd(1, 1, n, r, r, 1);

    int  x = st2.query(1, 1, n, l, r);
    ans += x;
  }

  cout << ans << '\n';
}

signed main() {
  ios_base::sync_with_stdio(0); cin.tie(0);

  int tt = 1;
  cin >> tt;

  for ( int i = 1; i <= tt; i++ ) {
    solve(i);
  }
  return 0;
}