/*
ID: xieke.b1
PROG: ride
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
using namespace std;

string s1;
string s2;

int main(){
    
    
    ifstream fin("ride.in");
    ofstream fout("ride.out");

    while(fin>>s1>>s2){
        long long int t1=1, t2=1;
        cout<<"now s1 s2 "<<s1<<" "<<s2<<endl;
        for(int i=0; i<s1.size(); i++){
            t1*= s1[i]-'A'+1;
        }
        for(int i=0; i<s2.size(); i++){
            t2*= s2[i]-'A'+1;
        }
        cout<<"T1 T2 "<<t1<<" "<<t2<<endl;
        if( t1%47 == t2%47){
            fout<<"GO"<<endl;
        }else{
            fout<<"STAY"<<endl;
        }
    }
    return 0;
}

