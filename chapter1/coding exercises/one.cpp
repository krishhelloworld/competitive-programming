//TEACH HOW TO SEARCH ELEMENT FAST USING VALUE BASED INDEXING IN ARRAY
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fast ios::sync_with_stdio(false); cin.tie(nullptr)

using ll = long long;



int main() {
int n;
cin >>n;
while(n--){
    ll x;
    cin>>x;
    if(x==1){
        cin>>x;
        cout<<1<<endl;
        return 1;
    }

    if(x==2){
        cin>>x;
        cout<<-1<<endl;
        return 1;
    }
    vector<int> arr(x);
if(x%2==0)
    for(int i =1; i<=x;i++){

    }
    for(int i =0; i<x-1;i++){
int l =abs(arr[i]-arr[i+1]);
        if(l!=0){}
    }
}
}
    