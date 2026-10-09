#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool is_digit(char c) {
  return (c >= '0' and c <= '9');
}

bool is_char(char c) {
  return ((c >= 'a' and c <= 'z') or (c >= 'A' and c <= 'Z'));
}

set<char> se = {'!', '?', '.', ',', ';', '$', '#', '^', '{', '}', '_', '=', '+', '*', ' '};
bool is_special(char c) {
  if (se.find(c) != se.end()) return true;
  return false;
}

bool is_valid(char c) {
  return is_digit(c) or is_char(c) or is_special(c);
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  cin.ignore();

  bool ok = true;
  while (t--) {
    string s; getline(cin, s);
    int n = s.size();

    bool part[n + 1];
    memset(part, false, sizeof part);

    if (s.front() == ' ' or s.back() == ' ') {
      ok = false;
      continue;
    }

    s = '=' + s;

    for (int i = 1; i <= n; i++) {
      if (!is_valid(s[i])) {
        ok = false;
        break;
      }
      if (s[i] == ' ' and s[i - 1] == ' ') {
        ok = false;
        break;
      }

      if (s[i] == '{') {
        if (s[i - 1] != '_' and s[i - 1] != '^') {
          ok = false;
          break;
        }

        int cnt = 0;
        bool all_digit = true;
        int xx = 0;
        char last = '=';
        for (int j = i - 2; j >= 1; j--) {
          if (s[j] == ' ') break;
          if (is_digit(s[j]) or is_char(s[j])) {
            part[j] = true;
            cnt++;
            all_digit &= is_digit(s[j]);
            xx++;
            last = s[j];
          }
          else {
            ok = false;
            break;
          }
        }

        if (cnt == 0) {
          ok = false;
          break;
        }

        if (all_digit and last == '0' and xx > 1) {
          ok = false;
          break;
        }

        if (i + 1 <= n) {
          if (s[i + 1] == '0') {
            ok = false;
            break;
          }
        }
        else {
          ok = false;
          break;
        }

        bool flag = false;
        for (int j = i + 1; j <= n; j++) {
          if (s[j] == '}') {
            flag = true;
            break;
          }
          part[j] = true;
          if (!is_digit(s[j])) {
            ok = false;
            break;
          }
        }

        if (!flag) {
          ok = false;
          continue;
        }
      }
    }

    if (!ok) continue;

    for (int i = 1; i <= n; i++) {
      if (part[i]) continue;

      if (is_digit(s[i])) {
        if (i - 1 >= 1 and !((is_digit(s[i - 1]) or is_char(s[i - 1]) or s[i - 1] == ' '))) {
          ok = false;
          break;
        }
        if (i + 1 <= n and !((is_digit(s[i + 1]) or is_char(s[i + 1]) or s[i + 1] == ' '))) {
          ok = false;
          break;
        }
      }

      if (is_digit(s[i])) {
        if (i + 1 <= n and is_digit(s[i + 1])) continue;

        char last = '=';
        bool all_digit = true;
        int xx = 0;
        for (int j = i; j >= 1; j--) {
          if (s[j] == ' ') break;
          all_digit &= is_digit(s[j]);
          xx++;
          last = s[j];
        }

        if (all_digit and last == '0' and xx > 1) {
          ok = false;
          break;
        }
      }
    }
  }

  // cout << ok << '\n';
  if (ok) cout << "Ok\n";
  else cout << "Validation failed\n";

  return 0;
}