void kadaneMaxProduct(vector<int> &arr) {
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

