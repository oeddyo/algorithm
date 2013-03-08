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

const int MAXN = 105;
const int INF = 999999999;
int dp[MAXN][MAXN];
int d[MAXN][MAXN];
int sum[MAXN][MAXN];
int N;

void work(){
    memset(dp,0,sizeof(dp));
    for(int i=0; i<=N; i++){
        int t = 0;
        for(int j=0; j<=N; j++){
            t+=d[j][i];
            sum[j][i] = t;
        }
    }
    /*
    for(int i=0; i<=N; i++){
        for(int j=0; j<=N; j++){
            cout<<sum[i][j]<<" ";
        }cout<<endl;
    }
cout<<"***"<<endl;
    */
    int ans = -INF;
    for(int i=0; i<N; i++){
        for(int j=i+1; j<=N; j++){
            int sd[MAXN], t_ans = -INF;
            memset(sd,0,sizeof(sd));
            for(int k=1; k<=N; k++){
                int t = sum[j][k] - sum[i][k];
                sd[k] = max(sd[k-1]+t, t);
                t_ans = max(sd[k],t_ans);
            }
            ans = max(ans, t_ans);
        }
    }
    cout<<ans<<endl;

}


int main(){
    cin>>N;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin>>d[i][j];
        }
    }
    work();

    return 0;
}

