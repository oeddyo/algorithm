#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string.h>

using namespace std;
const int INF = 99999999;
const int MAXM = 1001;
const int MAXN = 10001;
char g[MAXM][MAXN];

int pos[MAXM][MAXN];
int N,M;
int sum[MAXN*2+1];
bool pre_process(){
    for(int i=0; i<M; i++){
        memset(sum,0,sizeof(sum)); 
        int t = 0;
        sum[0] = g[i][0]-'0';
        for(int j=1; j<N; j++){
            sum[j] = sum[j-1]+g[i][j]-'0';
        }
        if(sum[N-1]==0){
            return false;
        }
        for(int j=N; j<2*N; j++){
            sum[j] = sum[j-1]+g[i][j-N]-'0';
        }
        for(int j=N; j<2*N; j++){
            if(g[i][j-N]=='0'){
                int* left = lower_bound(sum, sum+2*N, sum[j]);
                int* right = upper_bound(sum+j, sum+2*N, sum[j]) ;
                pos[i][j-N] = min((&sum[j]-left), (right-&sum[j]) );
            }else{
                pos[i][j-N] = 0;
            }
        }
    }
    return true;
}

void work(){
    if(!pre_process()){
        cout<<-1<<endl;
        return ;
    }
    /*
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            cout<<pos[i][j];
        }cout<<endl;
    }
    */
    int ans = INF;
    for(int col = 0; col<N; col++){
        int t_sum = 0;
        for(int r = 0; r<M; r++){
            t_sum+=pos[r][col];
        }
        ans = min(ans, t_sum);
    }
    cout<<ans<<endl;
}

int main(){
    cin>>M>>N;
    for(int i=0; i<M; i++){
        cin>>g[i];
    }
    work();
    return 0;
}

