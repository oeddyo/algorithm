/*
ID: xieke.b1
PROB: maze1
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <stack>
#include <vector>
#include <string.h>
#include <queue>

using namespace std;
ifstream fin("maze1.in");
ofstream fout("maze1.out");

typedef pair<int, int> pii;
typedef pair< pii, int> piii;
const int INF = 999999999;
const int MAXN = 500;
string g[MAXN];
int W,H;

bool is_bound(int x,int y){
    int r_W = W*2+1;
    int r_H = H*2+1;
    if(x==0 || x==r_H-1 || y==0 || y==r_W-1){
        return true;
    }
    return false;
}
bool could_go(int x,int y){
    if(x>0 && x<2*H+1 && y>0 & y<2*W+1 && g[x][y]==' '){
        return true;
    }
    return false;
}

bool is_exit(int x,int y){
    if(is_bound(x,y) && g[x][y] == ' '){
        return true;
    }
    return false;
}

int sp1[MAXN][MAXN];
int sp2[MAXN][MAXN];
bool vis[MAXN][MAXN];
int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
void bfs(int x, int y, int sp[][MAXN]){
    memset(vis,0,sizeof(vis));
    for(int i=0; i<MAXN; i++){
        for(int j=0; j<MAXN; j++){
            sp[i][j] = INF;
        }
    }
    cout<<"in bfs"<<endl;
    vis[x][y] = true;
    queue< pair<pii, int> > Q;
    piii start(pii(x,y), 0);
    Q.push(start);
    while(!Q.empty()){
        piii cur = Q.front();
        Q.pop();
        int cur_x = cur.first.first;
        int cur_y = cur.first.second;
        for(int i=0; i<4; i++){
            int nx = cur_x+dir[i][0];
            int ny = cur_y+dir[i][1];
            if(could_go(nx, ny) && vis[nx][ny]==false){
                piii n_state( pii(nx, ny), cur.second+1);
                Q.push(n_state);
                sp[nx][ny] = (cur.second+1);
                vis[nx][ny] = true;
            }
        }
    }
    for(int i=0; i<2*H+1; i++){
        for(int j=0; j<2*W+1; j++){
            if(sp[i][j]==INF){
                cout<<"*\t";
            }else{
                cout<<(sp[i][j]+1)/2<<"\t";
                sp[i][j] = (sp[i][j]+1)/2;
            }
            //cout<<sp[i][j]<<"\t";
        }cout<<endl;
    }
}


void work(){
    bool first = false;
    cout<<"see is "<<is_exit(5,10)<<endl;

    for(int i=0; i<2*H+1; i++){
        for(int j=0; j<2*W+1; j++){
            if(is_exit(i,j) && first==false){
                first = true;
                cout<<"try to go to 1 bfs "<<i<<" "<<j<<endl;
                bfs(i,j,sp1);
                continue;
            }
            if(is_exit(i,j) && first==true){
                cout<<"try to go to 2 bfs "<<i<<" "<<j<<endl;
                bfs(i,j,sp2);
            }
        }
    }
    
    int ans = -INF;
    for(int i=0; i<2*H+1; i++){
        for(int j=0; j<2*W+1; j++){
            int tmp = INF;
            if(sp1[i][j]==INF || sp2[i][j]==INF)continue;
                tmp = min(tmp,(sp1[i][j]));
                tmp = min(tmp, (sp2[i][j]));
            ans = max(ans, tmp);
        }
    }
    fout<<ans<<endl;
}


int main(){
    fin>>W>>H;
    getline(fin, g[0]);
    for(int i=0; i<H*2+1; i++){
        getline(fin, g[i]);
        //fin>>g[i];
    }
    cout<<"----"<<endl;
    for(int i=0; i<H*2+1; i++){
        cout<<g[i]<<endl;
    }

    work();
    return 0;
}

