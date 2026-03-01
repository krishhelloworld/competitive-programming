#include<bits/stdc++.h>
#include <cstdlib>  // for exit()
#define endl '\n'
using namespace std;
//UVa
void solve_case(){
    int k;
    int check=0;
    cin>>k;
    vector<pair<int,int>> car(k);
    unordered_set<int > seen;//we got something new here 
    for( int ii =0; ii<k; ii++){
        cin>>car[ii].first>>car[ii].second;
        
    }
    vector<int> m(k);//created to search and insert fast
    vector<int> z(k);
    
    for(int i =0; i<k;i++){
        m[i]= car[i].second + i + 1;//giving the new index value to the m[i]
        if(seen.count(m[i])||m[i] < 1 || m[i]>k ){
            cout<<"-1"<<endl<<endl;
            return;}

seen.insert(m[i]);
        }
        for(int j = 0 ; j<k; j++){
            z[m[j] - 1]=car[j].first;
        }
        for(auto jj : z){
         cout<<jj<<endl;
        }
         cout<<endl;

}
