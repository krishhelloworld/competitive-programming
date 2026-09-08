#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

void kadaneMatrix() {
    int rows, cols;
    cin >> rows >> cols;
    vector<vector<int>> arr(rows, vector<int>(cols));
    for (int e = 0; e < rows; e++) {
        for (int d = 0; d < cols; d++) {
            cin >> arr[e][d];
        }
    }
    // int rows = arr.size();
    // int cols = arr[0].size();
    ll ans = LLONG_MIN;
    for (int top = 0; top < rows; top++) {
        vector<int> compressed(cols, 0);
        for (int bottom = top; bottom < rows; bottom++) {
            for (int col = 0; col < cols; col++) {
                compresssed[col] += arr[bottom][col];
                ll cur = compressed[0];
                ll best = compressed[0];
                for (int col = 1; col < cols; col++) {
                    cur = max(compressed[col], compressed[col] + cur);
                    best = max(best, cur);
                    ans = max(ans, best);
                }
            }
        }
    }
    return ans;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        kadaneMatrix();
    }
}
