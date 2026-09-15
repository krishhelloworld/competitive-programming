#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

void solve_case() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> garment(m + 1, vector<int>(n + 1, false));

    garment[0][0] = true;
    vector<vector<int>> price;

    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        vector<int> get(value);
        for (auto&k : get) cin >> k;
        price.push_back(get);
    }


    for (int money = 0; money <= m ; money++) {
        for (int d = 0; d < n; d++) {
            if (garment[money][d]) {
                for (auto&l : price[d]) {
                    if (money + l <= m) garment[money + l][d + 1] = true;
                }
            }
        }
    }

    for (int e = m; e >= 0; e--) {
        if (garment[e][n]) { cout << e << endl; return; }
    }

    cout << "no solution" << endl;

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

