#include <iostream>

using namespace std;

int main()
{
    int x, y;
    wchar_t str[20];
    wcout << "Enter 2 integers:"<<endl;
    wcin >> x >> y;
    wcout << "Sum = " << (x+y) << endl;
    wcout << "Enter a string:";
    wcin >> str;
    wcout << "You entered " << str;
    return 0;
}