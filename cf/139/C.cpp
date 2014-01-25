#include <iostream>
#include <cstring>

using namespace std;

int N,M,X,Y;

const int MAXN = 1001;
int dp[MAXN][2];
string S[MAXN];
int white_counts[MAXN];
int black_counts[MAXN];
const int INF = 999999999;

int int_white[MAXN];
int int_black[MAXN];

void pre_process(){
    for(int i=0; i<M; i++){
        int cnt = 0;
        for(int j=0; j<N; j++){
            if(S[j][i]=='#')cnt++;
        }
        white_counts[i+1] = cnt;
        black_counts[i+1] = N-cnt;
    }
    int_white[1] = white_counts[1];
    int_black[1] = black_counts[1];
    for(int i=2; i<=M; i++){
        int_white[i] = int_white[i-1]+white_counts[i];
        int_black[i] = int_black[i-1] + black_counts[i];
    }
}

void work(){
    for(int i=0; i<MAXN; i++){
        dp[i][0] = dp[i][1] = INF;
    }
    dp[0][0] = 0;
    dp[0][1] = 0;
    
    pre_process();
    for(int i=0; i<=M; i++){
        for(int k=0; k<2; k++){
            for(int j=X; j<=Y; j++){
                int next = i+j;
                if(next>M)continue;
                int tmp_sum = 0;
                if(k==0){
                    //for(int q=i+1; q<=i+j; q++)tmp_sum+=black_counts[q];
                    tmp_sum = int_black[i+j] - int_black[i];
                    dp[next][1] = min(dp[next][1], dp[i][0]+tmp_sum);
                }else{
                    //for(int q=i+1; q<=i+j; q++)tmp_sum+=white_counts[q];
                    tmp_sum = int_white[i+j] - int_white[i];
                    dp[next][0] = min(dp[next][0], dp[i][1]+tmp_sum);
                }
                //cout<<"k = "<<k<<" from "<<i+X<<" to "<<i+Y<<" = "<<tmp_sum<<endl;
                //cout<<"tmpsum = "<<tmp_sum<<endl;
            }
        }
    }
    int ans = min(dp[M][0], dp[M][1]);

    cout<<ans<<endl;
}


int main(){
    memset(dp,0,sizeof(dp));
    cin>>N>>M>>X>>Y;

    for(int i=0; i<N; i++){
        cin>>S[i];
    }
    work();

    return 0;
}

