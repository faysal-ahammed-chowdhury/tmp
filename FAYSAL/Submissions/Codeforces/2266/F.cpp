#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define int ll

struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    // http://xorshift.di.unimi.it/splitmix64.c
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 31)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }

  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};

const int N = 2e5 + 9;
int n, x[N], y[N];
gp_hash_table<int, int, custom_hash> freq;
vector<int> v;

bool ok(int banabo) {
  gp_hash_table<int, int, custom_hash> freq2;
  freq2 = freq;
  int sz = v.size();
  int last = banabo;
  __int128 add = 1;
  for (int i = sz - 1; i >= 0; i--) {
    if (add > 1e15) return false;
    int val = v[i];
    int d = last - val - 1;
    if (d > 50) return false;
    int pw = (1ll << d) - 1;

    add += (add * pw);

    int ase = freq2[val];
    if (ase < add) {
      if (i == 0) return false;
      add += add - ase;
    }
    else if (ase > add) {
      freq2[0] += ase - add;
    }

    last = val;
  }

  return true;
}

void solve() {
  v.clear();
  freq.clear();
  cin >> n;
  int ans = 0;
  bool zero_exist = false;
  for (int i = 1; i <= n; i++) {
    cin >> x[i] >> y[i];
    ans = max(ans, x[i]);
    freq[x[i]] = y[i];
    v.push_back(x[i]);
    if (x[i] == 0) zero_exist = true;
  }

  if (!zero_exist) v.push_back(0);
  sort(v.begin(), v.end());

  int mx = ans;
  for (int i = mx + 50; i > mx; i--) {
    if (ok(i)) {
      ans = max(ans, i);
      break;
    }
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