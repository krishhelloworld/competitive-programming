#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
template <typename T>
void output(const vector<T> &arr2)
{
    for (auto x : arr2)
    {
        cout << x << " ";
    }
    cout << endl;
}
vector<int> solve_case(int n)
{
    vector<int> arr;
    if (n < 4)
    {
        arr.push_back(n);
        output(arr);
        return arr;
    }
    for (int i = 2; i < n + 1; i++)
    {
        if (n)
        {
            if (n % i == 0)
            {
                arr.push_back(i);
                n /= i;
                i = 1;
            }
        }
        else
        {
            break;
        }
    }
    return arr;
}
// ""
//     "5,2,5=10,lcm//the one who have most element of that key is real lcm element
//     = 5,
//     hcf ""
//         "//for hcf it is the element who have repeated in both
int  lcm(auto &v1, auto &v2, int n)
{
    vector<int> freq1((n + 5),0), freq2((n + 5),0);
    vector<int> result;
    int ans;
    for (auto x : v1)
    {
        freq1[x]++;
    }
    for (auto x : v2)
    {
        freq2[x]++;
    }
    for (int i = 0; i <= n; i++)
    {
        if (freq1[i] != 0 && freq2[i] != 0)
        {

            ans = max(freq1[i], freq2[i]);
            result.push_back(ans);
        }
        else if (freq1[i] != 0 || freq2[i] != 0)
        {
            if (freq1[i] != 0)
                result.push_back(freq1[i]);
            else
                result.push_back(freq2[i]);
        }
    }
    int x = 1;
    for (int i = 0; i < result.size(); i++)
    {
        x *= result[i];
    }
    return x;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b,n;
    cin >> a >> b;
    vector<int> mult1 = solve_case(a);
    vector<int> mult2 = solve_case(b);
    if (mult1.size() >= mult2.size())
    {
         n = mult1.size();
    }
    else
    {
        n = mult2.size();
    }
    cout << lcm(mult1, mult2, n);
}