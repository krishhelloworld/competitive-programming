#include<bits/stdc++.h>
using namespace std;
#define endl ‘n’
using ll = long long;
 
void solve_case(int n){
int x;
map<int,int> freq;
vector<set<int>> f(3);
for(int i =0; i<3;i++){
cin>>x;
for(int j = 0; j < x; j++){
    int val;
    cin >> val;
    f[i].insert(val);
}
}
 
 
for(int i =0; i<3;i++){
for(auto ii : f[i]){
freq[ii]++;
}
}
 
vector<vector<int>> unique(3);
for(int i =0; i<3;i++){
for(int ii : f[i]){
if(freq[ii]==1)
unique[i].push_back(ii);
}
sort(unique[i].begin(),unique[i].end());
}
 
vector<int> size(3);
for(int i =0; i<3;i++){
size.push_back(unique[i].size());
}
int maxs = *max_element(size.begin(),size.end());
cout<<“Case #”<<n<<endl;
for(int i =0;i<3;i++){
if(unique[i].size()==maxs){
cout<<i+1<<” “;
cout<<unique[i].size()<<” “;
for(int ii : f[i]){
cout<<ii<<” “;
 
}
}
 
cout<<endl;
}
}
 
int main(){
int n;
cin>>n;
int s =0;
while(s<n){
s++;
solve_case(s);
}
}