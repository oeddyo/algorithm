#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>
#include <stack>
#include <map>
#include <set>
using namespace std;
 
#define DEBUG
#define REP(i,a) for(i=0;i<a;i++)
#define FOR(i,a,b) for(i=a;i<b;i++)
#define VE vector<int>
#define SZ size()
#define PB push_back
const int MAXN = 502;
int N, K, h[MAXN];

//int dp[MAXN][MAXN];
int dp[MAXN];
int zero[MAXN], one[MAXN];
const int INF = 99999999;
void pre(){
    //zero[1] = (h[0]==0?1:0);
    //one[1] = (h[0]==1?1:0);
    for(int i=1; i<=N; i++){
        if(h[i-1] == 1){
            one[i] += one[i-1] + 1;
            zero[i] = zero[i-1];
        }else{
            zero[i] += zero[i-1]+1;
            one[i] = one[i-1];
        }
        //cout<<"zero["<<i<<"] = "<<zero[i]<<endl;
        //cout<<"one["<<i<<"] = "<<one[i]<<endl;
    }
}


void work(){
    pre();
    for(int i=0; i<MAXN; i++)for(int j=0; j<MAXN; j++){
        //dp[i][j ] = INF;
        dp[i] = INF;
    }

    //dp[0][0] = 0;
    dp[0] = 0;
    
    for(int k=0; k<K; k++){
        for(int i=1; i<=N; i++){
            for(int j=0; j<i; j++){
                int n_one = one[i] - one[j];
                int n_zero = zero[i] - zero[j];
                int v = n_one * n_zero;
                cout<<i<<" "<<j<<" v = "<<n_one<<"*"<<n_zero<<" = "<<v<<endl;
                //dp[i][k+1] = min(dp[i][k+1], dp[j][k]+v);
                dp[i] = min(dp[i], dp[j] + v);
                //cout<<"dp["<<i<<"]["<<k+1<<"] = "<<dp[i][k+1]<<endl;
                cout<<"dp["<<i<<"] = "<<dp[i]<<endl;
            }
        }
    }

    //cout<<dp[N][K]<<endl;
    for(int i=0; i<=N; i++){
        cout<<dp[i]<<" ";
    }cout<<endl;

    cout<<dp[N]<<endl;

}

int main(){
    cin>>N>>K; 
    for(int i=0; i<N; i++){
        cin>>h[i];
    }
    work();
    return 0;

}

