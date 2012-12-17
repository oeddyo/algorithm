/*
ID: xieke.b1
PROG: palsquare
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

ofstream fout("palsquare.out");
ifstream fin ("palsquare.in");
int B;

string ten_to_B(int N){
    string res;
    while(N){
        int t = N%B;
        char a;
        if(t>=10){
            a = t-10+'A';
        }else{
            a = t+'0';
        }
        res+=a;
        N/=B;
    }
    reverse(res.begin(), res.end());
    return res;
}

void work(){
    for(int num=1; num<=300; num++){
        int sq = num*num;
        string t = ten_to_B(sq);
        string t2 = t;
        reverse(t2.begin(), t2.end());
        if(t==t2){
            fout<<ten_to_B(num)<<" "<<ten_to_B(sq)<<endl;
        }
    }
}

int main(){
    fin>>B;
    work();


    return 0;
}

