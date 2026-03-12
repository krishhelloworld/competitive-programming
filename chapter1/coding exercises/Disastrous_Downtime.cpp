//never use i=1;
//  1 1
// 1616  [i=0]//never enter the for loop
// ceil((float)i-k/l) alternate to use this 
// (n - k + l - 1) / l; use this as alternate
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
// ---------- Fast IO ----------
#define fast ios::sync_with_stdio(false); cin.tie(nullptr);

// ---------- Type Aliases ----------
using ll = long long;



// ---------- Example Usage ----------
int main() {
ll n,l;
cin >>n>>l;
vector<ll> arr(n);
ll k=0,ans=0;
for(ll&j : arr){
cin >>j;
}
for(ll i = 0; i < n; i++){
    if(arr[i] <= arr[k] + 999){
          }
          else{
            ll x = (i - k + l - 1) / l;
        ans = max(ans, x);
        k ++;
          }
}
ll x = (n - k + l - 1) / l;
ans = max(ans, x);
cout<<ans<<endl;
}
    