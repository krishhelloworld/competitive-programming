//TEACH HOW TO SEARCH ELEMENT FAST USING VALUE BASED INDEXING IN ARRAY
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
// ---------- Fast IO ----------
#define fast ios::sync_with_stdio(false); cin.tie(nullptr)

// ---------- Type Aliases ----------
using ll = long long;



// ---------- Example Usage ----------
int main() {
int n;
cin >>n;
vector<int> arr(n);
for(int& a : arr)   
    cin >> a;
const ll max= 1000000;
vector<bool> err(max,0);
int arrows=0;
for(int j=0; j<n;j++){
    int y= arr[j];
if(1==err[y]){
    err[y]=0;
}
else{
    arrows++;
}
err[y-1]=1;
}
cout<<arrows<<endl;
}
    