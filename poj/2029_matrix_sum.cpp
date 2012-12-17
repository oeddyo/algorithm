#include <iostream>
#include <stdio.h>
#include <string.h>
#define INF 99999999
#define MAXN 102
using namespace std;
int N, W, H,S,T;
short map[MAXN][MAXN];
int c[MAXN][MAXN];

void work(){
    // W==col, H==row
    // S==col, T==row
    memset(c,0,sizeof(c));
    for(int j=1; j<=W; j++){
        for(int i=1; i<=H; i++){
            c[i][j] = c[i-1][j]+map[i][j];
            //cout<<"c["<<i<<"]["<<j<<"] is "<<c[i][j]<<endl;
        }
    }
    int ans = -INF;
    //cout<<"T S "<<T<<" "<<S<<endl;
    int tmp[MAXN];
    for(int i=1; i<=H; i++){
        int sum=0;
        int ptr=0;
        for(int j=1; j<=W; j++){
            //if(i+T-1>H || j+S-1>W)continue;
            if(i+T-1>H)break;
            int cur = c[i+T-1][j] - c[i-1][j];
            sum+=cur;
            //cout<<"adding "<<cur<<endl;
            tmp[ptr] = cur;
            if(j>S){
                sum-=tmp[ptr-S];
                //cout<<"substract "<<tmp[ptr-S]<<endl;
            }
            if(sum>ans){
                ans = sum;
            }
            ptr++;
        }
    }
    cout<<ans<<endl;
}

int main(){
    while(scanf("%d",&N)){
        if(N==0)break;
        memset(map,0,sizeof(map));
        scanf("%d %d",&W,&H);
        int a,b;
        for(int i=0; i<N; i++){
            scanf("%d %d",&a,&b);
            map[b][a] = 1;
        }
        scanf("%d %d",&S,&T);
        work();
    }

    return 0;
}

