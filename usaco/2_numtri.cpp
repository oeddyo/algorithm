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
int dp[2][MAXN];
int d[MAXN][MAXN];
ofstream fout("numtri.out");
ifstream fin ("numtri.in");
int N;
const int INF = 999999999;
void work(){
    for(int i=0; i<N; i++){
        for(int j=0; j<=i; j++){
            int a = (i+1)%2;
            int b = i%2;
            
            dp[a][j] = max(dp[a][j],dp[b][j]+d[i][j]);
            dp[a][j+1] = max(dp[a][j+1], dp[b][j]+d[i][j]);
        }
    }
    int ans = -INF;
    for(int i=0; i<N; i++){
        ans = max(ans,d[(N-1)][i]+dp[(N-1)%2][i]); 
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

