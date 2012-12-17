/*
ID: xieke.b1
PROB: inflate
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

ifstream fin("inflate.in");
ofstream fout("inflate.out");

typedef pair<int, int> pii;
const int INF = 900000000;
const int MAXN = 10001;
int N,M;
int dp[MAXN];

int gain[MAXN];
int weight[MAXN];


void work(){
    for(int i=0; i<MAXN; i++)dp[i]=-INF;
    
    dp[0] = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<=M; j++){
            if(j+weight[i]<=M){
                dp[j+weight[i]] = max(dp[j+weight[i]], dp[j]+gain[i]);
            }
        }
    }
    int ans = -1;
    for(int i=0; i<=M; i++){
        ans = max(ans, dp[i]);
    }
    fout<<ans<<endl;
}


int main(){
    fin>>M>>N;
    for(int i=0; i<N; i++){
        fin>>gain[i]>>weight[i];
    }
    work();


    return 0;
}

