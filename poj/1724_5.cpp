#include <iostream>
#include <queue>
#include <string.h>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;

int K,N,R;
typedef pair<int,int> mypair;

const int MAXN = 101;
const int INF = 999999999;

vector < pair<short, mypair> > g[MAXN];
int sz[MAXN];

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
void work(){
    for(int i=0; i<MAXN; i++)for(int j=0; j<10001; j++)vis[i][j] = INF;
    int cnt = 0;
    //priority_queue<node> Q;
    set<node> Q;
    node start;
    start.s = 0, start.money = K, start.id = 0;;
    //Q.push(start);
    Q.insert(start);
    node cur, next;
    int ans = INF,cur_money, next_money;
    vis[start.id][start.money] = 0;
    while(!Q.empty()){
        cur = *Q.begin();
        //cout<<cur.id<<" "<<cur.money<<" "<<cur.s<<" "<<endl;
        //cur = Q.top();
        //Q.pop();
        Q.erase(Q.begin());
        //if(cur.s <= vis[cur.id][cur.money]){
        if(cur.id==N-1){
            ans = min(ans,cur.s);
            break;
        }
        cur_money = cur.money;
        for(int i=0; i<sz[cur.id]; i++){
            next_money = cur_money - g[cur.id][i].second.second;
            if(next_money<0)continue;
            if(vis[g[cur.id][i].first][next_money]<=cur.s+g[cur.id][i].second.first)continue;
            //Q.erase( Q.find(cur));
            node p;
            p.id = g[cur.id][i].first, p.money = next_money, p.s = next_money;
            Q.erase(p);

            next.id = g[cur.id][i].first;;
            next.money = next_money;
            next.s = cur.s + g[cur.id][i].second.first;
            vis[next.id][next_money] = next.s;
            //Q.push(next);
            Q.insert(next);    
        }
   // }
    }
    if(ans==INF){
        cout<<"-1"<<endl;
    }else{
        cout<<ans<<endl;
    }
}

/*void init(){
  for(int i=0; i<MAXN; i++){
  for(int j=0; j<MAXN; j++){
//dis[i][j] = INF;
cost[i][j] = INF;
}
}
}
*/
int main(){
    cin>>K;
    cin>>N;
    cin>>R;
    //   init();
    for(int i=0; i<R; i++){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        a--,b--;
        g[a].push_back( pair<int, mypair>(b,mypair(c,d)) );
        reverse(g[a].begin(), g[a].end());
    }
    for(int i=0; i<MAXN; i++){
        sz[i] = g[i].size();
    }
    
    work();
    return 0;
}
