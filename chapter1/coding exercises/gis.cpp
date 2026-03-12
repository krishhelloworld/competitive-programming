//here i face difficulty to know the specific index where the last arr element was inserted 
//for the last element postition-> arr.size()-1, arr.push_back();
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fast ios::sync_with_stdio(false); cin.tie(nullptr)
using ll = long long;

#define rep(i,n) for(int i=0; i<(n); ++i)
#define all(x) begin(x), end(x)

int main() {
    fast;
ll n;
cin >>n;
    ll k;
vector<ll>arr;
for(ll i =0 ; i<n; i++){ 
    cin>>k;
if(i==0){
    arr.push_back(k);
}
else if(k>arr[arr.size()-1]){
    arr.push_back(k);
}
}
cout<<arr.size()<<endl;
cout<<*arr.begin();
for(ll&c : arr)
   if(c!=*arr.begin()) cout<<" "<<c;
cout<<endl;
    return 0;
}
    