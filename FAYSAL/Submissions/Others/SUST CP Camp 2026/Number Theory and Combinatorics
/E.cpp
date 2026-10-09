#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1000000 + 9;
int phi[N];
ll ans[N];

void sieve_phi() {
  for (int i = 0; i < N; i++)
    phi[i] = i;
  for (int i = 2; i < N; i++) {
    if (phi[i] == i) {
      for (int j = i; j < N; j += i)
        phi[j] -= phi[j] / i;
    }
  }
}

void prec() {
  for (int i = 2; i < N; i++) {
    for (int j = i + i; j < N; j += i) {
      ans[j] += phi[j / i] * i;
    }
  }

  ans[1] = 0;
  for (int i = 2; i < N; i++) {
    ans[i] += phi[i];
    ans[i] += ans[i - 1];
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  sieve_phi();
  prec();

  while (true) {
    int n; cin >> n;
    if (n == 0) break;
    cout << ans[n] << '\n';
  }

  return 0;
}