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
 

typedef long long ll;

const int MAXN = 501;
ll dp[MAXN][MAXN];
int N;

int main(){
    cin>>N;
    dp[0][0] = 1LL;
    ll ans = 0;
    for(int s=0; s<=N; s++){
        for(int t=0; t<=N; t++){
            if(dp[s][t]!=0){
                for(int n=t+1; n<N; n++){
                    if(n+s<=N){
                        dp[n+s][n] += dp[s][t];
                        //cout<<"ok... dp["<<n+s<<"]["<<n<<"] = "<<dp[n+s][n]<<endl;
                    }
                }
            }
        }
    }
    for(int i=1; i<=N; i++){
        ans += dp[N][i];
    }
    cout<<ans<<endl;

    return 0;
}

