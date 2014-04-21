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
 
const int MAXN = 181;
long long int dp[MAXN][10], N, K;

void work(){
    for(int i=0; i<MAXN;i++)for(int j=0; j<10; j++)dp[i][j] = 0LL;

    for(int i=1; i<K; i++){
        dp[0][i] = 1LL;
    }

    for(int i=0; i<N-1; i++){
        cout<<"now "<<dp[i][0]<<endl;
        for(int j=0; j<K; j++){
            if(dp[i][j]!=0){
                if(j==0){
                    for(int k=1; k<K; k++){
                        dp[i+1][k] += dp[i][j];
                    }
                }else{
                    for(int k=0; k<K; k++){
                        dp[i+1][k] += dp[i][j];
                    }
                }
            }
        }
    }
    long long int ans = 0;
    for(int i=0; i<K; i++){
        ans += dp[N-1][i];
    }
    cout<<ans<<endl;
}

int main(){
    cin>>N>>K;
    work();
    
    return 0;
}

