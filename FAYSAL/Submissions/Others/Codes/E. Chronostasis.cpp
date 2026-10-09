#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T> using o_set = tree<T, null_type, greater<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef long long ll;
#define int ll

void solve() {
  int n; cin >> n;
  vector<int> v;
  int cnt0 = 0;
  o_set<pair<int, int>> se;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    if (x == 0) cnt0++;
    else if (x > 0) v.push_back(x);
    else se.insert({abs(x), i});
  }

  sort(v.rbegin(), v.rend());
  if (v.size() == 0) {
    cout << -1 << '\n';
    return;
  }

  int cur = v.back();
  v.pop_back();
  vector<int> ans;
  ans.push_back(cur);

  while (true) {
    int mx = cur - 1;
    int idx = se.order_of_key(make_pair(mx, n + 1));
    if (idx == se.size()) {
      if (cnt0 > 0) {
        ans.push_back(cur);
        cnt0--;
        continue;
      }

      if (v.empty()) break;
      cur += v.back();
      v.pop_back();
      ans.push_back(cur);
      continue;
    }

    auto it = se.find_by_order(idx);
    int val = (*it).first;
    cur -= val;
    ans.push_back(cur);
    se.erase(it);
  }

  if (ans.size() != n) {
    cout << -1 << '\n';
    return;
  }

  for (auto x : ans) {
    cout << x << ' ';
  }
  cout << '\n';
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