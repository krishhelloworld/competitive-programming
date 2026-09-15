#include<bits/stdc++.h>
using namespace std;

void DiffArr() {

    vector<vector<long long>> a(n + 1, vector<long long>(m + 1));
    vector<vector<long long>> diff(n + 2, vector<long long>(m + 2));

    auto update = [&](int r1, int c1, int r2, int c2, long long x) {
        diff[r1][c1] += x;
        diff[r1][c2 + 1] -= x;
        diff[r2 + 1][c1] -= x;
        diff[r2 + 1][c2 + 1] += x;
    };

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {

            diff[i][j] += diff[i - 1][j]
                          + diff[i][j - 1]
                          - diff[i - 1][j - 1];

            a[i][j] += diff[i][j];
        }
    }
}
