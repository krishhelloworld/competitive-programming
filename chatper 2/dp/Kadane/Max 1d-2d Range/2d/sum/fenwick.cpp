struct Fenwick2D {

    int n, m;
    vector<vector<long long>> bit;

    Fenwick2D(int n, int m)
        : n(n), m(m),
          bit(n + 1, vector<long long>(m + 1, 0))
    {}

    void add(int x, int y, long long val) {
        for (int i = x; i <= n; i += i & -i) {
            for (int j = y; j <= m; j += j & -j) {
                bit[i][j] += val;
            }
        }
    }

    long long sum(int x, int y) {
        long long ans = 0;
        for (int i = x; i > 0; i -= i & -i) {
            for (int j = y; j > 0; j -= j & -j) {
                ans += bit[i][j];
            }
        }
        return ans;
    }

    long long query(int r1, int c1, int r2, int c2) {
        return sum(r2, c2)
               - sum(r1 - 1, c2)
               - sum(r2, c1 - 1)
               + sum(r1 - 1, c1 - 1);
    }
};
