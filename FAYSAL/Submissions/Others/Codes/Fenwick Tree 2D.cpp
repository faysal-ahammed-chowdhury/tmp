#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct FenwickTree2D {
  vector<vector<int>> bit;
  int n, m;

  FenwickTree2D(int n, int m) {
    this->n = n;
    this->m = m;
    bit.resize(n);
    for (int i = 0; i < n; i++) {
      bit[i].assign(m, 0);
    }
  }

  int sum(int x, int y) {
    int ret = 0;
    for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
      for (int j = y; j >= 0; j = (j & (j + 1)) - 1)
        ret += bit[i][j];
    return ret;
  }

  void add(int x, int y, int delta) {
    for (int i = x; i < n; i = i | (i + 1))
      for (int j = y; j < m; j = j | (j + 1))
        bit[i][j] += delta;
  }
};

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  return 0;
}