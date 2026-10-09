#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll

struct FenwickTree {
  vector<int> bit;
  int n;

  FenwickTree(int n) {
    this->n = n;
    bit.assign(n, 0);
  }

  FenwickTree(vector<int> const &a) : FenwickTree(a.size()) {
    for (int i = 0; i < n; i++) {
      bit[i] += a[i];
      int r = i | (i + 1);
      if (r < n) bit[r] += bit[i];
    }
  }

  int sum(int r) {
    int ret = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1) {
      ret += bit[r];
    }
    return ret;
  }

  int sum(int l, int r) {
    if (l > r) return 0;
    return sum(r) - sum(l - 1);
  }

  void add(int idx, int delta) {
    for (; idx < n; idx = idx | (idx + 1)) {
      bit[idx] += delta;
    }
  }
};




void solve() {
  int n, q; cin >> n >> q;
  vector<int> divs;
  for (int i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      divs.push_back(i);
      if (i != (n / i)) {
        divs.push_back(n / i);
      }
    }
  }

  sort(divs.begin(), divs.end());
  vector<int> a, divs2(divs);
  reverse(divs2.begin(), divs2.end());
  int last = 0;
  for (auto d : divs) {
    int x = n / d;
    a.push_back(x * (d - last));
    last = d;
  }

  FenwickTree ft(a);
  while (q--) {
    int x, y; cin >> x >> y;

    int l = 0, r = a.size() - 1, here = r;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (divs2[mid] >= y) {
        here = mid;
        l = mid + 1;
      }
      else {
        r = mid - 1;
      }
    }

    int tmp = divs[here];

    auto idx = upper_bound(divs.begin(), divs.end(), x) - divs.begin() - 1;
    int val = divs[idx];
    int ans = (min(tmp, val) * y) + ft.sum(here + 1, idx);
    if (x > val) {
      int nxt = divs[idx + 1];
      int op = n / nxt;
      ans += (x - val) * min(op, y);
    }
    cout << ans << '\n';
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}