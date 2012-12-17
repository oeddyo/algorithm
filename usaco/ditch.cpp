/*
ID: xieke.b1
PROB: ditch
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <stack>
#include <vector>
#include <string.h>
#include <cmath>
#include <iomanip>
#include <queue>

using namespace std;
ifstream fin("ditch.in");
ofstream fout("ditch.out");

const int INF = 2100000000;
const int MAXN = 300;
int N,M, g[MAXN][MAXN];

int bfs(int source, int end){
    int path[MAXN];
    bool vis[MAXN];
    memset(path,-1,sizeof(path));
    memset(vis,0,sizeof(vis));
    queue<int> Q;
    Q.push(source);
    vis[source] = true;
    while(!Q.empty()){
        int cur = Q.front();
        Q.pop();
        cout<<cur<<endl;
        if(cur==end){
            int value = INF;
            while( path[cur]!=-1 ){
                value = min(value, g[path[cur]][cur]);
                cur = path[cur];
            }
            cur = end;
            while( path[cur]!=-1 ){
                g[path[cur]][cur] -= value;
                g[cur][path[cur]] += value;
                cur = path[cur];
            }
            return value;
        }
        for(int i=1; i<=M; i++){
            if(g[cur][i]>0 && vis[i]!=true){
                Q.push(i);
                vis[i] = true;
                path[i] = cur;
            }
        }
    }
    return INF;
}

void work(){
    int res = 0;
    while(1){
        int value = bfs(1, M);
        cout<<value<<endl;
        if(value==INF){
            break;
        }else{
            res += value; 
        }
    }
    fout<<res<<endl;
}


int main(){
    fin>>N>>M;
    memset(g,0,sizeof(g));
    for(int i=0; i<N; i++){
        int a,b,c;
        fin>>a>>b>>c;
        g[a][b] += c;
        cout<<"ha"<<endl;
    }
    cout<<"here"<<endl;
    work();


    return 0;
}

