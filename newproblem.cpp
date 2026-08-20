#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve_case(){
string line;
while(getline(cin, line)) {
    if(line.contains('?')){
        char r = '?'^'A'^'B'^'C';
        for(auto& k : line){
            r ^= k;
        }
        cout<<r<<'\n';
    }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    while(n--){
        solve_case();
    }
}