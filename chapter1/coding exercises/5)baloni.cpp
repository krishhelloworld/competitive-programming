#include<bits/stdc++.h> 
#define endl '\n'
using namespace std;

int main(){
 int n;
 cin >>n;
 vector<int> arr(n);
 for(int& k : arr)
 cin >> k;
 vector<int> arr2(n);
 for(int p =0; p<n; p++){
     if(arr[p]==0){
         arr2[p]=0;
     cout<<arr2[p]<<" ";
     }
     else{
         arr2[p]= arr[p]-1;
        
     cout<<arr2[p]<<" ";
         
     }
 }
 cout<<endl;
 int count =1;
 for(int j=0,i =1; i<n&&j<n; ){
     if(j==(n - 1))//there is no element to match with the last element
     break;
 
        if(arr[j]==0)
        ++j;
      
     if (arr2[j]==arr[i]){
         cout<<"from first if   "<<i+1<<" "<<arr[i];
         arr[i]=0;
         if(i==(n-1)&&j!=(n-2))//the j have last element left if it is matched no matter the count will not increases 
             ++count;
          cout<<"-> "<<arr2[j]<<"="<<count<<endl;
         ++j;
         i=j+1;
         cout<<"\t "<<j<<"  "<<i<<endl;
     }
     
     else if(i==(n-1)&&arr[i]!=0){
        ++count;
                 cout<<"from second if   "<<arr[i]<<"-> "<<arr2[j]<<"="<<count<<endl;
        ++j;    
        i=j+1;
         cout<<"\t "<<j<<i<<endl;
     }
     else{
         ++i;
         cout<<"\t "<<j<<" "<<i<<endl;
     }
 } 
 cout<<endl<<count;
}
