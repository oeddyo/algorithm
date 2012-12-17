/*
ID: xieke.b1
PROB: rockers
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <stack>
#include <vector>
#include <string.h>
#include <queue>


using namespace std;
ifstream fin("rockers.in");
ofstream fout("rockers.out");

int INF = 999999999;
const int MAXN = 25;
//int dp[MAXN][MAXN][MAXN];
int dp[MAXN][MAXN];
int N,T,M, songs[MAXN];

void work(){
    //for(int i=0; i<MAXN; i++)for(int j=0; j<MAXN; j++)for(int k=0; k<MAXN; k++)dp[i][j][k] = -INF; 
    for(int i=0; i<MAXN; i++)for(int j=0; j<MAXN; j++)dp[i][j] = -INF;

    //dp[0][0][0] = 0;
    dp[0][0] = 0; 
    int ans = -1;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            for(int k=T; k>=0; k--){
                if(dp[j][k]!=-INF){
                    if(k+songs[i]<=T){
                        dp[j][k+songs[i]] = max(dp[j][k+songs[i]], dp[j][k]+1);
                        ans = max(dp[j][k+songs[i]], ans);
                        //cout<<"putting "<<i<<" "<<j<<" "<<k+songs[i]<<" as "<<dp[j][k+songs[i]]<<endl;
                    }
                    if(j+1<M){    
                        dp[j+1][0] = max(dp[j][k], dp[j+1][0]);
                        ans = max(dp[j+1][0], ans);
                        //cout<<"putting "<<i<<" "<<j+1<<" "<<0<<" as "<<dp[j+1][0]<<endl;
                    }
                }

            }
        }
    }

    fout<<ans<<endl;


}

int main(){
    fin>>N>>T>>M;
    for(int i=0; i<N; i++){
        fin>>songs[i];
    }
work();
    
    
    return 0;
}

