// EQBYXOR-Equal by XORing
// {0,1,2,-1} definite output now the play is if (condition),here you have to play with if else 

#include<bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(false); cin.tie(nullptr)

using ll = long long;
using namespace std;
int solve_case(){
int a,b,n;
cin>>a>>b>>n;
long long  d = a ^ b;
if(d==0){
	cout<<0<<endl;
	return 1;
	} 
	// //A = 3
	// B = 7
	// D = 3 XOR 7 = 4
	// d = 4  // binary: 0000...0100
	// clzll(12) = 61
	// 63 - 61 = 2  // bit index of highest 1
	// hb = 1 << 2 = 4 // 4 is the least no to be present in the n, hence n should be 4+1
	// N = 3  //here n is 2+1
	// Allowed numbers
	// 1 = 001
	// 2 = 010
	// Possible XORs
	// 1⊕0 = 1 //same as 2,and three 3
	// 1⊕1 = 0
	// 2⊕2 = 0
	// 1⊕2 = 3
	// {1,2,3}
	// hence hb=4 can never come in n that make to make d to find impossible 
	// ```

long long hb = 1ll << (63 - __builtin_clzll(d));
if(hb>=n){
	cout<<-1<<endl;
	return 1;
}

if(d<n){
	cout<<1<<endl;
	return 1;
}else{
cout<<2<<endl;}
        // ── CASE 2: Two operations needed ──────────────────
        ll X1 = n - 1;
        ll X2 = (n - 1) ^ d;
        
        cout << 2 << "\n";
        cout << "X1 = " << X1 << "\n";
        cout << "X2 = " << X2 << "\n";

return 0;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		solve_case();
	}
}

// Number: 12 → binary 1100
// MSB  LSB
// 1   1   0   0
// 8   4   2   1

//(highestbit) Largest power of 2 → 8 (bit 3)	//hb = 1LL << (63 - __builtin_clzll(d))
// Smallest power of 2 → 4 (bit 2)	//lb = 1LL << __builtin_ctzll(d) 


// in this problem we need to have hb= highest bit because it will be  only able to make the d
// we cant make  4(100) from  2(010) and 3(011) they dont have 1 to make xor of d
// Largest power of 2 → 8 (bit 3)	//hb = 1LL << (63 - __builtin_clzll(d))