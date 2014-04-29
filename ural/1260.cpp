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

const int MAXN = 1000;
long long int dp[MAXN][MAXN];
int N;

void work(){
    dp[1][1] = 1;
    dp[2][2] = 1;
    dp[2][3] = 1;
    dp[3][1] = dp[3][2] = dp[3][3] = 1;
    for(int i=3; i<N; i++){
        cout<<" i = "<<i<<endl;
        for(int j=1; j<=N; j++){
            if(j==i-1){
                dp[i+1][i+1] += dp[i][j];
            }else if(j==i){
                dp[i+1][i+1] += dp[i][j];
                dp[i+1][i+1+1] += dp[i][j];
            }else if(j==i+1){
                dp[i+1][i] += dp[i][j];
            }
        }
    }
    
    long long int ans = 0;
    for(int i=1; i<=N; i++){
        ans += dp[N][i];
        cout<<"dp["<<N<<"]["<<i<<"] = "<<dp[N][i]<<endl;
    }

    cout<<ans<<endl;

}



int main(){
    
    cin>>N;
    memset(dp, 0, sizeof(dp));
    
    work();
    return 0;
}

