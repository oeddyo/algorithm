#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;
const int INF = 999999999;
const int MAXN = 9;
int M,N,T,d[MAXN][MAXN];

int s_x, s_y, e_x, e_y;
int dir[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};
int ans, nx, ny;
int vis[MAXN][MAXN];
struct node{
    int x,y,step,t;
};

void flood(int x,int y){
    node s;
    s.x = x,s.y=y, s.step=0, s.t=6;
    memset(vis,0,sizeof(vis));
    //vis[x][y]=1;
    queue<node> Q;
    Q.push(s);
    node next;
    while(!Q.empty()){
        node cur = Q.front();
        Q.pop();
        //cout<<cur.x<<" "<<cur.y<<" "<<cur.step<<" "<<cur.t<<endl;
        if(cur.x==e_x && cur.y==e_y){
            ans = cur.step;
            return ;
        }
        for(int i=0; i<4; i++){
            nx = cur.x+dir[i][0];
            ny = cur.y+dir[i][1];
            //if(nx>=0&&nx<N&&ny>=0&&ny<M&&vis[nx][ny]<2&&d[nx][ny]!=0){
            if(nx>=0&&nx<N&&ny>=0&&ny<M<2&&d[nx][ny]!=0){
                if(cur.t>1){
                    next.x=nx,next.y=ny,next.step=cur.step+1;
                    if(d[nx][ny]==4 && vis[nx][ny]==0){
                        next.t=6;
                    }else{
                        next.t = cur.t-1;
                    }
                    vis[nx][ny]++;
                    Q.push(next);
                }
            }
        }
    }
}

void work(){
    memset(vis,0,sizeof(vis));
    ans = INF;
    flood(s_x, s_y); 
    if(ans==INF){
        cout<<-1<<endl;
    }else{
        cout<<ans<<endl;
    }
}


int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&N,&M);
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                scanf("%d",&d[i][j]);
                if(d[i][j]==2){
                    s_x = i;
                    s_y = j;
                }
                if(d[i][j]==3){
                    e_x = i;
                    e_y = j;
                }
            }
        }
        work();
    }
    return 0;
}

