#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define int long long

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

const int N = 3e5 + 9;
int n, k, x;
int a[N];
int pref[N], pref0[N], pref2[N];
int pref3[N];

void solve() {
  cin >> n >> k >> x;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] == x) a[i] = 0;
    else if (a[i] < x) a[i] = -1;
    else a[i] = 1;

    pref[i] = pref[i - 1] + a[i];
    pref0[i] = pref0[i - 1] + (a[i] == 0);

    pref2[i] = pref2[i - 1] + (a[i] == 1 ? +1 : -1);
    pref3[i] = pref3[i - 1] + (a[i] == -1 ? +1 : -1);
  }

  gp_hash_table<int, int, custom_hash> mp1, mp2;
  for (int r = 1; r <= n; r++) {
    if (pref0[r] >= pref[r] and pref[r] >= 0 and r >= k and pref0[r] > 0) {
      cout << "Yes\n";
      return;
    }

    if (pref[r] < 0) {
      if (mp1.find(pref[r]) != mp1.end()) {
        int l = mp1[pref[r]];
        if (r - l >= k and (pref0[r] - pref0[l]) > 0) {
          cout << "Yes\n";
          return;
        }
      }
    }
    else {
      int need = pref[r] - pref0[r];
      if (mp2.find(need) != mp2.end()) {
        int l = mp2[need];
        if (r - l >= k and (pref0[r] - pref0[l]) > 0) {
          cout << "Yes\n";
          return;
        }
      }
    }

    if (mp1.find(pref[r]) == mp1.end()) mp1[pref[r]] = r;
    if (mp2.find(pref2[r]) == mp2.end()) mp2[pref2[r]] = r;
  }

  // return;

  mp1.clear(), mp2.clear();
  for (int r = 1; r <= n; r++) {
    pref[r] = -pref[r];
    if (pref0[r] > pref[r] and pref[r] >= 0 and r >= k and pref0[r] > 0) {
      cout << "Yes\n";
      return;
    }

    if (pref[r] < 0) {
      if (mp1.find(pref[r]) != mp1.end()) {
        int l = mp1[pref[r]];
        if (r - l >= k and (pref0[r] - pref0[l]) > 0) {
          cout << "Yes\n";
          return;
        }
      }
    }
    else {
      int need = pref[r] - pref0[r] + 1;
      if (mp2.find(need) != mp2.end()) {
        int l = mp2[need];
        if (r - l >= k and (pref0[r] - pref0[l]) > 0) {
          cout << "Yes\n";
          return;
        }
      }
    }

    if (mp1.find(pref[r]) == mp1.end()) mp1[pref[r]] = r;
    if (mp2.find(pref3[r]) == mp2.end()) mp2[pref3[r]] = r;
  }

  cout << "No\n";
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