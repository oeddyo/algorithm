/*
ID: xieke.b1
PROG: dualpal
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

ofstream fout("dualpal.out");
ifstream fin ("dualpal.in");

int N,S;


string ten_to_B(int number, int B){
    string res;
    while(number){
        int t = number%B;
        char a;
        if(t>=10){
            a = t-10+'A';
        }else{
            a = t+'0';
        }
        res+=a;
        number/=B;
    }
    reverse(res.begin(), res.end());
    return res;
}

void work(){
    int ok_count = 0;
    int num = S+1;
    while(ok_count<N){
    //for(int num = S+1; num<=S+N; num++){
        int cnt = 0;
        for(int B=2; B<=10; B++){
            string t1 = ten_to_B(num, B);
            string t2 = t1;
            reverse(t2.begin(), t2.end());
            cout<<"it's "<<t1<<" for "<<num<<" under "<<B<<endl;
            if(t1==t2 && t1[t1.size()-1]!='0'){
                cnt++;
            }
        }
        cout<<"ok-> "<<cnt<<endl;
        if(cnt>=2){
            fout<<num<<endl;
            ok_count++;
        }
        num++;
    }
}

int main(){
    fin>>N>>S;
    work();
    return 0;
}

