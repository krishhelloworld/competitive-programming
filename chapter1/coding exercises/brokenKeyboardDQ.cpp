#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    while(getline(cin, s)) {
        deque<string> dq;
        string cur;
int count=0;
        bool atFront = false;
  for(char c : s) {
            if(c == '[') {
                if (!cur.empty()) {
                    if (atFront) dq.push_front(cur);
                    else dq.push_back(cur);
                    cur.clear();
                }
                atFront = true;
                ++count;
            } 
            else if (c == ']') {
                if (!cur.empty()) {
                    if (atFront) dq.push_front(cur);
                    else dq.push_back(cur);
                    cur.clear();
                }
                atFront = false;
                ++count;
            } 
            else {
                ++count;
                if(count==s.size()){
                    cur += c;
                    dq.push_back(cur);
                }
                else{
                    cur += c;
                }
            }
        }
       

        for (auto &part : dq)
            cout << part;
        cout << '\n';
    }
}