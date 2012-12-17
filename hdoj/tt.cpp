#include <iostream>

using namespace std;

int N,M,T;
const int MAXN = 8;
char d[MAXN][MAXN];
int vis[MAXN][MAXN];
int s_x, s_y, e_x, e_y;
bool ans = false;
int n_x, n_y;
int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
int cnt = 0;


void dfs(int x, int y, int t, int left){
    if(d[x][y]=='#' || d[x][y]=='X'|| t>T ){
        return ;
    }
    if(left < T-t ){
        return ;
    }
    if((x+y)&1 == 0 && (e_x+e_y)&1 ==0 && (T-t)&1 == 1){
        return;
    }
    if((x+y)&1 == 1 && (e_x+e_y)&1 ==0 && (T- t)&1 ==0){
        return ;
    }
    if((x+y)&1 == 0 && (e_x+e_y)&1 ==1 && (T- t)&1 ==0){
        return ;
    }
    if((x+y)&1 == 1 && (e_x+e_y)&1 ==1 && (T- t)&1 ==1){
        return ;
    }
    if( abs(x-e_x) + abs(y-e_y) > T-t){
        return ;
    }

    if(ans){
        return ;
    }
    if(d[x][y]=='D'){
        if(t==T){
            ans = true;
        }
        return ;
    }
    char original = d[x][y];
    cnt++;      
    if(cnt%10000==0){
                  cout<<cnt<<endl;
          }
    d[x][y]='#';
    left -= 1;
    for(int i=0; i<4; i++){
        n_x = x+dir[i][0];
        n_y = y+dir[i][1];
        if(n_x>=0&&n_x<N&&n_y>=0&&n_y<M){
            dfs(n_x, n_y, t+1,left);
        }
    }
    left+=1;
    d[x][y]=original;

}

void work(){
    int go_able = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(d[i][j]=='S'){
                s_x=i, s_y=j;
            }
            if(d[i][j]=='D'){
                e_x=i, e_y=j;
            }
            if(d[i][j]=='.'){
                go_able++;
            }
        }
    }
    go_able++;

    memset(vis,0,sizeof(vis));
    ans = false;
    dfs(s_x, s_y, 0, go_able);
    if(ans){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }

}

int main(){
    while(1){
        scanf("%d %d %d",&N,&M,&T);
        if(N==0 &&M==0&&T==0)break;
        for(int i=0; i<N;i++){
            scanf("%s",d[i]);
        }
        work();     
    }

    return 0;
}
