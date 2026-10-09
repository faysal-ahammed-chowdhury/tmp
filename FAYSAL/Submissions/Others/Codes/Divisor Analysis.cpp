#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long
 
const int N = 1e5 + 9;
const int mod = 1e9 + 7;
int p[N], k[N];
 
int get(int n) {
  return (n * (n + 1)) / 2;
}
 
int power(int x, long long n, int mod) {
  int ans = 1 % mod;
  while (n > 0) {
    if (n & 1) {
      ans = 1LL * ans * x % mod;
    }
    x = 1LL * x * x % mod;
    n >>= 1;
  }
  return ans;
}
 
struct ST {
  int tree[4 * N];
  void build(int n, int b, int e) {
    if (b == e) {
      tree[n] = k[b] + 1; 
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = (tree[l] * tree[r]) % (mod - 1); 
  }
  int query(int n, int b, int e, int i, int j) {
    if (b > j || e < i) return 1; 
    if (b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    int L = query(l, b, mid, i, j);
    int R = query(r, mid + 1, e, i, j);
    return (L * R) % (mod - 1);
  }
} st;
 
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
 
  int n; cin >> n;
  int pw = 1;
  int ans2 = 1;
  for (int i = 1; i <= n; i++) {
    cin >> p[i] >> k[i];
    pw *= (k[i] + 1);
    pw %= mod;
 
    int cur = power(p[i], (k[i] + 1), mod);
    cur --;
    if (cur < 0) cur += mod;
 
    cur = 1ll * cur * power(p[i] - 1, mod - 2, mod) % mod;
    ans2 = 1ll * ans2 * cur % mod;
  }
 
  st.build(1, 1, n);
  int ans = 1;
  for (int i = 1; i <= n; i++) {
    int x = p[i];
    int sum = get(k[i]);
    int here = power(x, sum, mod);
    int pw2 = (st.query(1, 1, n, 1, i - 1) * st.query(1, 1, n, i + 1, n)) % (mod - 1);
    // cout << pw2 << '\n';
    ans = 1ll * ans * power(here, pw2, mod) % mod;
  }
 
  cout << pw << ' ' << ans2 << ' ' << ans << '\n';
 
  return 0;
}