#include <iostream>
#include <queue>
#include <stdio.h>
#include <string.h>
using namespace std;

int N;
char order[10];
int dir[6][3] = {
    {0,0,1},
    {0,1,0},
    {1,0,0},
    {0,0,-1},
    {0,-1,0},
    {-1,0,0}
};
const int MAXN = 20;
int vis[MAXN][MAXN][MAXN];
char map[MAXN][MAXN][MAXN];
typedef struct my_node{
    int x,y,z,steps;
}node;

int s_x, s_y, s_z;
int e_x, e_y, e_z;


int main(){
    while(scanf("%s %d",order, &N)!=EOF){
        for(int k=0; k<N; k++){
            for(int i=0; i<N; i++){
                scanf("%s",map[i][k]);
            }
        }
        /*
        cout<<"______________"<<endl;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cout<<map[j][i]<<endl;
            }
        }
        cout<<"--------------"<<endl; 
        */
        scanf("%d%d%d",&s_x,&s_y,&s_z);
        scanf("%d%d%d",&e_x,&e_y,&e_z);
        swap(s_x,s_y);
        swap(e_x,e_y);
        swap(s_y,s_z);
        swap(e_y,e_z);
        memset(vis,0,sizeof(vis));
        node cur,next;
        cur.x = s_x, cur.y = s_y, cur.z = s_z, cur.steps=0;
        vis[cur.x][cur.y][cur.z]=1;
        queue<node> Q;
        Q.push(cur);
        int ans = -1;
        while(!Q.empty()){
            cur = Q.front();
            Q.pop();
            //cout<<cur.x<<" "<<cur.y<<" "<<cur.z<<" "<<map[cur.x][cur.y][cur.z]<<endl;
            if(cur.x==e_x && cur.y==e_y && cur.z == e_z){
                ans = cur.steps;
                break;
            }
            for(int i=0; i<6; i++){
                int n_x = cur.x+dir[i][0];
                int n_y = cur.y+dir[i][1];
                int n_z = cur.z+dir[i][2];
                if(n_x >=0 && n_x<N && n_y>=0 && n_y<N && n_z>=0 && n_z<N && vis[n_x][n_y][n_z]==0&& map[n_x][n_y][n_z]!='X'){
                    next.x = n_x, next.y = n_y, next.z = n_z, next.steps = cur.steps+1;
                    vis[n_x][n_y][n_z]=1;
                    Q.push(next);
                }
            }
        }
        scanf("%s",order);
        if(ans==-1){
            cout<<"NO ROUTE"<<endl;
        }else{
            cout<<N<<" "<<ans<<endl;
        }
    }
    return 0;
}

