/*
ID: xieke.b1
PROB: nuggets
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <stack>
#include <vector>
#include <string.h>

using namespace std;
ifstream fin("nuggets.in");
ofstream fout("nuggets.out");

const int INF = 999999999;
int N;
const int MAXN = 100000;
int data[MAXN];
bool dp[MAXN];
int cnt = 0;

void work(){
    memset(dp,0,sizeof(dp));
    for(int i=0; i<N; i++){
        dp[ data[i] ] = 1;
    }

    for(int i=0; i<MAXN; i++){
        for(int j=0; j<N; j++){
            if(dp[i] && i+data[j]<MAXN){
                dp[i+data[j]] = 1;
            }
        }
    }
    int ans = -1;
    for(int i=MAXN-1; i>=0; i--){
        if(dp[i]==0){
            ans = i;
            break;
        }
    }
    if(ans==-1 || ans>=256*256-256*2){
        fout<<0<<endl;
    }else{
        fout<<ans<<endl;
    }
}


int main(){
    fin>>N;
    for(int i=0; i<N; i++){
        fin>>data[i];
    }
    work();
    return 0;
}

