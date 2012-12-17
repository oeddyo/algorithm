#include <iostream>
#include <queue>

using namespace std;

int N,M;
typedef struct my_node{
    int x,y;
    int steps;
}node;
const int MAXN = 201;
int vis[MAXN][MAXN];
int dir[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};
string d[MAXN];

int main(){
    while(cin>>N>>M){
        for(int i=0; i<N; i++){
            cin>>d[i];
        }
        queue<node> Q;
        memset(vis,0,sizeof(vis)); 
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(d[i][j]=='a'){
                    node t_new;
                    t_new.x = i, t_new.y = j, t_new.steps=0;
                    Q.push(t_new);
                    vis[i][j] = 1;
                }
            }
        }
        node t_next, t_cur;
        int ans = -1;
        while(!Q.empty()){
            t_cur = Q.front();
            Q.pop();
            if(d[t_cur.x][t_cur.y] == 'r'){
                ans = t_cur.steps;
                break;
            }
            for(int i=0; i<4; i++){
                int n_x = t_cur.x+dir[i][0];
                int n_y = t_cur.y+dir[i][1];
                if(n_x>=0 && n_x<N && n_y>=0 && n_y<M && vis[n_x][n_y]==0){
                    if(d[n_x][n_y] == '#'){
                        continue;
                    }
                    t_next.x = n_x;
                    t_next.y = n_y;
                    if(d[n_x][n_y] == 'x'){
                        t_next.steps = t_cur.steps+2;
                    }else{
                        t_next.steps = t_cur.steps+1;
                    }
                    Q.push(t_next);
                    vis[n_x][n_y] = 1;
                }
            }
        }
        
        if(ans==-1){
            cout<<"Poor ANGEL has to stay in the prison all his life."<<endl;
        }else{
            cout<<ans<<endl;
        }
    }
    return 0;
}

