
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
ll k;
cin>>n;
ll sum =0;
vector<ll>arr2(n);
for(ll& ii : arr2)
    cin>> ii;
sort(arr2.begin(),arr2.end());
for (int j = 0; j < n; j++) {
k= ((j+1)-arr2[j]);
if(k>=0)
    sum+= k;
else{
    // cout<<arr[j]<<" "<<arr2[j]<<endl;
    cout<<"-1"<<endl;
    return;
}
}
cout<<sum<<endl;
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
    