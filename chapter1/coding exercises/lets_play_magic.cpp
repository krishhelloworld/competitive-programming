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

	for(int i=arr[0].second,j=0; j<n;){
// 		if(i+arr[j].second<=n)	{
// 			// i+=arr[j].second;
 // x=i+arr[j].second;

// 		}
// 		else 					{i+= (arr[j].second-n);}
		
		while(count!=arr[j].second){
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
// 13
// AS ACE
// 2S TWO
// 3S THREE
// 4C FOUR
// 5C FIVE
// 6C SIX
// 7D SEVEN
// 8D EIGHT
// 9D NINE
// TH TEN
// JH JACK
// QH QUEEN
// KH KING

// QH 4C AS 8D KH 2S 7D 5C TH JH 3S 6C 9D
// 9D 4C AS TH 7D 2S QH 5C KH 8D 3S JH 6C 		


//if(c[i]==0)count++; count == arr[j].second