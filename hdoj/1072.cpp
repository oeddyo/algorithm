#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;
const int INF = 999999999;
const int MAXN = 9;
int M,N,T,d[MAXN][MAXN];
int vis[MAXN][MAXN];
int time_map[MAXN][MAXN];

int s_x, s_y, e_x, e_y;
int dir[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};
int ans, nx, ny;
int mini[MAXN][MAXN];

int dfs(int step, int x, int y, int t){
    vis[x][y] =1;
    cout<<"marking "<<x<<" "<<y<<" "<<step<<" "<<t<<endl;
    if(x==e_x && y==e_y){
        ans = (step>ans)?(ans):(step);
        return t;
    }

                
    if(x==2&&y==0&&t==5){
        cout<<"now 3,0 is "<<vis[3][0]<<endl;
    }


    int re = t;
    for(int i=0; i<4; i++){
        nx = x+dir[i][0];
        ny = y+dir[i][1];
        if(nx>=0 && nx<N && ny>=0 && ny<M){
            if(vis[nx][ny]==0&&d[nx][ny]!=0){
                if(t-1>0){
                    if(d[nx][ny]==4){
                        int w = dfs(step+1,nx,ny,6);
                        re = max(w,re);
                    }else{
                        int w = dfs(step+1, nx,ny, t-1);
                        re = max(w,re);
                    }
                }
            }
        }
    }
    vis[x][y]=0;
    cout<<"unmarking "<<x<<" "<<y<<endl;
    return re;
}
struct node{
    int x,y,step;
};

void flood(int x,int y){
    node s;
    s.x = x,s.y=y, s.step=0;
    memset(vis,0,sizeof(vis));
    vis[x][y]=1;
    queue<node> Q;
    Q.push(s);
    node next;
    while(!Q.empty()){
        node cur = Q.front();
        Q.pop();
        //cout<<cur.x<<" "<<cur.y<<endl;
        //cout<<"before "<<mini[cur.x][cur.y]<<endl;
        mini[cur.x][cur.y] = min(cur.step,mini[cur.x][cur.y]);
        //cout<<"after "<<mini[cur.x][cur.y]<<endl;
        for(int i=0; i<4; i++){
            nx = cur.x+dir[i][0];
            ny = cur.y+dir[i][1];
            if(nx>=0&&nx<N&&ny>=0&&ny<M&&vis[nx][ny]==0&&d[nx][ny]!=0){
                next.x=nx,next.y=ny,next.step=cur.step+1;
                vis[nx][ny]=1;
                Q.push(next);
            }
        }
    }
}

void pre(){
    for(int i=0; i<N; i++){
        for(int j=0; j<M;j++){
            mini[i][j]=INF;
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(d[i][j]==4){
                flood(i,j);
            }
        }
    }
    /*for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cout<<mini[i][j]<<" ";
        }cout<<endl;
    }*/
}


void work(){
    memset(vis,0,sizeof(vis));
    ans = INF;
    pre();
    memset(vis,0,sizeof(vis));
    dfs(0,s_x, s_y, 6);
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

