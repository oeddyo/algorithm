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
int min_dis[MAXM][MAXN];
int N,M;

void work(){
    //from left to right
    for(int i=0; i<M; i++)for(int j=0; j<N; j++)min_dis[i][j] = INF;

    for(int i=0; i<M; i++){
        int idx = -1;
        int reverse_idx = -1;
        for(int j=0; j<N; j++){
            if(g[i][j]=='1'){
                idx = j;
            }
            if(idx==-1)continue;
            min_dis[i][j] = j-idx;
        }
        for(int j=N-1; j>=0; j--){
            if(g[i][j]=='1'){
                reverse_idx = j;
            }
            if(reverse_idx == -1)continue;
            min_dis[i][j] = min(min_dis[i][j], reverse_idx - j);
        }
    }
    /*
       for(int i=0; i<M; i++){
       for(int j=0; j<N; j++){
       cout<<min_dis[i][j]<<" ";
       }
       cout<<endl;
       }
       */
    int ans = INF;
    for(int j=0; j<N; j++){
        int tmp = 0;
        for(int i=0; i<M; i++){
            tmp += min_dis[i][j];
        }
        ans = min(ans, tmp);


    }
    if(ans==INF){
        cout<<-1<<endl;
    }
    else{
        cout<<ans<<endl;
    }


}

int main(){
    cin>>M>>N;
    for(int i=0; i<M; i++){
        cin>>g[i];
    }
    work();
    return 0;
}

