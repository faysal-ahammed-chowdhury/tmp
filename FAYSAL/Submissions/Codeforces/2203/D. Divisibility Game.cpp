#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n, m; cin >> n >> m;
  int a[n + 1];
  int freq[n + m + 1];
  memset(freq, 0, sizeof freq);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    freq[a[i]]++;
  }

  int b[m + 1];
  for (int i = 1; i <= m; i++) {
    cin >> b[i];
  }

  int divs[n + m + 1];
  memset(divs, 0, sizeof divs);

  for (int i = 1; i <= n + m; i++) {
    if (freq[i] == 0) continue;
    for (int j = i; j <= (n + m); j += i) {
      divs[j] += freq[i];
    }
  }

  int alice = 0, common = 0, bob = 0;
  for (int i = 1; i <= m; i++) {
    if (divs[b[i]] == n) {
      alice++;
      continue;
    }

    if (divs[b[i]]) {
      common++;
    }
    else {
      bob++;
    }
  }

  int cnt1 = alice + ((common + 1) / 2);
  int cnt2 = bob + (common / 2);
  if (cnt1 > cnt2) cout << "Alice\n";
  else cout << "Bob\n";
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