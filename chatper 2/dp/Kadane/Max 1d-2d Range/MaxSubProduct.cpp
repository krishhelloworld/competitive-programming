-#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

void solve_case() {
    vector<ll> arr;
    int n;
    while (cin >> n) {
        if (n == -999999) break;
        arr.push_back(n);
    }
    if (arr.size() < 1) return;
    ll mx = arr[0];
    ll mn = arr[0];
    ll best = arr[0];

    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] < 0) swap(mx, mn);
        mx = max(arr[i], arr[i] * mx);
        mn = min(arr[i], arr[i] * mn);
        best = max(best, mx);
    }
    cout << best << endl;
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
// test cases
// 4
// 1 2 3 -999999
// -5 -2 2 -30 -999999
// -8 -999999
// -1 0 -2 -999999


