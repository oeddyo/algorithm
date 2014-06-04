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
 
const int MAXN = 50;
int dp[MAXN][MAXN];

const int INF = 500000000;
int g[MAXN][MAXN][MAXN];
int N;


void work(){
    for(int i=0; i<MAXN; i++){
        for(int j=0; j<MAXN; j++){
            dp[i][j] = INF;
        }
    }
    dp[0][1] = 0;

    for(int level=1; level<=N; level++){
        for(int cur_node = 1; cur_node<=MAXN; cur_node++){
            for(int pre_node =1; pre_node<=MAXN; pre_node++){
                if(g[level][cur_node][pre_node] != INF){
                    dp[level][cur_node] = min(dp[level][cur_node], dp[level-1][pre_node] + g[level][cur_node][pre_node]);
                }
            }
        }
    }
    int ans = INF;
    for(int i=1; i<MAXN; i++){
        ans = min(ans, dp[N][i]);
    }
    cout<<ans<<endl;

}


int main(){
    cin>>N;

    for(int i=0; i<MAXN; i++)for(int j=0; j<MAXN; j++){
        for(int k=0; k<MAXN; k++){
            g[i][j][k] = INF;
        }
    }


    for(int level=1; level<=N; level++){
        int K;
        cin>>K;
        for(int k=1; k<=K; k++){
            while(1){
                int a, b;
                cin>>a;
                if(a==0)break;
                cin>>b;
                //cout<<"a = "<<a<<" b = "<<b<<endl;
                //cout<<"g["<<level<<"]["<<k<<"]["<<a<<"] = "<<b<<endl;
                g[level][k][a] = b;
            }
        }
        if(level<N){
            string t;
            cin>>t;
            //cout<<"now setting "<<t<<endl;
        }
    }
    work();
    

    return 0;
}

