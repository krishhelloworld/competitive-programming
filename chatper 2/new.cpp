#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<int>> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int ans = 0;
    for (int i = 1; i < 9 ; i += i & -i) {
        for (int j = 1; j < 9; j += j & -j) {
            // cout << "arr[" << i << "]" << "[" << j << "]" << endl;
            if (arr[i][j]) ans += arr[i][j];
        }
    }
    cout << ans << endl;
}
