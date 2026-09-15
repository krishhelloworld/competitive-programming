#include <bits/stdc++.h>
using namespace std;

vector<vector<long long>> buildPrefix(vector<vector<long long>> &a) {
    int n = a.size();
    int m = a[0].size();

    vector<vector<long long>> p(n + 2, vector<long long>(m + 2, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            p[i][j] = a[i - 1][j - 1];
        }
    }
    vector<vector<long long>> err(n + 2, vector<long long>(m + 2, 0));
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            // cout << err[i][j] << " ";
            long long  sum  = -1e18;
            for (int k = 0; k < 4; k++) {
                int ni = i + dx[k];
                int nj = j + dy[k];

                sum  = max(sum, p[ni][nj]);
                // cout << p[ni][nj];
            }
            err[i][j] = sum;
            // cout << " " << err[i][j] << " ";
        }
        // cout  << endl;

    }
    return err;
}


int main() {
    vector<vector<long long>> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    for (auto&rows : arr) {
        for (long long &cols : rows) {
            cout << cols << " ";
        }
        cout << endl;
    }
    vector<vector<long long>> narr = buildPrefix(arr);
    for (auto&rows : narr) {
        for (long long &cols : rows) {
            cout << cols << " ";
        }
        cout << endl;
    }
}
