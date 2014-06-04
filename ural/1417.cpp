#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>
#include <stack>
#include <map>
#include <set>
using namespace std;
 
#define DEBUG
#define REP(i,a) for(i=0;i<a;i++)
#define FOR(i,a,b) for(i=a;i<b;i++)
#define VE vector<int>
#define SZ size()
#define PB push_back
 
const int MAXN = 51000;
int N, M;
vector<int> G[MAXN];
vector<int> T[MAXN];
vector<int> W[MAXN]; //weight

typedef pair<int, int> pii;

vector< pii > queries;
int f[MAXN];
int r[MAXN];
int color[MAXN];
int visited[MAXN];

set< pii > my_set;

int find(int u){
    if(f[u]==u){
        return u;
    }else{
        f[u] = find(f[u]);
        return f[u];
    }
}

void _union(int u, int v){
    int a = find(u);
    int b = find(v);
    if(a==b)
        return ;
    else{
        if(r[a] > r[b]){
            f[b] = a;
        }else if(r[a] <r[b]){
            f[a] = b;
        }else if(a!=b){
            f[b] = a;
            r[a] +=1;
        }
    }
}

void LCA(int u){
    f[u] = u;
    r[u] = 0;
    cout<<"now in node "<<u<<endl;
    
    for(int i=0; i<T[u].size(); i++){
        int v = T[u][i];
        LCA(v);
        _union(u, v);
        f[find(u)] = u; // why?
    }
    color[u] = 1;
    for(int i=0; i<T[u].size(); i++){
        int v = T[u][i];
        cout<<"v = "<<v<<endl;
        if (color[v] == 1){
            cout<<"checking "<<u<<" "<<v<<endl;
            if( my_set.find(pii(u, v))!=my_set.end()){
                cout<<"ha in here"<<endl;
                cout<<"current "<<u<<" "<<v<<endl;
                cout<<"f[1] = "<<f[1]<<endl;
                cout<<"ok so f is "<<find(v)<<endl;
                cout<<u<<" and "<<v<<" LCA = "<<f[find(v)]<<endl;
                cout<<"ha in here2"<<endl;
                cout<<"ok find("<<v<<") = "<<find(v)<<" and "<<f[find(v)] <<endl;
            }
        }
    }

}


void bfs(int root){
    queue<int> q;
    q.push(root);
    visited[root] = 1;
    while(!q.empty()){
        int cur = q.front();
        q.pop();

        for(int i=0; i<G[cur].size(); i++){
            int v = G[cur][i];
            if(visited[v]==0){
                q.push(v);
                T[cur].push_back(v);
                cout<<"from "<<cur<<" to "<<v<<endl;
                visited[v] = 1;
            }
        }
    }
}



void work(){
    //int root = rand()%N;
    int root = 1;
    bfs(root);
    LCA(root);
}

int main(){

    cin>>N;
    for(int i=0; i<N-1; i++){
        int a, b, c;
        cin>>a>>b>>c;
        G[a].push_back(b);
        W[b].push_back(c);

        G[b].push_back(a);
        W[b].push_back(c);
    }
    cin>>M;
    for(int i=0; i<M; i++){
        pii tmp;
        cin>>tmp.first>>tmp.second;
        queries.push_back(tmp);
        my_set.insert(tmp);
        my_set.insert( pii(tmp.second, tmp.first));
        cout<<"in set "<<tmp.first<<" "<<tmp.second<<endl;
    }
    
    work();
    return 0;
}

