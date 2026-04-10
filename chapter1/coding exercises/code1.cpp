#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
        
ll no,pairs,m=0,x,y;
cin >> no >> pairs;
vector<ll> arr(no);
for(ll&k : arr)
cin >> k;

while(pairs){
        cin>>x>>y;
        arr[y-1]=0;
        --pairs;
}

for(ll&k : arr){
        m+=k;
}
cout<<m<<endl;
        
}
