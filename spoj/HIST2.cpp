#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int N;
int dp[1<<16][16];
long long  num[1<<16][16];
int data[16];
const int INF = 999999999;
void work(){
    for(int i=0; i<(1<<16);i++)for(int j=0;j<16;j++)dp[i][j]=-INF;
    memset(num,0,sizeof(num));
    for(int i=0; i<N; i++){
        dp[1<<i][i] = 2*data[i]+2;
        num[1<<i][i] = 1;
    }

    for(int i=0; i<=((1<<N) -1); i++){
        for(int j=0; j<N; j++){
            if(dp[i][j]==-INF)continue;
            for(int k=0; k<N; k++){
                if((i>>k)&1)continue;
                int add_p = data[k]*2 +2-2*(min(data[j],data[k]));
                int ns = (1<<k)|i;
                if(dp[ns][k]<dp[i][j]+add_p){
                    dp[ns][k] = dp[i][j]+add_p;;
                }
                //cout<<"state is "<<ns<<" and now is "<<dp[ns][k]<<endl;
            }
        }
    }
    int final_s = (1<<N) -1;
    int ans = -INF,cnt=0;
    for(int i=0; i<N; i++){
        if(dp[final_s][i]>ans){
            ans = dp[final_s][i];
        }
    }

    for(int i=0; i<=((1<<N)-1); i++){
        for(int j=0; j<N; j++){
            if(dp[i][j]==-INF)continue;
            for(int k=0; k<N; k++){
                if((i>>k)&1)continue;
                int add_p = data[k]*2 +2-2*(min(data[j],data[k]));
                int ns = (1<<k)|i;
                if(dp[ns][k]==dp[i][j]+add_p){
                    num[ns][k]+=num[i][j];
                }
            }
        }
    }
    long long ans2 = 0;
    for(int i=0; i<N; i++){
        if(dp[final_s][i]==ans){
            ans2+=num[final_s][i];
        }
    }
    cout<<ans<<" "<<ans2<<endl;
}


int main(){
    while(1){
        cin>>N;
        if(N==0)break;
        for(int i=0; i<N; i++){
            cin>>data[i];
        }
        work();
    }
    return 0;
}

