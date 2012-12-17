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
int dir[4][2] = {{0,-1},{-1,0},{0,1},{1,0}};

int dfs(int x,int y, int num){
    if(x<0||x>=N || y<0 || y>=M)return -INF;

    if(vis[x][y])return num;
    int cur_state = g[x][y];
    vis[x][y] = 1;
    num++;
    int sum = 0;
    for(int i=0; i<4; i++){
        if( ((1<<i)&cur_state) == 0 ){
            int nx = x+dir[i][0];
            int ny = y+dir[i][1];
            sum += dfs(nx,ny,0);
        }
    }
    return sum+num;
}


void work(){
    int ans = -INF;
    int rooms = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            int res = dfs(i,j,0);
            //cout<<"res "<<res<<endl;
            if(res!=0){
                rooms++;
            }
            ans = max(res, ans);
        }
    }

    int ans_max = -INF;
    int pos_x, pos_y, pos_k;
    for(int j=0; j<M; j++){
        for(int i=N-1; i>=0; i--){
            int cur_state = g[i][j], tmp=-1;
            if( (cur_state& (1<<1) )!=0){
                g[i][j] &= (~(1<<1) );
                memset(vis,0,sizeof(vis));
                tmp = dfs(i,j,0);
                g[i][j] |= (1<<1);
                if(tmp>=ans_max){
                   if(i==3&&j==0){
                        cout<<"in one ok is "<<tmp<<endl;
                    }
                    ans_max = tmp, pos_x = i, pos_y = j, pos_k = 1;
                    cout<<"mmax is "<<ans_max<<endl;
                }
            }
            if( (cur_state& (1<<2) )!=0){
                if(i==3&&j==4){
                    cout<<"in two"<<endl;
                    cout<<"state is "<<g[i][j]<<endl;
                    cout<<"cur res is "<<tmp<<endl;
                }
                g[i][j] &= (~(1<<2) );
                memset(vis,0,sizeof(vis));
                tmp = dfs(i,j,0);
                g[i][j] |= (1<<2);
                if(tmp>=ans_max){
                   if(i==3&&j==0){
                        cout<<"in two ok is "<<tmp<<endl;
                    }
                    ans_max = tmp, pos_x = i, pos_y = j, pos_k = 2;
                    cout<<"mmax is "<<ans_max<<endl;
                }
            }
            if(tmp==17){
                cout<<"i and j are "<<i<<" "<<j<<" pos "<<pos_x+1<<" "<<pos_y+1<<endl;
            }


        }
    }
    
    fout<<rooms<<endl;
    fout<<ans<<endl;
    fout<<ans_max<<endl;
    fout<<pos_x+1<<" "<<pos_y+1;
    if(pos_k==1){
        fout<<" N"<<endl;
    }
    if(pos_k==2){
        fout<<" E"<<endl;
    }

    cout<<"final"<<ans<<endl;;

    cout<<ans_max<<endl;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cout<<g[i][j]<<" ";
        }cout<<endl;
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
