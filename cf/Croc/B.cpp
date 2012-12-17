#include <iostream>
#include <queue>
#include <string.h>
#include <stdio.h>

using namespace std;
int m,n;
const int MAXN = 1001;
char d[MAXN][MAXN];
int vis[MAXN][MAXN];
typedef struct my_col{
    int x,  y;
    int step;
}col;
vector <int> my_x[MAXN];
vector <int> my_y[MAXN];
void work(){
    queue <col> Q;
    memset(vis,0,sizeof(vis));
    col c;
    for(int i=0; i<m; i++){
        if(d[n-1][i]=='#'){
            c.x = n-1;
            c.y = i;
            c.step=1;
            vis[n-1][i]=0;
            Q.push(c);
        }
    }
    int ans = -1;
    while(!Q.empty()){
        col cur = Q.front();
        Q.pop();
        if(cur.x==0){
            ans = cur.step;
            break;
        }
        col next;
        int t_sz = my_y[cur.y].size();
        for(int i=0; i<t_sz; i++){
            if(!vis[my_y[cur.y][i]][cur.y]&&d[my_y[cur.y][i]][cur.y]=='#'){
                next.x = my_y[cur.y][i], next.y=cur.y, next.step=cur.step+1;
                Q.push(next);
                vis[my_y[cur.y][i]][cur.y]=1;
            }
        }

        t_sz = my_x[cur.x].size();
        for(int i=0; i<t_sz; i++){
            if(!vis[cur.x][my_x[cur.x][i]] && d[cur.x][my_x[cur.x][i]]=='#'){
                next.x = cur.x, next.y = my_x[cur.x][i], next.step=cur.step+1;
                Q.push(next);
                vis[cur.x][my_x[cur.x][i]]=1;
            }
        }
    }
    cout<<ans<<endl;
}

int main(){
    scanf("%d %d",&n,&m);
    for(int i=0; i<n; i++){
        scanf("%s",d[i]);
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(d[i][j]=='#'){
                my_x[i].push_back(j);
                my_y[j].push_back(i);
            }
        }
    }

    work();
    return 0;
}
