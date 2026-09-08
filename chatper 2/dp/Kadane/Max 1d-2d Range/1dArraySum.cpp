#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
pair<int, int> kadaneIndex(vector<ll> a) {
    int cur = a[0];
    int best = a[0];
    int current_start = 0;
    int best_start = 0;
    int best_end = 0;
    for (int i = 1; i < a.size(); i++) {
        if (a[i] < a[i] + cur) {
            cur = cur + a[i];
        } else {
            cur = a[i];
            current_start = i;
        }
        if (best < cur) {
            best = cur;
            best_end = i;
            best_start = current_start;
        }
    }
    return make_pair(best_start, best_end);

}
void solve_case() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (ll&k : a)cin >> k;
    int cur = a[0];
    int best = a[0];
    for (int i = 1; i < a.size(); i++) {
        cur = max(a[i], cur + a[i]);// 2 7 -30 1 28 //here 1 after -30 begins a
        // new squence
        best = max(best, cur);
    }
    cout << best << endl;
    auto [k, m] = kadaneIndex(a);
    cout << k << m << endl;
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

