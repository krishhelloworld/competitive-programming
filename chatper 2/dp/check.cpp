#include<bits/stdc++.h>
using namespace std;

void solve_case(){
int sum =0; 
int ans =0; 
int n;
cin >> n;
vector<int> arr(n);
for(int&h : arr)
cin>> h;

for(int i =0; i<9; i++){
sum+= arr[i];
ans= max(ans ,sum);
cout << "arr[i]"<<arr[i]<<"sum "<< sum << "ans "<< ans <<endl;
if (sum <0){
sum=0;
cout << "resum " << sum << endl;
} }
cout << ans << endl;

}
int main(){
ios::sync_with_stdio(false);
cin.tie(nullptr);
int t;
cin >> t ;
while(t--){
solve_case();
}
}
