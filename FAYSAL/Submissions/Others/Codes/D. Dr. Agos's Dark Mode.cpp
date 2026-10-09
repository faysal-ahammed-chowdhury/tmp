#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll

int f(int a, int b, int c, int n) {
  int aa = a - 1;
  int bb = b - a - 1;
  int cc = c - b - 1;
  int dd = n - c;

  // cout << aa << ' ' << bb << ' ' << cc << ' ' << dd << '\n';

  int ans = (aa * (aa + 1)) / 2;
  ans += (bb * (bb + 1)) / 2;
  ans += (cc * (cc + 1)) / 2;
  ans += (dd * (dd + 1)) / 2;

  int x = bb + cc;
  if (x % 2 == 0) {
    ans += (aa + 1) * (dd + 1);
  }

  if (bb % 2 == 0) {
    ans += (aa + 1) * (cc + 1);
  }
  if (cc % 2 == 0) {
    ans += (bb + 1) * (dd + 1);
  }

  return ans;
}

void solve() {
  int n; cin >> n;

  if (n == 1) {
    cout << "1\n";
    return;
  }
  if (n == 2) {
    cout << "11\n";
    return;
  }
  if (n == 3) {
    cout << "101\n";
    return;
  }

  vector<pair<int, vector<int>>> cnt_pos;

  int zero = n - 1;
  int left = zero / 2;
  int right = zero - left;
  int cnt = ((left * (left + 1)) / 2) + ((right * (right + 1)) / 2);
  cnt_pos.push_back({cnt, vector{left + 1}});

  zero = n - 2;
  left = zero / 3;
  int middle = zero / 3;
  right = zero / 3;
  int rem = zero % 3;
  if (middle % 2 == 0 and rem > 0) middle++, rem--;

  if (rem > 0) left++, rem--;
  if (rem > 0) right++, rem--;

  if (middle % 2 == 0) middle--, left++;
  cnt = ((left * (left + 1)) / 2) + ((right * (right + 1)) / 2) + ((middle * (middle + 1)) / 2);
  cnt_pos.push_back({cnt, vector{left + 1, left + middle + 2}});


  if (n > 6) {
    zero = n - 3;
    int per = zero / 4;
    int a = per + 1;
    int b = per + per + 2;
    int c = per + per + per + 3;

    // cout << a << ' ' << b <<  ' ' << c << '\n';

    int range = min(n, 5ll);

    for (int i = -range; i <= range; i++) {
      for (int j = -range; j <= range; j++) {
        for (int k = -range; k <= range; k++) {
          int aa = a + i;
          int bb = b + j;
          int cc = c + k;
          if (aa >= 1 and aa < bb and bb < cc and cc <= n) {
            // if (!(aa == 1 and bb == 4 and cc == 6)) continue;
            // cout << "here\n";
            cnt_pos.push_back({f(aa, bb, cc, n), vector{aa, bb, cc}});
          }
        }
      }
    }

    per = zero / 3;
    a = 1;
    b = per + 2;
    c = per + per + 3;
    for (int i = -range; i <= range; i++) {
      for (int j = -range; j <= range; j++) {
        for (int k = -range; k <= range; k++) {
          int aa = a + i;
          int bb = b + j;
          int cc = c + k;
          if (aa >= 1 and aa < bb and bb < cc and cc <= n) {
            // if (!(aa == 1 and bb == 4 and cc == 6)) continue;
            // cout << "here\n";
            cnt_pos.push_back({f(aa, bb, cc, n), vector{aa, bb, cc}});
          }
        }
      }
    }
  }


  sort(cnt_pos.begin(), cnt_pos.end());

  for (int i = 1; i <= n; i++) {
    bool found = false;
    for (auto x : cnt_pos[0].second) {
      if (x == i) found = true;
    }
    cout << found;
  }
  cout << '\n';
  // cout << cnt_pos[0].first  << '\n';
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