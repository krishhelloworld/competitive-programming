#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2005;
int pref[MAXN][MAXN];

int query(int x1, int y1, int x2, int y2) {

    x1 = max(x1, 0);
    y1 = max(y1, 0);
    x2 = min(x2, MAXN - 1);
    y2 = min(y2, MAXN - 1);

    int ans = pref[x2][y2];
    if (x1 > x2 || y1 > y2) return 0;

    if (x1 > 0) ans -= pref[x1 - 1][y2];

    if (y1 > 0) ans -= pref[x2][y1 - 1];

    if (x1 > 0 && y1 > 0) ans += pref[x1 - 1][y1 - 1];

    return ans;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int dx, dy;

    cin >> dx >> dy;

    int n;
    cin >> n;

    const int OFFSET = 1000;

    memset(pref, 0, sizeof(pref));

    // Store coffee shops in transformed coordinates
    for (int i = 0; i < n; i++) {

        int x, y;
        cin >> x >> y;

        int u = x + y;
        int v = x - y + OFFSET;

        pref[u][v]++;
    }

    // Build 2D prefix sum
    for (int i = 1; i < MAXN; i++) {
        for (int j = 1; j < MAXN; j++) {

            pref[i][j] +=
                pref[i - 1][j] +
                pref[i][j - 1] -
                pref[i - 1][j - 1];
        }
    }

    int q;
    cin >> q;

    while (q--) {

        int m;
        cin >> m;

        int best = -1;
        int bestX = 0;
        int bestY = 0;

        // Try every possible customer location
        for (int x = 0; x < dx; x++) {

            for (int y = 0; y < dy; y++) {

                int u = x + y;
                int v = x - y + OFFSET;

                int u1 = u - m;
                int u2 = u + m;

                int v1 = v - m;
                int v2 = v + m;

                int shops = query(u1, v1, u2, v2);

                if (shops > best) {

                    best = shops;
                    bestX = x;
                    bestY = y;
                }
            }
        }

        cout << bestX << " " << bestY << " " << best << '\n';
    }

    return 0;
}
// #include <bits/stdc++.h>
// using namespace std;

// const int MAXC = 2005;
// const int SHIFT = 1000;

// int pref[MAXC][MAXC];

// int getSum(int x1, int y1, int x2, int y2) {

//     // Clip rectangle to valid prefix-sum coordinates
//     x1 = max(x1, 1);
//     y1 = max(y1, 1);

//     x2 = min(x2, MAXC - 1);
//     y2 = min(y2, MAXC - 1);

//     if (x1 > x2 || y1 > y2)
//         return 0;

//     return pref[x2][y2]
//          - pref[x1 - 1][y2]
//          - pref[x2][y1 - 1]
//          + pref[x1 - 1][y1 - 1];
// }

// int main() {

//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int dx, dy, n, q;
//     int tc = 1;

//     while (cin >> dx >> dy >> n >> q) {

//         if (dx == 0 && dy == 0 && n == 0 && q == 0)
//             break;

//         // Clear prefix array
//         memset(pref, 0, sizeof(pref));

//         // ------------------------------------------------
//         // Step 1: Put coffee shops into transformed grid
//         // ------------------------------------------------

//         for (int i = 0; i < n; i++) {

//             int x, y;
//             cin >> x >> y;

//             int u = x + y;
//             int v = x - y + SHIFT;

//             pref[u][v]++;
//         }

//         // ------------------------------------------------
//         // Step 2: Build 2D prefix sum
//         // ------------------------------------------------

//         for (int i = 1; i < MAXC; i++) {

//             for (int j = 1; j < MAXC; j++) {

//                 pref[i][j] +=
//                     pref[i - 1][j]
//                     + pref[i][j - 1]
//                     - pref[i - 1][j - 1];
//             }
//         }

//         cout << "Case " << tc++ << ":\n";

//         // ------------------------------------------------
//         // Step 3: Answer each query
//         // ------------------------------------------------

//         while (q--) {

//             int m;
//             cin >> m;

//             int bestCount = -1;
//             int bestX = -1;
//             int bestY = -1;

//             // IMPORTANT:
//             // y outer loop, x inner loop
//             // gives required tie-breaking:
//             // smallest y, then smallest x.

//             for (int y = 1; y <= dy; y++) {

//                 for (int x = 1; x <= dx; x++) {

//                     int u = x + y;
//                     int v = x - y + SHIFT;

//                     int count = getSum(
//                         u - m,
//                         v - m,
//                         u + m,
//                         v + m
//                     );

//                     if (count > bestCount) {

//                         bestCount = count;
//                         bestX = x;
//                         bestY = y;
//                     }
//                 }
//             }

//             cout << bestCount
//                  << " (" << bestX
//                  << "," << bestY
//                  << ")\n";
//         }
//     }

//     return 0;
// }
