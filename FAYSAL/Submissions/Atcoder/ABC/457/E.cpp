#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

const int N = 2e5 + 9, K = 20, inf = 1e9;
int mn[N], tree[N][K];

int log2_floor(unsigned long long i) {
  return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
}

void build(int n) {
  for (int i = 1; i <= n; i++) {
    tree[i][0] = mn[i];
  }
  for (int k = 1; k < K; k++) {
    for (int i = 1; i + (1 << k) - 1 <= n; i++) {
      tree[i][k] = min(tree[i][k - 1], tree[i + (1 << (k - 1))][k - 1]);
    }
  }
}

int query(int l, int r) {
  int k = log2_floor(r - l + 1);
  return min(tree[l][k], tree[r - (1 << k) + 1][k]);
}


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  vector<int> v[n + 1], v2[n + 1];
  for (int i = 1; i <= m; i++) {
    int l, r; cin >> l >> r;
    v[l].push_back(r);
    v2[r].push_back(-l);
  }

  for (int i = 1; i <= n; i++) {
    mn[i] = inf;
    sort(v[i].begin(), v[i].end());
    sort(v2[i].begin(), v2[i].end());

    if (v[i].size() >= 1) {
      mn[i] = v[i][0];
    }
  }

  build(n);

  // vector<int> vec;
  // auto it = upper_bound(vec.begin(), vec.end(), 4);
  // cout << (vec.end() == vec.begin()) << '\n';

  int q; cin >> q;
  while (q--) {
    int l, r; cin >> l >> r;
    auto it1 = upper_bound(v[l].begin(), v[l].end(), r);
    // cout << l << ' ' << r << '\n';

    if (v[l].begin() == v[l].end()) {
      cout << "No\n";
      continue;
    }


    if (it1 != v[l].begin()) {
      --it1;
      int right = *it1;

      if (right == r) {
        if (v[l].size() >= 2) {
          if (v[l][1] <= r or v[l][0] < r) {
            cout << "Yes\n";
            continue;
          }
        }

        if (l < r) {
          int here = query(l + 1, r);
          if (here <= r) {
            cout << "Yes\n";
            continue;
          }
        }

        cout << "No\n";
      }
      else {
        // cout << "here\n";
        auto it2 = upper_bound(v2[r].begin(), v2[r].end(), -l);
        if (v2[r].begin() == v2[r].end()) {
          cout << "No\n";
          continue;
        }

        if (it2 != v2[r].begin()) {
          --it2;
          int left = -(*it2);
        // cout << right << "here\n";

          if (left <= right or left - right == 1) {
            cout << "Yes\n";
          }
          else {
            cout << "No\n";
          }
        }
        else {
          cout << "No\n";
        }
      }
    }
    else {
      cout << "No\n";
    }
  }

  return 0;
}