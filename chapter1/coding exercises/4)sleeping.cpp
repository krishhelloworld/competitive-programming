#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int main(){
    cout<<"hello";
    string s;
    while(true){
        cin>> s;
        if (s[0]== 'A'){
            break;
        }
        vector<pair<int,int>> count(s.size(),{0,0});
        int m=0;
    for(int i =0 ; m <= s.size();) {
        if(s[i]=='.'){
            count[i].first++;
            ++m;
        }
        else if(s[i]=='X'){
            count[i].second++;
            ++i;
            count[i].second++;
            ++m;
        }
    }
    for(int j =0; j<s.size();j++){
        if(count[j].second == 1){
            count[j].first += -1;
        }
        else if(count[j].second){
            if(count[j].first % 2==0){
            count[j].first = count[j].first-count[j].second - 1;
            }
        else{
            count[j].first = count[j].first-count[j].second;
        }
            
        }
    }
    auto k = max_element(count.begin(),count.end());
    cout<<k->first<<endl;
        
    }
    cout<<"hello";
}