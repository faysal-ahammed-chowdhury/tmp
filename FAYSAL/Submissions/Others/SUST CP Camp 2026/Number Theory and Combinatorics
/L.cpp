#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll

const int N = 505;
int a[N];
int n, k;

int f(int d) {
  multiset<int> ms;
  for (int i = 1; i <= n; i++) {
    int x = (a[i] % d);
    ms.insert(x);
  }

  int cnt = 0;
  while (!ms.empty()) {
    int first = *ms.begin();
    ms.erase(ms.begin());

    if (first == 0) {
      continue;
    }
    cnt += first;

    while (first > 0 and ms.size() >= 1) {
      int last = *ms.rbegin();
      int old = last;
      last += first;
      if (last >= d) {
        if (ms.find(*ms.rbegin()) != ms.end()) ms.erase(ms.find(*ms.rbegin()));
        int extra = last - d;
        first = extra;
      }
      else {
        if (ms.find(*ms.rbegin()) != ms.end()) ms.erase(ms.find(*ms.rbegin()));
        first = 0;
        ms.insert(last);
      }
    }
  }

  return cnt;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;

  int sum = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum += a[i];
  }

  int ans = 1;
  for (int i = 1; i * i <= sum; i++) {
    if (sum % i != 0) continue;
    if (f(i) <= k) ans = max(ans, i);
    if (f(sum / i) <= k) ans = max(ans, sum / i);
  }

  cout << ans << '\n';

  return 0;
}