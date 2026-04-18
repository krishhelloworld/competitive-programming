#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
int S, B;

    while (cin >> S >> B) {
        
        if (S == 0 && B == 0)
            break;

        set<int> arr;

        for (int i = 1; i <= S; i++) {
        arr.insert(i);
        }

        for (int i = 0; i < B; i++) {
            int L, R;
            cin >> L >> R;
        auto it3 = arr.lower_bound(L);
        auto it4 = arr.upper_bound(R);    
       if(it3==arr.begin()){
        cout<<"* ";}
    else{
        auto it1 = prev(it3);
        cout<<*it1<<" ";
    }

   if(it4==arr.end()){
        cout<<"*"<<endl;}
   
    else{
        cout<<*it4<<endl;
    }
                arr.erase(it3,it4);

       }

        cout << "-\n";
    }

    return 0;
}
//INPUT TEST CASES
