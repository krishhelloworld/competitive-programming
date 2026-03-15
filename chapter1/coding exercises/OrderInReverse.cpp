// EQBYXOR

#include <bits/stdc++.h>
using namespace std;
#define YES cout<<"yes"<<endl; return 0
#define NO cout<<"no"<<endl ; return 0

int solve_case(){
        int n,x=0;
        cin>>n;
        vector<int> arr(n);
        for(int &k : arr)
        cin>>k;
(*max_element(arr.begin(), arr.end()) != 7) && [&](){cout << "7no" << endl; x++; return 0;}();
if(x>0) return 0;
        for(int j=0;j<n/2;j++){ (arr[j+1]>arr[j]+1) && [&](){ cout<<"no"<<endl; x++;return 0;}();if(x>0) return 0;
}
        for(int i=0,j=n-1;i<j;i++,j--){
                if(arr[i]!=arr[j]){
			x++;                        NO;
                }
if(x>0) return 0;

        }
        YES;
        return 0;
}

int main() {
int t;
cin>>t;
while(t--)
solve_case();
}
