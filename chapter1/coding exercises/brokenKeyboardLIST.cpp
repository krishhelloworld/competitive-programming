#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    string line;
    while (getline(cin, line)) {
        list<char> text;
        auto cursor = text.begin();

        for (char c : line) {
            if (c == '[') {
                cursor = text.begin();
            }
            else if (c == ']') {
                cursor = text.end();
            }
            else {
                text.insert(cursor, c);
            }
        }

        for (char c : text)
            cout << c;
        cout << '\n';
    }
    return 0;
}