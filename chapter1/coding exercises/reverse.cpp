//1)same characters,same frequency,rearrangement
//,anagram(Both halves contain the same characters with same counts(order not important{who come first and who after}))
//use freq ,initialize the freq ,now do operation on it make another operation that equalize the freq to original form
//now check that there is any change in the original freq->yes ->print no because something is
//----------------------------------------------------------------

//2) to do same thing in array in reverse direction use
//  for(int i =0 ; i<n/2;i++){ i; n-i-1; }
// ------------------OR---------------
// for(int i = 0, j = n-1; i < j; i++, j--)
// {
//     cout << i << " " << j << endl;
// }
//------------------
//LAPIN problem on codechef
#include<bits/stdc++.h>
#define endl '\n'
#define print(n) cout<<n<<endl
#define YES cout<<"YES"<<endl; return
#define NO cout<<"NO"<<endl ; return
#define fast ios::sync_with_stdio(false); cin.tie(nullptr)

using ll = long long;
using namespace std;

void solve(){
    string s;
    cin >> s;

    int n = s.size();
    vector<int> freq(26,0);


for(int i=0;i<n/2;i++)
{
    freq[s[i]-'a']++;
    freq[s[n-i-1]-'a']--;
}

    for(int x:freq){
        if(x!=0){
NO;         
   return;
        }
        }

        YES;
}

int main(){
    fast;
    int t;
    cin>>t;

    while(t--) solve();
}