/*
ID: xieke.b1
PROB: friday
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>

using namespace std;
int N;

int d_in_m[13] = {-1,31,-1,31,30,31,30,31,31,30,31,30,31};
int fri_13[13];;

int main(){
    ofstream fout("friday.out");
    ifstream fin("friday.in");

    while(fin>>N){
        memset(fri_13,0,sizeof(fri_13));
        int cnt = 1;
        for(int year=1900; year<1900+N; year++){
            for(int month=1; month<=12; month++){
                int days;
                if(month==2){
                    if((year%100!=0 &&year%4==0) || (year%100==0 && year%400==0 ) ){
                            days = 29;
                    }else{
                            days = 28;
                        }
                }else{
                    days = d_in_m[month];
                }
                cout<<"year "<<year<<" month "<<month<<" days "<<days<<endl;
                for(int i=1; i<=days; i++){
                    cnt+=1;
                    cnt%=7;
                    if(i==13){
                        fri_13[cnt]++;
                    }
                }
            }
        }
        for(int i=0; i<6; i++){
            fout<<fri_13[i]<<" ";
            //cout<<fri_13[i]<<" ";
        }
        //cout<<fri_13[6]<<endl;
        fout<<fri_13[6]<<endl;
    }

    return 0;
}


