#include <bits/stdc++.h>
using namespace std;

template<typename T>
void output_vector(const T &v, bool add_one=false, int start=-1, int end=-1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());
    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
}

void run_case() {



}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
     cin >> t;
    while (t--) run_case();
}
