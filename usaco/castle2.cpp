/*
ID: xieke.b1
PROG: castle
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <stack>
#include <map>

using namespace std;

ofstream fout("castle.out");
ifstream fin ("castle.in");
const int INF = 999999999;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define all(c) (c).begin(), (c).end()
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++) 
const int MAXN = 51;
int g[MAXN][MAXN];
int N,M;

bool vis[MAXN][MAXN];
int color[MAXN][MAXN];

int dir[4][2] = {{0,-1},{-1,0},{0,1},{1,0}};

void dfs(int x,int y, int col){
    if(x<0||x>=N || y<0 || y>=M)return ;

    if(color[x][y]!=-1)return ;
    int cur_state = g[x][y];
    color[x][y] = col;
    for(int i=0; i<4; i++){
        if( (1&cur_state>>i) == 0 ){
            int nx = x+dir[i][0];
            int ny = y+dir[i][1];
            dfs(nx,ny,col);
        }
    }
}

int count(int col_a, int col_b){
    int sum = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(color[i][j]==col_a || color[i][j]==col_b){
                sum++;
            }
        }
    }
    return sum;
}


void work(){
    memset(color, -1, sizeof(color));
    int room = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(color[i][j]==-1){
                dfs(i,j,room);
                room++;
            }
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cout<<color[i][j]<<" ";
        }cout<<endl;
    }
    int max_single = -INF;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            max_single = max(max_single, count(color[i][j], color[i][j]));
        }
    }

    int ans = -INF;
    int pos_x, pos_y, pos_k;
    for(int j=M-1; j>=0; j--){
        for(int i=0; i<N; i++){
            int cur_state = g[i][j];
            //East
            if((cur_state&(1<<2))!=0){
                if(j+1<M){
                    int a = color[i][j+1];
                    int b = color[i][j];
                    if(a!=b){
                        int t_ans = count(a,b);
                        if(t_ans >= ans){
                            pos_x = i, pos_y = j, pos_k = 2, ans = t_ans;
                        }
                        //ans = max(t_ans, ans);
                    }
                }
            }
            //North
            if( (cur_state&(1<<1))!=0 ){
                if(i-1>=0){
                    int a = color[i-1][j];
                    int b = color[i][j];
                    if(a!=b){
                        int t_ans = count(a,b);
                        if(t_ans >= ans){
                            pos_x = i, pos_y = j, pos_k = 1, ans = t_ans;
                        }
                        //ans = max(t_ans, ans);
                    }
                }
            }

        }
    }

    fout<<room<<endl;
    fout<<max_single<<endl;
    fout<<ans<<endl ;
    fout<<pos_x+1<<" "<<pos_y+1<<" ";
    cout<<"dir "<<pos_k<<endl;
    if(pos_k==1){
        fout<<"N"<<endl;
    }else if(pos_k == 2){
        fout<<"E"<<endl;
    }

}

int main(){
    fin>>M>>N;
    for(int i=0; i<N; i++){
        for(int j=0; j<M;j++){
            fin>>g[i][j];
        }
    }
    work();
    return 0;
}

/*

            for(int k=3; k>=0; k--){
                if( (cur_state&(1<<k))==0 )continue;
                g[i][j] &= (~(1<<k) );
                int tmp = dfs(i,j,0);
                g[i][j] |= (1<<k);
                if(tmp>ans_max){
                    ans_max = tmp;
                    pos_x = i,pos_y = j, pos_
                    ans_max = max( ans_max, dfs(i,j,0));
                }
            }

            */
