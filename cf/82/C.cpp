#include <iostream>
#include <cstring>

using namespace std;

const int MAXN = 3000;
int earn[MAXN];
int cost[MAXN];
const int INF = 99999999;
int dp[MAXN][MAXN];
int idx, n, m;

int main(){
    idx = 1;
    cin>>n>>m;

    int tc, td;
    cin>>tc>>td;
    
    for(int i=0; i<n/tc; i++){
        earn[idx] = td;
        cost[idx] = tc;
        idx++;
    }

    
    //cin>>cost[0]>>earn[0];
    //idx++;
    for(int i=0; i<m; i++){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        int number = a/b;;
        //cout<<"build "<<c<<" "<<d<<" num = "<<number<<endl;
        for(int k=0; k<number; k++){
            cost[idx] = c;
            earn[idx] = d;
            idx++;
        }
    }

    memset(dp,0,sizeof(dp));

    //cout<<"earn 0 = "<<earn[0]<<endl;
    
    //dp[0][cost[0]] = earn[0];

    int ans = 0;
    for(int i=1; i<=idx; i++){
        for(int j=0; j<=n; j++){
            dp[i][j] = max(dp[i][j], dp[i-1][j]);
            if(j-cost[i]>=0){
                dp[i][j] = max(dp[i][j], earn[i] + dp[i-1][j-cost[i]]);
                //cout<<"dp["<<i<<"]["<<j<<"] = "<<dp[i][j]<<endl;
                ans = max(ans, dp[i][j]);
            }
        }    
    }
    cout<<ans<<endl;
}

