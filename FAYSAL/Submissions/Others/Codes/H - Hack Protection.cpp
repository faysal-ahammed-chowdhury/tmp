#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

const int N = 1e5 + 9, K = 20, MAXV = 2147483647;
int n, a[N], tree[N][K], pref[N], pref2[N];

int log2_floor(unsigned long long i) {
  return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
}

void build(int n) {
  for (int i = 1; i <= n; i++) {
    tree[i][0] = a[i];
  }
  for (int k = 1; k < K; k++) {
    for (int i = 1; i + (1 << k) - 1 <= n; i++) {
      tree[i][k] = (tree[i][k - 1] & tree[i + (1 << (k - 1))][k - 1]);
    }
  }
}

int query(int l, int r) {
  int k = log2_floor(r - l + 1);
  return (tree[l][k] & tree[r - (1 << k) + 1][k]);
}

struct wavelet_tree {
  int low, high;
  wavelet_tree *lft = NULL, *rgt = NULL;
  int *pref = NULL;

  wavelet_tree(int *l, int *r, int low, int high): low(low), high(high) {
    if (l >= r || low >= high) return;
    pref = new int[r - l + 2];
    pref[0] = 0;
    int mid = (low + high) >> 1, cnt = 1;
    for (int *i = l; i != r; i++, cnt++) {
      pref[cnt] = pref[cnt - 1] + ((*i) <= mid);
    }
    int *pivot = stable_partition(l, r, [&](int x) {return x <= mid;});
    lft = new wavelet_tree(l, pivot, low, mid);
    rgt = new wavelet_tree(pivot, r, mid + 1, high);
  }
  // count occurences of 'k' in range [l,r]
  int count(int l, int r, int k) {
    if (l > r || high < k || low > k) return 0;
    if (low == high) return r - l + 1;
    int mid = (low + high) >> 1;
    if (k <= mid) return lft->count(pref[l - 1] + 1, pref[r], k);
    return rgt->count(l - pref[l - 1], r - pref[r], k);
  }
  ~wavelet_tree() {
    if (pref != NULL) delete []pref;
    if (lft != NULL) delete lft;
    if (rgt != NULL) delete rgt;
  }
};

int32_t main() {
  freopen("hack.in","r",stdin);
  freopen("hack.out","w",stdout);
 
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    pref[i + 1] = pref[i] ^ a[i];
    pref2[i] = pref[i + 1];
  }

  build(n);
  wavelet_tree wt(pref + 1, pref + n + 2, 0, MAXV);

  ll ans = 0;
  for (int r = 1; r <= n; r++) {
    int last = r;
    while (last >= 1) {
      int lo = 1, hi = last, left = last;
      while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (query(mid, r) == query(last, r)) {
          left = mid;
          hi = mid - 1;
        }
        else lo = mid + 1;
      }

      int nd = query(left, r);
      ans += wt.count(left, last, (pref2[r] ^ nd));

      last = left - 1;
     }
  }

  cout << ans << '\n';

  return 0;
}