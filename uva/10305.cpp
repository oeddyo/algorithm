#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int n,m;
const int MAXN = 110;
vector<int> g[MAXN];
int global_t;
bool vis[MAXN];
int ok[MAXN];
typedef pair<int, int> pii;
vector< pii > res;

void dfs(int cur){
    if(vis[cur])return ;
    vis[cur] = true;
    global_t++;
    int sz = g[cur].size();
    for(int i=0; i<sz; i++){
        dfs(g[cur][i]);
    }
    global_t++;
    res.push_back(pii( global_t, cur));
}

void work(){
    global_t = 0;
    for(int i=1; i<=n; i++){
        dfs(i);
    }
    sort(res.rbegin(), res.rend() );
    for(int i=0; i<res.size()-1; i++){
    //    cout<<res[i].first<<" "<<res[i].second<<endl;
        cout<<res[i].second<<" ";
    }
    cout<<res[res.size()-1].second<<endl;

}

void init(){
    for(int i=0; i<MAXN; i++)g[i].clear();
    memset(vis,0,sizeof(vis));
    res.clear();
}

int main(){
    while(cin>>n>>m){
        if(n==0&&m==0)break;
        int a,b;
        init();    
        for(int i=0; i<m; i++){
            cin>>a>>b;
            g[a].push_back(b);
        }
        work();

    }
    return 0;
}
