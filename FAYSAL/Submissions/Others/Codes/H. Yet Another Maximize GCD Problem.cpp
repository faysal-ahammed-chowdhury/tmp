#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

const int N = 1e5 + 9, MAXV = 1e6 + 9;
int n, k, a[N];
int spf[MAXV];
map<int, vector<int>> mp;
map<int, int> mp2;
vector<int> v;
map<array<int, 2>, int> dp;

void spf_sieve() {
  for (int i = 2; i < MAXV; i++) {
    spf[i] = i;
  }
  for (int i = 2; i < MAXV; i++) {
    if (spf[i] == i) {
      for (int j = i; j < MAXV; j += i) {
        spf[j] = min(spf[j], i);
      }
    }
  }
}

int f(int i, int baki) {
  if (baki < 0) return 0;
  if (i < 0) return 1;

  if (dp.count({i, baki})) return dp[ {i, baki}];

  int p = v[i];
  int pp = v[i];
  int avg = mp2[p] / n;

  int ans = f(i - 1, baki);
  int need = 0;
  for (int cnt = 1; cnt <= avg; cnt++) {
    need += lower_bound(mp[p].begin(), mp[p].end(), cnt) - mp[p].begin() + (n - mp[p].size());
    // cout << p << ' ' << pp << ' ' << avg << ' ' << need << '\n';
    ans = max(ans, pp * f(i - 1, baki - need));
    pp *= p;
  }
  return dp[ {i, baki}] = ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  spf_sieve();

  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    int x = a[i];
    while (x > 1) {
      int p = spf[x], pw = 0;
      while (x % p == 0) {
        pw++;
        x /= p;
      }
      mp2[p] += pw;
      mp[p].push_back(pw);
    }
  }

  for (auto [p, cnt] : mp2) {
    int avg = cnt / n;
    if (avg) {
      v.push_back(p);
      sort(mp[p].begin(), mp[p].end());
    }
    else {
      mp.erase(p);
    }
  }


  // for (auto x : mp[2]) {
  //   cout << x << ' ';
  // }
  // cout << '\n';

  // cout << lower_bound(mp[2].begin(), mp[2].end(), 2) - mp[2].begin() << '\n';
  // return 0;


  int here = v.size();
  here--;

  // cout << f(here, 1) << '\n';
  // return 0;
  for (int i = 1; i <= k; i++) {
    cout << f(here, i) << ' ';
  }
  cout << '\n';

  return 0;
}