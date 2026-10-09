#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll

bool CHECK(ll N, int pos) { return (bool)(N & (1ll << pos)); }
void SET(ll &N, int pos) { (N |= (1ll << pos)); }
void CLR(ll &N, int pos) { (N &= ~(1ll << pos)); }

const int N = 1e5 + 9, mod = 1e9 + 7;
int n, a[N];

using Matrix = array<array<int, 2>, 2>;
Matrix matrix_mul(Matrix &A, Matrix &B, int M_sz) {
  Matrix res = {};
  for (int i = 0; i < M_sz; i++) {
    for (int j = 0; j < M_sz; j++) {
      for (int k = 0; k < M_sz; k++) {
        res[i][j] = (res[i][j] + ((A[i][k] * B[k][j]) % mod)) % mod;
      }
    }
  }
  return res;
}
Matrix matrix_pow(Matrix mat, int n, int M_sz) {
  Matrix res = {};
  for (int i = 0; i < M_sz; i++) {res[i][i] = 1;}
  while (n) {
    if (n & 1) {res = matrix_mul(res, mat, M_sz);}
    if (n > 0) {mat = matrix_mul(mat, mat, M_sz);}
    n >>= 1;
  }
  return res;
}

Matrix power_val[53];
void prec() {
  for (int k = 0; k <= 50; k++) {
    if (k == 0) {
      power_val[k] = {{
          {0, 1},
          {1, 1}
        }
      };
    }
    else {
      power_val[k] = matrix_mul(power_val[k - 1], power_val[k - 1], 2);
    }
  }
}

pair<int, int> calc(int x, int y, ll n) {
  if (n == 0) return {x, y};
  if (n == 1) return {y, (x  + y) % mod};
  if (n == 2) return {(x  + y) % mod, (x  + ((y + y) % mod)) % mod};

  ll pw = n - 2;
  Matrix B = {
    {
      {1, 1},
    }
  };
  // for (int k = __lg(pw); k >= 0; k--) {
  //   if (CHECK(pw, k)) {
  //     B = B * power_val[k];
  //   }
  // }

  while (pw > 0) {
    int msb = __lg(pw);
    pw -= (1ll << msb);
    B = matrix_mul(B, power_val[msb], 2);
  }

  int xx = 1ll * y * B[0][1] % mod;
  xx = (xx + (1ll * x * B[0][0] % mod)) % mod;

  B = matrix_mul(B, power_val[0], 2);
  int yy = 1ll * y * B[0][1] % mod;
  yy = (yy + (1ll * x * B[0][0] % mod)) % mod;

  return {xx, yy};
}

struct ST {
  int tree1[4 * N], tree2[4 * N];
  ll lazy[4 * N];
  void push(int n, int b, int e) {
    if (lazy[n] == 0) return;
    auto [x, y] = calc(tree1[n], tree2[n], lazy[n]);
    tree1[n] = x;
    tree2[n] = y;

    if (b != e) {
      int l = n << 1, r = l + 1;
      lazy[l] += lazy[n];
      lazy[r] += lazy[n];
    }
    lazy[n] = 0;
  }
  void build(int n, int  b, int e) {
    lazy[n] = 0;
    if (b == e) {
      auto [x, y] = calc(1, 1, a[b] - 1);
      tree1[n] = x;
      tree2[n] = y;
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree1[n] = (tree1[l] + tree1[r]) % mod;
    tree2[n] = (tree2[l] + tree2[r]) % mod;
  }
  void upd(int n, int b, int e, int i, int j, int x) {
    push(n, b, e);
    if (b > j || e < i) return;
    if (b >= i && e <= j) {
      lazy[n] += x;
      push(n, b, e);
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd(l, b, mid, i, j, x);
    upd(r, mid + 1, e, i, j, x);
    tree1[n] = (tree1[l] + tree1[r]) % mod;
    tree2[n] = (tree2[l] + tree2[r]) % mod;
  }
  int query(int n, int b, int e, int i, int j) {
    push(n, b, e);
    if (b > j || e < i) return 0;
    if (b >= i && e <= j) return tree1[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    int L = query(l, b, mid, i, j);
    int R = query(r, mid + 1, e, i, j);
    return (L + R) % mod;
  }
} st;


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  prec();

  int m; cin >> n >> m;

  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  st.build(1, 1, n);

  while (m--) {
    int type, l, r; cin >> type >> l >> r;
    if (type == 1) {
      int x; cin >> x;
      st.upd(1, 1, n, l, r, x);
    }
    else {
      cout << st.query(1, 1, n, l, r) << '\n';
    }
  }

  return 0;
}