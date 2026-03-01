
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
// ---------- Fast IO ----------
#define fast ios::sync_with_stdio(false); cin.tie(nullptr)

// ---------- Type Aliases ----------
using ll = long long;

#define rep(i,n) for(int i=0; i<(n); ++i)
#define all(x) begin(x), end(x)

void solve_Case(){
int n ;
cin>>n;
vector<ll>arr(n);
ll sum =0;
for (int i = 0; i < n; i++) {
     cin>>arr[i];
     sum += arr[i];
}
ll k = sum/(n+1);
for (int i = 0; i < n; i++) {
cout<<arr[i]-k<<" ";
}
cout<<endl;

}

// ---------- Example Usage ----------
int main() {
    fast;
    int t; 
    cin>>t;
    while(t--){
        solve_Case();
    }
    return 0;
}
    