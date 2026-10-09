#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;

template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
  int n; cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  o_set<pair<int, int>> se;
  // se.insert({1, 1});
  // se.insert({1, 2});
  // cout << se.order_of_key({1, 0}) << '\n';

  int ans = 0;
  int extra = 0;
  for (int i = 1; i <= n; i++) {
    int idx = se.order_of_key({i, 1e9});
    ans = max(ans, (i - 1) - idx + extra + 1);
    // cout << (i - 1) - idx + extra << '\n';
    se.insert({a[i], i});
    extra += a[i] <= i;
  }

  cout << ans << '\n';
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