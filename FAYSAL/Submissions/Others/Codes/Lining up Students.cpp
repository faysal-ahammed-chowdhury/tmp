#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;

template <typename T> using o_set = tree<T, null_type, greater<T>, rb_tree_tag, tree_order_statistics_node_update>;

int cs;
void solve() {
  int n; cin >> n;
  int a[n + 1];
  o_set<int> se;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    se.insert(i);
  }

  vector<int> ans;
  for (int i = n; i >= 1; i--) {
    auto it = se.find_by_order(a[i]);
    ans.push_back(*it);
    se.erase(it);
    // cout << *it << ' ';
  }


  cout << "Case " << ++cs << ": " << ans.back() << '\n';
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