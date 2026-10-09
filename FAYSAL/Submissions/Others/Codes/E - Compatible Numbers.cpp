#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
bool CHECK(int N, int pos) { return (bool)(N & (1 << pos)); }
void SET(int &N, int pos) { (N |= (1 << pos)); }
void CLR(int &N, int pos) { (N &= ~(1 << pos)); }
 
const int N = 1e6 + 9, MAX = 4194304 + 9, K = 23;
int n, a[N], freq[MAX];
int dp[MAX][2];

int Mod(int m) {
  int x = m % 2;
  if (x < 0) x += 2;
  return x;
}
 
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
 
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    freq[a[i]]++;
  }
 
  for (int bit = 0; bit < K; bit++) {
    for (int x = MAX - 1; x >= 0; x--) {
      if (bit == 0) {
        dp[x][Mod(bit)] = freq[x] ? x : -1;
        continue;
      }
      int &ans = dp[x][Mod(bit)];
      ans = -1;
      if (!CHECK(x, bit - 1)) {
        int y = x;
        SET(y, bit - 1);
        if (y < MAX and dp[y][Mod(bit - 1)] != -1) ans = dp[y][Mod(bit - 1)];
        if (dp[x][Mod(bit - 1)] != -1) ans = dp[x][Mod(bit - 1)];
      }
      else {
        int y = x;
        CLR(y, bit - 1);
        if (dp[y][Mod(bit - 1)] != -1) ans = dp[y][Mod(bit - 1)];
      }
    }
  }
 
  for (int i = 1; i <= n; i++) {
    cout << dp[a[i]][Mod(K - 1)] << ' ';
  }
  cout << '\n';
 
  return 0;
}