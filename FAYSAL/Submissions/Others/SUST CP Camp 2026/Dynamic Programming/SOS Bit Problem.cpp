#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
bool CHECK(int N, int pos) { return (bool)(N & (1 << pos)); }
void SET(int &N, int pos) { (N |= (1 << pos)); }
void CLR(int &N, int pos) { (N &= ~(1 << pos)); }
 
const int N = 2e5 + 9, MAX = 1048576 + 9, K = 21;
int n, a[N], freq[MAX];
int dp[MAX][K];
int dp2[MAX][K];
int dp3[MAX][K];
 
// int f(int x, int bit) {
//   if (x >= MAX) return 0;
//   if (bit == -1) {
//     return freq[x];
//   }
 
//   int &ans = dp[x][bit];
//   if (ans != -1) return ans;
 
//   ans = 0;
//   if (CHECK(x, bit)) {
//     int y = x;
//     CLR(y, bit);
//     ans += f(y, bit - 1);
//     ans += f(x, bit - 1);
//   }
//   else ans += f(x, bit - 1);
 
//   return ans;
// }
 
// int f2(int x, int bit) {
//   if (x >= MAX) return 0;
//   if (bit == -1) {
//     return freq[x];
//   }
 
//   int &ans = dp2[x][bit];
//   if (ans != -1) return ans;
 
//   ans = 0;
//   if (!CHECK(x, bit)) {
//     int y = x;
//     SET(y, bit);
//     ans += f2(y, bit - 1);
//     ans += f2(x, bit - 1);
//   }
//   else ans += f2(x, bit - 1);
 
//   return ans;
// }
 
// int f3(int x, int bit) {
//   if (x >= MAX) return 0;
//   if (bit == -1) {
//     return freq[x];
//   }
 
//   int &ans = dp3[x][bit];
//   if (ans != -1) return ans;
 
//   ans = 0;
//   if (!CHECK(x, bit)) {
//     int y = x;
//     SET(y, bit);
//     ans += f3(y, bit - 1);
//     ans += f3(x, bit - 1);
//   }
//   else {
//     int y = x;
//     CLR(y, bit);
//     ans += f3(y, bit - 1);
//   }
 
//   return ans;
// }
 
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
        dp[x][bit] = freq[x];
        continue;
      }
      int &ans = dp[x][bit];
      ans = 0;
      if (CHECK(x, bit - 1)) {
        int y = x;
        CLR(y, bit - 1);
        ans += dp[y][bit - 1];
        ans += dp[x][bit - 1];
      }
      else ans += dp[x][bit - 1];
    }
  }
 
  for (int bit = 0; bit < K; bit++) {
    for (int x = MAX - 1; x >= 0; x--) {
      if (bit == 0) {
        dp2[x][bit] = freq[x];
        continue;
      }
      int &ans = dp2[x][bit];
      ans = 0;
      if (!CHECK(x, bit - 1)) {
        int y = x;
        SET(y, bit - 1);
        if (y < MAX) ans += dp2[y][bit - 1];
        ans += dp2[x][bit - 1];
      }
      else ans += dp2[x][bit - 1];
    }
  }
 
  for (int bit = 0; bit < K; bit++) {
    for (int x = MAX - 1; x >= 0; x--) {
      if (bit == 0) {
        dp3[x][bit] = freq[x];
        continue;
      }
      int &ans = dp3[x][bit];
      ans = 0;
      if (!CHECK(x, bit - 1)) {
        int y = x;
        SET(y, bit - 1);
        if (y < MAX) ans += dp3[y][bit - 1];
        ans += dp3[x][bit - 1];
      }
      else {
        int y = x;
        CLR(y, bit - 1);
        ans += dp3[y][bit - 1];
      }
    }
  }
 
  for (int i = 1; i <= n; i++) {
    cout << dp[a[i]][K - 1] << ' ' << dp2[a[i]][K - 1] << ' ' << n - dp3[a[i]][K - 1] << '\n';
  }
 
  return 0;
}