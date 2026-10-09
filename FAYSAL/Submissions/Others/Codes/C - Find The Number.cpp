#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 120;
vector<bool> is_prime(N, true);
map<ll, int> mp;
vector<int> primes;

void sieve() {
  is_prime[1] = false;
  int lim = sqrt(N + 1);
  for (int i = 2; i <= lim; i++) {
    if (is_prime[i]) {
      for (int j = i + i; j < N; j += i) {
        is_prime[j] = false;
      }
    }
  }
}

int legendre(int n, int p) {
  int ex = 0;
  while(n) {
    ex += (n / p);
    n /= p;
  }
  return ex;
}

void prec() {
  for (int i = 1; i <= 110; i++) {
    int n = i;
    ll ans = 1;
    for (auto p : primes) {
      if (p > n) break;
      int pw = legendre(n, p);
      ans = 1ll * ans * (pw + 1);
    }

    if (mp.find(ans) == mp.end()) mp[ans] = n;
    else  mp[ans] = min(mp[ans], n);
  }
}

void solve() {
  ll n; cin >> n;
  if (mp.find(n) == mp.end()) {
    cout << "nai\n";
    return;
  }
  cout << mp[n] << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  sieve();

  for (int i = 2; i < N; i++) {
    if(is_prime[i]) primes.push_back(i);
  }

  prec();

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}