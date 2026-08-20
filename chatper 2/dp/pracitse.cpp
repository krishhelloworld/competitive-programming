#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"

void solve_case() {
  int n;
  cin >> n;
  ll f[n + 1][8];
  const ll inf = 1e18;
  for (int e = 0; e <= n; e++) {
    for (int d = 0; d < 8; d++) {
      f[e][d] = inf;
    }
  }
  for (int i = 0; i <= n; i++) {
    f[i][0] = 0;
  }
  f[0][0] = 0;
  for (int i = 0; i < n; i++) {
    int cost;
    cin >> cost;
    string s;
    cin >> s;
    int string_mask = 0;
    cout << cost << s << endl;
    for (char c : s) {
      int pos = 'C' - c;
      string_mask += (1 << pos);
      cout << string_mask << " " << pos << endl;
    }
    for (int mask = 0; mask < 8; mask++) {
      cout << i + 1 << "----" << endl;
      cout << " mask  -> " << mask << "mask |string_mask -> "
           << (mask | string_mask) << "   ";
      cout << "f[" << i + 1 << "][" << (mask | string_mask) << "]" << "  | ";
      cout << "f[" << i << "][" << (mask) << "]" << f[i][mask] + cost << " "
           << endl;
    }
  }
}

int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve_case();
  }
}

// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;
// #define endl '\n'
// #define RED(x) "\033[31m" << (x) << "\033[0m"
//
// void solve_case() {
//   int n;
//   cin >> n;
//   ll f[n + 1][8];
//
//   const ll inf = 1e18;
//   for (int e = 0; e <= n; e++) {
//     for (int d = 0; d < 8; d++) {
//       f[e][d] = inf;
//     }
//   }
//   for (int i = 0; i <= n; i++) {
//     f[i][0] = 0;
//   }
//   f[0][0] = 0;
//   for (int i = 0; i < n; i++) {
//     int cost;
//     cin >> cost;
//     string s;
//     cin >> s;
//     int string_mask = 0;
//     int pos;
//     for (char c : s) {
//       pos = 'C' - c;
//       string_mask += (1 << pos);
//       cout << RED("string_mask -> ") << string_mask << RED(" char -> ") << c
//            << endl;
//     }
//     for (int mask = 0; mask < 8; mask++) {
//       // mask is telling me about the position and the string_mask is telling
//       // about which mask the value the cost should be updated
//       // and the mask is telling about the previous char position to add one
//       // with the cost
//       // mask+string_mask will put the value at right place of addition of
//       char
//
//       f[i + 1][mask | string_mask] =
//           min(f[i + 1][mask | string_mask], f[i][mask] + cost);
//     }
//     for (int mask = 0; mask < 8; mask++) {
//       cout << f[i + 1][mask] << " |  ";
//     }
//     cout << endl;
//   }
//
//   int ans = f[n][7];
//   if (ans == inf)
//     cout << "NO" << endl;
//   else
//     cout << ans << endl;
//
// }
//
// int main() {
//   ios::sync_with_stdio(false);
//   cin.tie(nullptr);
//   int t;
//   cin >> t;
//   while (t--) {
//     solve_case();
//   }
// }
