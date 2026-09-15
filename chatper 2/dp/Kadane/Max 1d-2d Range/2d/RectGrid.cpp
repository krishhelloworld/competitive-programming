#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m;
bool valid(int ni, int nj) {
    return i >= 0 && i < n && j >= 0 && j < m;
}

vector<vector<long long>> buildPrefix(vector<vector<long long>> &a) {
    int n = a.size();
    int m = a[0].size();

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    vector<vector<long long>> p(n + 2, vector<long long>(m + 2, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 0; k < 4; k++) {
                int nx = i + dx[k];
                int ny = j + dy [k];
                if (valid(nx, ny)) {
                    p[i][j] += a[nx][ny];
                }
            }

        }

    }
    return p;
}

int main() {
    vector<vector<long long>> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<long long>> narr = buildPrefix(arr);
    for (auto&rows : narr) {
        for (long long &cols : rows) {
            cout << cols;
        }
        cout << endl;
    }
}
