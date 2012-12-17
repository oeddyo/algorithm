#include <iostream>
#include <queue>
#include <string.h>
#include <stdio.h>
#include <map>
using namespace std;

int K,N,R;
typedef pair<int,int> mypair;

const int MAXN = 101;
const int INF = 999999999;
//bool open[MAXN];
//bool closed[MAXN];

vector < pair<short, mypair> > g[MAXN];
typedef struct mynode{
    int s;
    int money;
    short id;
    bool operator < (const mynode &a) const{
        if(a.s == s){
            return a.money < money;
        }
        return a.s < s;
    }
}node;
int vis[MAXN][10001];
int sz[MAXN];
void work(){
    priority_queue<node> Q;
    for(int i=0; i<MAXN; i++)for(int j=0;j<10001; j++)vis[i][j]=INF;
    vis[0][K] = 0;
    node start;
    start.s = 0, start.money = K, start.id = 0;;
    Q.push(start);
    node cur, next;
    int ans = INF,cur_money, next_money;
    while(!Q.empty()){
        cur = Q.top();
        Q.pop();
        if(vis[cur.id][cur.money] < cur.s)continue;
        cout<<"cur "<<cur.id+1<<" dis is "<<cur.s<<" money is "<<cur.money<<endl;
        if(cur.id==N-1){
            ans = min(ans,cur.s);
            break;
        }
        //int sz = g[cur.id].size();
        cur_money = cur.money;
        for(int i=0; i<sz[cur.id]; i++){
            next_money = cur_money - g[cur.id][i].second.second;
            if(next_money<0)continue;
            //cout<<"at "<<cur.id<<" seeing "<<g[cur.id][i].first<<next_money<<"$ left"<<endl;
            next.id = g[cur.id][i].first;;
            next.money = next_money;
            next.s = cur.s + g[cur.id][i].second.first;
            if(vis[next.id][next.money] <= next.s)continue;
            Q.push(next);
        }
    }
    if(ans==INF){
        cout<<"-1"<<endl;
    }else{
        cout<<ans<<endl;
    }
}

int main(){
    scanf("%d %d %d",&K,&N,&R);
    for(int i=0; i<R; i++){
       int a,b,c,d;
    //   cin>>a>>b>>c>>d;
      scanf("%d%d%d%d",&a,&b,&c,&d);
       a--,b--;
       g[a].push_back( pair<int, mypair>(b,mypair(c,d)) );
       sz[a] = g[a].size();
    }
    work();
    return 0;
}
