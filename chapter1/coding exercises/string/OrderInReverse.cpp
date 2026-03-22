// EQBYXOR
// cout<<no,yes comes definite output now the play is if (condition),here you have to play with if else 
#include <bits/stdc++.h>
using namespace std;
#define YES cout<<"yes"<<endl; return 0
#define NO cout<<"no"<<endl ; return 0
int solve_case(){
    return [&]()->int {

        int n;
        cin >> n;
        vector<int> arr(n);
        for(int &k : arr) cin >> k;

        (*max_element(arr.begin(), arr.end()) != 7) && [&](){
            cout << "no\n";
            return 0;
        }();

        for(int j = 0; j < n/2; j++){
            (arr[j+1] > arr[j] + 1) && [&](){
                cout << "no\n";
                return 0;
            }();
        }

        cout << "yes\n";
        return 0;

    }();
}

int main() {
int t;
cin>>t;
while(t--)
solve_case();
}
