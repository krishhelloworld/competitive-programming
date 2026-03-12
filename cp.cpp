#include <iostream>
#include<bits/stdc++.h>
using namespace std;


int main(){
char t;
int date, ab, hol, cla, per, mon, tcl,abl;
int x = 2, counter = 0, i = 0;
int nod, nod1;
constexpr int separr[] = {7, 14, 21, 28};
constexpr int octarr[] = {5, 12, 19, 26};
cout<<"test case of accuracy or approximate\n For text case of accuracy-:\n 1) no. of question wilil be high \n \t TO PROCEED WITH ACCURACY TYPE-> A \n\n For text case of approximate-:\n 1) output will give you ida about detained or not \n \t TO PROCEED WITH APPROXIMATE TYPE -> P \n\n";
cin>>t;
if(t == 'P'||t== 'p'){
   cout << "\t\t YOU SELECTED APPROXIMATE. \n\n";
cout<<" month going on"<<endl;
cin>>mon;
mon=abs(mon);
while(mon<9||mon>10){
    cout<<"enter valid month"<<endl;
cin>>mon;
}

cout<<"todays date"<<endl;
cin>>date;

while(date>31){
cout<<"enter valid date"<<endl;
cin>>date;
}


if (mon==9){
    cout<<"is there any other holidays rather than sunday{write no of days}"<<endl;
    cin>>hol;
    while(hol>25){
        cout<<"enter valid holiday no"<<endl;
    cin>>hol;
}
i = 0;
counter = 0;
    while(i<4 && date>separr[i]){
        counter++;
        i++;
}

    nod=date-counter-1-hol;
   // tcl=nod*5;
    cout<<"no of absent days in this month "<<endl;
    cin>>ab;
   // cla=ab;
    //attend=(nod-ab)*5;
 per= ((double)(nod-ab)/nod)*100;
}

else{
    cout<<"is there any  other holidays rather than sunday{write no of days}"<<endl;
    cin>>hol;
    while(hol>25){
        cout<<"enter valid holiday no"<<endl;
    cin>>hol;
    }
    nod1=25-hol;

i = 0;
counter = 0;
while (i < 4 && date > octarr[i]) {
    counter++;
    i++;
}

nod=date + nod1 - counter;
    cout<<"no of days you were absent "<<endl;
    cin>>ab;
   per= ((double)(nod-ab)/nod)*100;
}
abl=(55-hol) - (75*(55-hol)/100);
abl=abs(abl);
if (per < 70) { cout << "\nCONCLUSION: padhle gawar\n"; }
    else if (per >= 70 && per < 75) { cout << "\nCONCLUSION: You are going to detained. Attend regularly if you want CT-1!\n"; }
    else if (per >= 75 && per < 80) { cout << "\nCONCLUSION: Good\n"; }
    else if (per >= 80) { cout << "\nCONCLUSION: Are you sure? YOU FUCKING LIKE THIS COLLEGE???\n"; }

cout<<"\n\n \t \b DETAILED REPORT \n"<<endl;
cout<<"no of lecture taken = "<<nod*5<<endl;
cout<<"no of lecture attended = "<<(nod-ab)*5<<endl;
cout<<"DATE OF CT-1 \t 10 nov 2025" <<endl;
   cout << fixed << setprecision(2);
    cout << "\nAttendance Percentage: " << per << "%\n"<<endl;
cout<<"no of days you can absent now= "<<abl-1-ab<<endl;
}

return 0;
}
