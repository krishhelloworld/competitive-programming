#include <bits/stdc++.h>
#define endl '\n'

#define fast ios::sync_with_stdio(false); cin.tie(nullptr)
using namespace std;

int solve_case(){
            int count=0;
        string m,w;
        cin>>m>>w;
        if(m.size()<=w.size()){
        for(int i =0,j=0; i<w.size()&&j<m.size();i++){
                if(w[i]==m[j]){
                    count++;   
                    j++;
                }
        }
        (count >= m.size()) ? cout<<"YES"<<endl : cout<<"NO"<<endl ;
        return 1;
        }
        
        else{
        for(int i =0,j=0; i<m.size()&&j<w.size();i++){
                if(w[i]==m[i]){
                    count++;    
                    j++;
                }
        }
        (count >= w.size()) ? cout<<"YES"<<endl : cout<<"NO"<<endl ;
        return 1; 
        }

}

int main() {
fast;
int n;
cin >>n;
while(n--){ 
solve_case();
}

}
