#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
#include <stdio.h>
using namespace std;

int N,M;
const int MAXN = 40001;
typedef pair<int, int> mypair;
vector < mypair > g[MAXN];

int vis[MAXN];
int sz[MAXN];

struct node{
    int pos;
    int sum_len;
};

int bfs(int start, int &fur){
    memset(vis,0,sizeof(vis));
    queue< mypair > Q;
    Q.push( mypair(start, 0) );
    mypair cur, next;
    int ans = -1;
    vis[start]=1;
    while(!Q.empty()){
        cur = Q.front();
        Q.pop();
        if(cur.second > ans){
            ans = cur.second;
            fur = cur.first;
        }
        for(int i=0; i<sz[cur.first]; i++){
            int dis = g[cur.first][i].second;
            int next_pos = g[cur.first][i].first;
            if(vis[next_pos]==0){
                vis[next_pos]=1;
                Q.push( mypair(next_pos, dis+cur.second));
            }
        }
    }
    return ans;
}

void work(){
    for(int i=1; i<=N; i++)sz[i] = g[i].size();
    int fur = 0;
    bfs(1,fur );
    int t=-1; 
    int ans = bfs(fur, t);
    //cout<<ans<<endl;
/*
    for(int i=1; i<=N; i++){
        if(sz[i] == 1){
            int t = bfs(i);
            ans = max(ans,t);
            //start = i;
        }
    }
  */
    //bfs(start);
    cout<<ans<<endl;
}


int main(){
    scanf("%d%d",&N,&M);
    int a,b,c;
    char d;
    for(int i=0; i<N-1; i++){
        a--,b--;
        scanf("%d %d %d %c",&a,&b,&c,&d);
        //cin>>a>>b>>c>>d;
        g[a].push_back(mypair(b,c));
        g[b].push_back(mypair(a,c));
    }
    work();
    return 0;
}

