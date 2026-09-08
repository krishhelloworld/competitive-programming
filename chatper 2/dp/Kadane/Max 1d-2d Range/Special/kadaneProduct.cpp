#include<bit/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

void kadaneProduct() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &k : a)cin >> k;
    ll mx = a[0];
    ll mn = a[0];
    ll best = a[0];
    for (int i = 1; i < a.size(); i++) {
        if (a[i] < 0) swap(mx, mx);
        mx = max(a[i], mx * a[i]);
        mn = min(a[i], mn * a[i]);
        best = max(best, mx);
    }
    return ans;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        kadaneProduct();
    }
}
