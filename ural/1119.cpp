#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int N,M;
const int INF = 999999999;
const int MAXN = 1003;

double dp[2][MAXN];

int diag[MAXN][2];
int cnt=0;

void work(){
    for(int i=0; i<2; i++)for(int j=0; j<MAXN; j++)dp[i][j] = INF;
    
    dp[1%2][1] = 0.0;
    //dp[1][1] = 0.0;
    
    for(int i=1; i<=N+1; i++){
        for(int j=1; j<=M+1; j++){
            if(dp[i%2][j]==INF)continue;
            //if(dp[i][j]==INF)continue;
            for(int k=0; k<cnt; k++){
                if(diag[k][0]==i&&diag[k][1]==j){
                    dp[(i+1)%2][(j+1)] = min(dp[(i+1)%2][(j+1)], (dp[i%2][j]+141.421));
                    //dp[(i+1)][(j+1)] = min(dp[(i+1)][(j+1)], (dp[i][j]+141.421));
                    //cout<<"ok now i,j are "<<i<<" "<<j<<" and "<<dp[i%2][j]<<endl;
                    //cout<<"en-> min is "<<min(dp[(i+1)%2][j+1], dp[i%2][j]+141.421)<<endl;
                    //cout<<"first is "<<dp[(i+1)%2][j+1]<<" second is "<<dp[i%2][j]+141.421<<endl;
                    //cout<<"next "<<dp[(i+1)%2][j+1]<<endl;
                    //cout<<"diag "<<i<<" "<<j<<endl;
                    break;
                }
            }
            dp[(i+1)%2][j] = min(dp[(i+1)%2][j],dp[i%2][j]+100);
            //dp[(i+1)][j] = min(dp[(i+1)][j],dp[i][j]+100);
            dp[i%2][(j+1)] = min(dp[i%2][(j+1)],dp[i%2][j]+100);
            //dp[i][(j+1)] = min(dp[i][(j+1)],dp[i][j]+100);
            //cout<<"at "<<i<<" "<<j<<" "<<dp[i%2][j]<<endl;
        }
        if(i==N+1)break;
        for(int j=0; j<MAXN; j++)dp[i%2][j] = INF;
    }

    //cout<<M+1<<" "<<N+1<<endl;
    //cout<<int((dp[(N+1)%2][(M+1)]+0.5))<<endl;
    cout<<int((dp[(N+1)%2][(M+1)]+0.5))<<endl;
}


int main(){
    cin>>N>>M;
    cin>>cnt;
    for(int i=0; i<cnt; i++){
        cin>>diag[i][0]>>diag[i][1];
    }

    work();

    return 0;
}

