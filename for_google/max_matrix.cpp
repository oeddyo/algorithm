#include <iostream>
#define MAXN 120
#define INF 99999999
using namespace std;

int N, data[MAXN][MAXN], c[MAXN][MAXN];

void work(){
    //compress matrix here
    for(int i=0; i<N; i++)for(int j=0; j<N; j++)c[i][j]=data[i][j];

    for(int j=0; j<N; j++){
        for(int i=1; i<N; i++){
            c[i][j]+=c[i-1][j];
        }
    }
    //c[i][j] represent the accumutive sum of c[0~i][j]
    int ans = -INF;
    for(int i=0; i<N; i++){
        for(int j=i; j<N; j++){
            int t_sum = 0;
            int t_dp[MAXN];
            memset(t_dp,0,sizeof(t_dp));
            for(int k=0; k<N; k++){
                int t = c[j][k] - c[i][k] + data[i][k];
                if(k==0){
                    t_dp[0] = max(0, t);
                }else{
                    t_dp[k] = max(t_dp[k-1]+t, t);
                }
                if(t_dp[k]> ans ){
                    ans = t_dp[k];
                }
            }
        }
    }
    cout<<ans<<endl;
}



int main(){
    cin>>N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>data[i][j];
        }
    }
    work();

    return 0;
}

