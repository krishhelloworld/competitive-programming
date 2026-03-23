//	>cyclic simulation -;
//		while (true) {
//		    i = (i + 1) % n;
//		    if (slot[i] is empty) count++;
//		}
//		or 
//		while(true){
//			(i>=n) ? i=1 : i++ ;
// 		}
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
	int n,count =0;
	cin>>n;
	string s;
	vector<pair<string,int>> arr(n);
	vector<string> err(n+1,"0");
	for(int i =0; i<n; i++){
		cin>>arr[i].first;
		cin>>s;
		int k = s.size();
		arr[i].second= k;
	}

	for(int i=1,j=0; j<n;){
		while(true){
			if(err[i]=="0") {
				count++;
				 if(count==arr[j].second) {
				err[i]=arr[j].first; j++; count=0; break;}}
				(i>n) ? i=1 : i++ ;
			}

}
	for(auto ii : err){
	    if(ii != "0")
		cout<<ii<<" ";
	}	
}
