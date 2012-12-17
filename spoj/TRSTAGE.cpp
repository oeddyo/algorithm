#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

const int MAXN = 1000;
const double INF = 999999999;
double g[MAXN][MAXN];
double t[MAXN];
double dp[31][(1<<8)];
int a,b,m,n,p;
const double eps = 1e-9;
bool eq(double a, double b){
    if(fabs(a-b)<=eps){
        return true;
    }
    return false;
}
void work(){
    for(int i=0; i<31; i++)for(int j=0; j<(1<<8); j++)dp[i][j]=INF;
    dp[a][0] = 0;
    for(int s = 0; s<(1<<(n)); s++){
        for(int c_from = 1; c_from<=m; c_from++){
            for(int c_to = 1; c_to<=m; c_to++){
                for(int ticket=0; ticket<n; ticket++){
                    //if(g[c_from][c_to]==INF)continue;
                    if( (s>>ticket)&1 != 0)continue;
                    if(eq(g[c_from][c_to], INF))continue;
                    if(eq(dp[c_from][s], INF))continue;
                    //if(dp[c_from][s]>=INF)continue;
                    int ns = (1<<ticket)|s;
                    double time = g[c_from][c_to]/(1.0*t[ticket]);
                    if(dp[c_to][ns] > dp[c_from][s] + time){
                        dp[c_to][ns] = dp[c_from][s]+time;
                        //cout<<"state "<<s<<"-> "<<ns<<"; from "<<c_from<<" to "<<c_to<<" with fee of "<<time<<" and now all is "<<dp[c_to][ns]<<endl;;
                    
                    }
                }
            }
        }
    }
    double ans = INF;
    for(int s=0; s<(1<<(n));s++){
        //cout<<"now searching for at state "<<s<<" "<<dp[b][s]<<endl;
        ans = min(ans, dp[b][s]);
    }
    if(ans<INF-1){
        cout<<setiosflags(ios::fixed)<<setprecision(5)<<ans<<endl;
    }else{
        cout<<"Impossible"<<endl;
    }
}

int main(){
    while(1){
    for(int i=0; i<MAXN; i++){
        for(int j=0; j<MAXN; j++){
            g[i][j] = INF;
        }
    }
    cin>>n>>m>>p>>a>>b;
    if(n==m&&m==p&&p==a&&a==b&&b==0)break;
    for(int i=0; i<n; i++){
        cin>>t[i];
    }
    int t_from, t_to, t_dis;
    for(int i=0; i<p; i++){
        cin>>t_from>>t_to>>t_dis;
        g[t_from][t_to] = t_dis;
        g[t_to][t_from]=t_dis;
    }
    work();
    }
    return 0;
}

