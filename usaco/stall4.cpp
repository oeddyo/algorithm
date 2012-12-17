/*
ID: xieke.b1
PROB: stall4
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

using namespace std;

ifstream fin("stall4.in");
ofstream fout("stall4.out");

const int INF = 2100000000;
const int MAXN = 501;
int fix = 200;
int N,M;
int g[MAXN][MAXN];

int bfs(int start, int end){
    queue<int> Q;
    Q.push(start);
    bool vis[MAXN];
    int path[MAXN];
    memset(vis,0,sizeof(vis));
    memset(path,-1,sizeof(path));
    vis[start] = true;
    while(!Q.empty()){
        int cur = Q.front();
        Q.pop();
        if(cur==end){
            int tmp = end;
            int t_value = INF;
            while(path[tmp]!=-1){
                t_value = min(t_value, g[path[tmp]][tmp]);
                tmp = path[tmp];
            }
            tmp = end;
            while(path[tmp]!=-1){
                g[path[tmp]][tmp] -= t_value;
                g[tmp][path[tmp]] += t_value;
                tmp = path[tmp];
            }
            return t_value;
        }
        for(int i=0; i<MAXN; i++){
            if(g[cur][i]>0 && vis[i]==false){
                Q.push(i);
                vis[i] = true;
                path[i] = cur;
            }
        }
    }
    return INF;
}


void work(){
    int ans = 0;
    while(true){
        int t = bfs(0,500);
        cout<<"aug = "<<t<<endl;
        if(t==INF)break;
        ans += t ;
    }
    
    fout<<ans<<endl;
}


int main(){
    fin>>N>>M;
    int S,t;
    for(int i=1; i<=N; i++){
        fin>>S;
        for(int j=1; j<=S; j++){
            fin>>t;
            cout<<"ok "<<i<<" "<<t+fix<<endl;
            g[i][t+fix] = 1;
        }
    }
    for(int i=1; i<=N; i++){
        g[0][i] = 1;
    }
    for(int i=1; i<=M; i++){
        g[i+fix][500] = 1;
    }
    

    for(int i=0; i<MAXN; i++){
        for(int j=0; j<MAXN; j++){
            if(g[i][j]){
                cout<<"g["<<i<<"]["<<j<<"] = "<<g[i][j]<<endl;
            }
        }
    }
    work();

    return 0;
}

