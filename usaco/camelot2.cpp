/*
ID: xieke.b1
PROB: camelot
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <string.h>
#include <cmath>
#include <cmath>

using namespace std;

ifstream fin("camelot.in");
ofstream fout("camelot.out");

typedef pair<int, int> pii;
const int MAXN = 31;
const int INF = 1000000;

int king[2], knights[MAXN*MAXN][2];
int n_knights = 0, R , C;
int dir[8][2] = {{1,2},{1,-2},{2,1},{2,-1},{-1,2},{-1,-2},{-2,1},{-2,-1}};

int dis[MAXN][MAXN][MAXN][MAXN];
bool vis[MAXN][MAXN];

typedef struct _node{
    int x, y, step;
    _node(int a, int b, int c){
        x = a, y = b, step = c;
    }
}node;

void sp_compute(int init_x, int init_y){
    memset(vis,0,sizeof(vis));
    node start(init_x, init_y, 0);
    vis[start.x][start.y] = true;
    queue<node> Q;
    Q.push(start);
    while(!Q.empty()){
        node cur = Q.front();
        Q.pop();
        dis[init_x][init_y][cur.x][cur.y] = cur.step;
        for(int i=0; i<8; i++){
            int nx = cur.x + dir[i][0];
            int ny = cur.y + dir[i][1];
            if( nx>=0 && nx<R && ny>=0 && ny<C && vis[nx][ny] == false){
                node next(nx, ny, cur.step+1);
                Q.push(next);
                vis[nx][ny] = true;
            }
        }
    }
}



void work(){
    for(int i=0; i<MAXN; i++)for(int j=0; j<MAXN; j++)for(int k=0; k<MAXN; k++)for(int m=0; m<MAXN; m++)dis[i][j][k][m]=INF;

    //memset(dis,-1,sizeof(dis));
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            sp_compute(i,j);
        }
    }

    int ans = INF;
    for(int x=0; x<R; x++){
        for(int y=0; y<C; y++){
            //cout<<x<<" "<<y<<endl;
            //all knights move directly and king moves directly
            int knights_direct = 0;
            int king_direct = max( abs(king[0]-x), abs(king[1]-y));
            for(int i=0; i<n_knights; i++){
                knights_direct += dis[ knights[i][0] ][ knights[i][1] ][ x ][ y ];
            }
            //cout<<"king_direct + knights_direct = "<<king_direct<<" + "<<knights_direct<<endl;
            ans = min(ans, king_direct+knights_direct); 

            for(int kx=0; kx<R; kx++){
                for(int ky=0; ky<C; ky++){
                    int king_indirect = max(abs(king[0]-kx), abs(king[1]-ky));

                    int gain = king_direct - king_indirect;
                    if( king_direct + knights_direct - gain >= ans)continue;

                    int this_knight = 0;
                    for(int k=0; k<n_knights; k++){
                        this_knight = dis[knights[k][0]][knights[k][1]][kx][ky] + dis[kx][ky][x][y];
                        
                        int t_ans = knights_direct - dis[knights[k][0]][knights[k][1]][x][y] + this_knight + king_indirect;
                        ans = min(ans, t_ans);
                    }
                }
            }

        }
    }
    fout<<ans<<endl;

}


int main(){
    fin>>R>>C;
    char a;
    int b;
    fin>>a>>b;
    king[0] = b-1;
    king[1] = a-'A';
    
    while(fin>>a>>b){
        knights[n_knights][0] = b-1;
        knights[n_knights][1] = a-'A';
        n_knights++;
    }
    cout<<"size of knights is "<<n_knights<<endl;
    work();
    return 0;
}

