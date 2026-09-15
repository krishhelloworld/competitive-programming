#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

//brute force techinque
void solve_case() {

    int  n, m, size, check;
    cin >> n >> m >> size >> check;
    vector<vector<bool>> arr(n, vector<bool> (m, false));

    vector<pair<int, int>> err;
    for (int i = 0; i < size; i++) {
        int x, y;
        cin >> x >> y;
        err.emplace_back(x - 1, y - 1);
        arr[x - 1][y - 1] = true;
    }
    vector<pair<int, int>> rrr;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == false) rrr.emplace_back(i, j);
        }
    }
    int x1, y1;
    for (int e = 0; e < check; e++) {
        int f ;
        cin >> f;
        //always i forget this
        int ans = INT_MIN;
        vector<vector<int>> count(n, vector<int> (m, 0));
        for (auto&[x, y] : err) {

            for (auto&[s, r] : rrr) {
                if (abs(x - s) + abs(y - r) <= f) {
                    count[s][r] += 1;
                    if (ans < count[s][r]) {
                        x1 = s;
                        y1 = r;
                        ans = count[s][r];
                    }
                }
            }
        }
        cout << ans << " pos(";
        cout << x1 + 1 << "," << y1 + 1 << ")" << endl;

    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve_case();
}
