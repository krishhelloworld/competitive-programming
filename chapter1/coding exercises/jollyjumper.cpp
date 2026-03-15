//learn about transform function
//and if we dont know about the no of testcases then we can simply do this -> while(cin>>n){
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
#define fast ios::sync_with_stdio(false); cin.tie(nullptr)
using ll = long long;
#define all(x) (x).begin(), (x).end()
int main() {
    fast;
    int n; 
    while(cin>>n){
    vector<ll> arr(n),err(n-1),rrr(n-1);

    for(ll&k : arr)
        cin>> k;
    for (int i = 0; i < n-1; i++) {
        err[i]=i+1;
    }
    transform(arr.begin(),arr.end()-1,arr.begin()+1,rrr.begin(),[](ll a,ll b){
        return abs(a-b);
    });
    sort(all(rrr));
    if(err==rrr) cout<<"Jolly"<<endl;
    else         cout<<"Not jolly"<<endl;
}
    return 0;

}