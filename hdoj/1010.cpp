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
bool stop_all = false;

void dfs(int x, int y, int t, int left){
    if(ans){
        return ;
    }
    int tt_t = abs(x-e_x)+abs(y-e_y);
    if(t>T){
        return ;
    }
    if((tt_t + T-t)&1==0){
        return ;
    }
    if(left < T-t ){
        return ;
    }
    if( tt_t > T-t){
        return ;
    }
    if(d[x][y]=='D'){
        if(t==T){
            ans = true;
        }
        return ;
    }
    char original = d[x][y];
    /*
    cnt++;
    if(cnt%10000==0){
        cout<<cnt<<endl;
    }
*/
    d[x][y]='#';
    left -= 1;
    for(int i=0; i<4; i++){
        n_x = x+dir[i][0];
        n_y = y+dir[i][1];
        if(n_x>=0&&n_x<N&&n_y>=0&&n_y<M && (d[n_x][n_y]=='.'||d[n_x][n_y]=='D')){
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
        
    ans = false;
    dfs(s_x, s_y, 0, go_able);
    if(ans){
        printf("YES\n");
    }else{
        printf("NO\n");
    }

}

int main(){
    while(scanf("%d%d%d",&N,&M,&T)!=EOF){
        if(N==0 &&M==0&&T==0)break;
        for(int i=0; i<N;i++){
            scanf("%s",d[i]);
        }
        work();     
    }

    return 0;
}

