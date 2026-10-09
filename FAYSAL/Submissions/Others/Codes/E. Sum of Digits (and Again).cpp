#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;

struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    // http://xorshift.di.unimi.it/splitmix64.c
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }

  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};

bool ok(int x, gp_hash_table<int, int, custom_hash> &mp2) {
  if (x <= 9) {
    mp2[x]--;
    return mp2[x] >= 0;
  }
  int sum = 0;
  bool flag = true;
  while (x > 0) {
    int last = x % 10;
    x /= 10;
    sum += last;
    mp2[last]--;
    flag &= mp2[last] >= 0;
  }
  return (flag and ok(sum, mp2));
}

void print(int x) {
  cout << x;
  if (x <= 9) return;
  int sum = 0;
  while (x > 0) {
    int last = x % 10;
    x /= 10;
    sum += last;
  }
  print(sum);
}

void solve() {
  string s; cin >> s;
  int n = s.size();

  if (n == 1) {
    cout << s << '\n';
    return;
  }

  gp_hash_table<int, int, custom_hash> mp;
  for (auto c : s) {
    int x = c - '0';
    mp[x]++;
  }

  for (int x = 1; x <= 9 * n; x++) {
    gp_hash_table<int, int, custom_hash> mp2 = mp;
    if (ok(x, mp2)) {
      int here = 0;
      for (auto [y, cnt] : mp2) {
        here += y * cnt;
      }
      if (here == x) {
        string ans = "", zero = "";
        for (auto [y, cnt] : mp2) {
          for (int j = 1; j <= cnt; j++) {
            if (y == 0) zero += '0';
            else ans += char(y + '0');
          }
        }
        cout << ans << zero;
        print(x);
        cout << '\n';
        return;
      }
    }
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