
void kadaneMatrix() {
    int rows, cols;
    cin >> rows >> cols;
    vector<vector<ll>> a(rows, vector<ll>(cols));

    for (auto &row : a)
        for (auto &x : row)
            cin >> x;
// O(rows² × cols) real time complexty to dcrease the rows more than columns.
// For 100 × 5:
// 100² × 5 = 50,000

// But if you transpose it: 5 × 100

// then you can fix the smaller dimension:
// O(cols² × rows)

// which becomes:
// 5² × 100 = 2,500
    if (rows > cols) {
        vector<vector<ll>> trans(cols, vector<ll>(rows));
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                trans[j][i] = a[i][j];
        a.swap(trans);
        swap(rows, cols);
    }

    ll ans = LLONG_MIN;
    vector<ll> compressed(cols);

    for (int top = 0; top < rows; ++top) {
        fill(compressed.begin(), compressed.end(), 0);
        for (int bottom = top; bottom < rows; ++bottom) {
            for (int col = 0; col < cols; ++col)
                ll cur = compressed[0];

            for (int col = 1; col < cols; ++col) {
                cur = max(compressed[col],
                          cur + compressed[col]);
                ans = max(ans, cur);
            }
            ans = max(ans, compressed[0]);
        }
    }
    cout << ans << '\n';
}


//store the extract matrix
void kadaneMatrixExtra() {
    int rows, cols;
    cin >> rows >> cols;

    vector<vector<ll>> a(rows, vector<ll>(cols));

    for (auto &row : a)
        for (auto &x : row)
            cin >> x;

    if (rows > cols) {
        vector<vector<ll>> t(cols, vector<ll>(rows));

        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                t[j][i] = a[i][j];

        a.swap(t);
        swap(rows, cols);
    }

    ll ans = LLONG_MIN;

    int ansTop = 0, ansBottom = 0;
    int ansLeft = 0, ansRight = 0;

    vector<ll> compressed(cols);

    for (int top = 0; top < rows; ++top) {

        fill(compressed.begin(), compressed.end(), 0);

        for (int bottom = top; bottom < rows; ++bottom) {

            for (int col = 0; col < cols; ++col)
                compressed[col] += a[bottom][col];

            // Kadane
            ll cur = compressed[0];
            ll best = compressed[0];

            int start = 0;
            int bestLeft = 0;
            int bestRight = 0;

            for (int col = 1; col < cols; ++col) {

                if (compressed[col] > cur + compressed[col]) {
                    cur = compressed[col];
                    start = col;
                } else {
                    cur += compressed[col];
                }

                if (cur > best) {
                    best = cur;
                    bestLeft = start;
                    bestRight = col;
                }
            }

            if (compressed[0] > best) {
                best = compressed[0];
                bestLeft = bestRight = 0;
            }

            if (best > ans) {
                ans = best;
                ansTop = top;
                ansBottom = bottom;
                ansLeft = bestLeft;
                ansRight = bestRight;
            }
        }
    }

    cout << "Maximum Sum = " << ans << '\n';

    cout << "Top    = " << ansTop << '\n';
    cout << "Bottom = " << ansBottom << '\n';
    cout << "Left   = " << ansLeft << '\n';
    cout << "Right  = " << ansRight << '\n';
}
