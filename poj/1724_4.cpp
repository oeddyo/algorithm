#include <iostream>
#include <queue>
#include <string.h>
#include <map>
using namespace std;

int K,N,R;
typedef pair<int,int> mypair;

const int MAXN = 101;
const int INF = 999999999;

int dp[MAXN][10001];
vector < pair<int, mypair > > g[MAXN];

void work(){
    for(int i=0; i<MAXN; i++){
        for(int j=0; j<=K; j++){
            dp[i][j] = INF;
        }
    }

    dp[0][0] = 0;

    for(int j=0; j<=K; j++){
        for(int i=0; i<N; i++){
            if(dp[i][j]>=INF)continue;
            int sz = g[i].size();
            for(int k=0; k<sz; k++){
                int dis = g[i][k].second.first;
                int cost = g[i][k].second.second;
                if(j+cost>K){
                    continue;
                }
                int city = g[i][k].first;
                dp[city][j+cost] = min(dp[city][j+cost],dp[i][j]+dis);
            }
        }
    }
    int ans = INF;
    for(int i=0; i<=K; i++){
        ans = min(ans, dp[N-1][i]);
    }
    if(ans==INF){
        cout<<-1<<endl;
    }else{
        cout<<ans<<endl;
    }

}

int main(){
    cin>>K;
    cin>>N;
    cin>>R;
    for(int i=0; i<R; i++){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        a--,b--;
        g[a].push_back( pair<int, mypair>(b,mypair(c,d)) );
    }
    work();
    return 0;
}
