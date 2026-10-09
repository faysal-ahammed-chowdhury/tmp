#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
#define int long long

const int N = 2e5 + 9;
int n, a[N];
int pref[N];
int pref2[N];

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (i & 1) {
      pref[i] = pref[i - 1] + a[i];
      pref2[i] = pref2[i - 1];
    }
    else {
      pref[i] = pref[i - 1];
      pref2[i] = pref2[i - 1] + a[i];
    }
  }

  int ans = 0;
  o_set<pair<int, int>> se;
  for (int i = 1; i <= n; i += 2) {
    int x = pref[i] - pref2[i];
    ans += se.order_of_key({x - 1, 1e18});

    se.insert({pref[i - 1] - pref2[i - 1], i - 1});
  }

  for (int i = 1; i <= n; i++) {
    a[i] = a[i + 1];
  }
  n--;

  for (int i = 1; i <= n; i++) {
    if (i & 1) {
      pref[i] = pref[i - 1] + a[i];
      pref2[i] = pref2[i - 1];
    }
    else {
      pref[i] = pref[i - 1];
      pref2[i] = pref2[i - 1] + a[i];
    }
  }

  se.clear();
  for (int i = 1; i <= n; i += 2) {
    int x = pref[i] - pref2[i];
    ans += se.order_of_key({x - 1, 1e18});

    se.insert({pref[i - 1] - pref2[i - 1], i - 1});
  }

  cout << ans + n + 1 << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}