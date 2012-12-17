#include <iostream>
#include <string.h>
using namespace std;

const int MAXN = 21;
int d[MAXN][MAXN];

long long int dp[2][1<<20];
//long long int dp[MAXN][1<<20];
int T,N;
int t[MAXN][MAXN];
int n[MAXN];
int ones[1<<20];
void work(){
    memset(dp,0,sizeof(dp));
    /*for(int i=0; i<N; i++){
        for(int j=0; j<(1<<N); j++){
            dp[i][j]=0;
        }
    }*/
    for(int i=0; i<N; i++){
        if(d[0][i]==1){
            dp[0][(1<<i)] = 1;
        }
    }
    for(int i=0; i<(1<<N); i++){
        ones[i] = __builtin_popcount(i);
    }
    int num;
    for(int i=0; i<N-1; i++){
        int limit = 1<<N;
        for(int s=0; s<limit ; s++){
            if(ones[s]!=i+1)continue;
            if(dp[i&1][s]==0)continue;
            //if(dp[i][s]==0)continue;
            for(int k=0; k<n[i+1]; k++){
                //int w = t[i+1][k];
                //dp[i+1][(1<<(t[i+1][k]))|s] += dp[i][s];
                dp[(i+1)&1][ (1<<(t[i+1][k]))|s] += dp[i&1][s];
            }
            /*
            for(int j=0; j<N; j++){
                if( (s>>j)&1 ==1)continue;
                if(d[(i+1)][j]==0)continue;
                dp[(i+1)&1][ (1<<j)|s  ] += dp[i&1][s];  
            }*/
        }
    }
    cout<<dp[(N-1)&1][(1<<N)-1]<<endl;
}


int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        memset(n,0,sizeof(n));
        memset(t,0,sizeof(t));
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                //cin>>d[i][j];
                scanf("%d",&d[i][j]);
                if(d[i][j]==1){
                    t[i][n[i]] = j;
                    n[i]++;
                }
            }
        }
        work();
    }
    return 0;
}

