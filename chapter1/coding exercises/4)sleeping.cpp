//dont use count everywhere i index itself can help me to count,just need a marker like last here
//dont make array also to find the min or max type of question 
//process last automatically if mark cant not be mapped 
#include<bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(false); cin.tie(nullptr)

using ll = long long;
using namespace std;
int main() {

    string line;

    while(cin>>line){
    ll ans =0;
    ll last=-1;
    ll n = line.size();
    for(ll i=0; i<n; i++) {
    if(line[i]=='X'){
        if(last==-1){
            ans= max(ans,i-1);
        }
else{
ans=max(ans,(i-last-2)/2);
}
        last=i;
    }

        //  else if (i==(line.size()-1)){
        //     ans=max(ans,i-last-1);
        // }
    }
    //optimized that above line as it will select only greater no.
             ans=max(ans,n-last-2);
    
    cout<<ans<<endl;
}
return 0;
}