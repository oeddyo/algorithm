/*
ID: xieke.b1
PROG: numtri
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <string.h>

using namespace std;
const int MAXN = 1002;
int dp[MAXN][MAXN];
int d[MAXN][MAXN];
ofstream fout("numtri.out");
ifstream fin ("numtri.in");
int N;
const int INF = 999999999;
void work(){
    for(int i=0; i<N; i++){
        for(int j=0; j<=i; j++){
            dp[i+1][j] = max(dp[i+1][j],dp[i][j]+d[i][j]);
            dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]+d[i][j]);
        }
    }
    int ans = -INF;
    for(int i=0; i<N; i++){
        ans = max(ans,d[N-1][i]+dp[N-1][i]); 
    }
    fout<<ans<<endl;
}

int main(){
    fin>>N;
    for(int i=0; i<N; i++){
        for(int j=0; j<=i; j++){
            fin>>d[i][j];
        }
    }
    work();
    return 0;
}

