
vector<vector<long long>> buildPrefix(vector<vector<int>> &a) {
    int n = a.size();
    int m = a[0].size();

    vector<vector<long long>> p(n + 1, vector<long long>(m + 1));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            p[i][j] =
                a[i - 1][j - 1]
                + p[i - 1][j]
                + p[i][j - 1]
                - p[i - 1][j - 1];
        }
    }

    return p;
}

//get exact row and columns based query input and output
long long rectangleSum(vector<vector<long long>> &p, int r1, int c1, int r2, int c2) {
    return p[r2 + 1][c2 + 1]
           - p[r1][c2 + 1]
           - p[r2 + 1][c1]
           + p[r1][c1];
}
// ## QUERY FORMULA-; (after preprocessed area)
// +BIG RECTANGLE Area -> r2+1 and c2+1 have this array area in it(+1 because of extra zeros column and row )
//     ↓
// - TOP AREA
//     ↓
// - LEFT AREA
//     ↓
// + TOP-LEFT AREA (the extra area that have been cutten from whole area)

1 2 3
4 5 6
7 8 9

area of this part would be
5 6
8 9
    =
        +
        1 2 3
        4 5 6
        7 8 9

        +
        1 2 3
        4 5 6

        +
        1 2
        4 5
        7 8

        -
        1 2
        4 5
//  ## AREA FORMULA-; (pre processing area)
// + TOP AREA
// + LEFT AREA
// - TOP LEFT AREA
// + current area
