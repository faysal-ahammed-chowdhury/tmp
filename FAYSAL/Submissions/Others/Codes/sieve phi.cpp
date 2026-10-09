#include <bits/stdc++.h>
using namespace std;

const int N = 5e6 + 9;
int phi[N];

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

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  sieve_phi();

  return 0;
}