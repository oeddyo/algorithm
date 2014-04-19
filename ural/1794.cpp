#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>

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


int N;
int sink;
const int MAXN = 10005*3, INF = 99999999; 
typedef pair<int, int> pii;
vector< pii > graph[MAXN];
vector< pii > residual[MAXN];
bool visited[MAXN];
int pre[MAXN];

pii* get(int a, int b){
    for(int i=0; i<residual[a].size(); i++){
        if(a==1 && b == 2){
            cout<<"special "<<residual[a][i].first<<" "<<residual[a][i].second<<endl;
        }

        if(residual[a][i].first == b){
            return &residual[a][i];
        }
    }
    return NULL;
}


bool bfs(){
    memset(visited, 0, sizeof(visited));
    memset(pre, -1, sizeof(pre));
    visited[0] = true;
    queue<int> Q;
    Q.push(0);
  
    bool path = false;

    while(!Q.empty()){
        int cur = Q.front();
        Q.pop();
        cout<<"now at "<<cur<<endl;
        if(cur==sink){
            path = true;
            break;
        }
        for(int i=0; i<residual[cur].size(); i++){
            cout<<"looking at "<<i<<endl;
            if(residual[cur][i].second <= 0)continue;
            cout<<"pass"<<endl;
            int next = residual[cur][i].first;
            if(visited[next]==false){
                Q.push(next);
                visited[next] = true;
                pre[next] = cur;
            }
        }
    }

    cout<<"out"<<endl;
    cout<<"path = "<<path<<endl;
    if(path==false)return false;

    usleep(3000); 

    int cur = sink;
    int weight = INF;;
    while(pre[cur]!=-1){
        cout<<"back at "<<cur<<endl;
        int p = pre[cur];
        pii* tmp = get(p, cur);
        cout<<"weight of "<<p<<" to "<<cur<<" = "<<tmp->second<<endl;
        weight = min(weight, tmp->second);
        cur = pre[cur];
    }

    cout<<"my weight = "<<weight<<endl;
    cur = sink;
    
    while(pre[cur]!=-1){
        cout<<"ok im at "<<cur<<endl;
        int p = pre[cur];
        //cout<<"res = "<<residual[p][cur].second<<" "<<residual[cur][p].second<<endl;
        
        pii* tmp_a = get(p, cur);
        tmp_a->second -= weight;
        pii* tmp_b = get(cur, p);
        tmp_b->second += weight;

        cout<<"kk "<<tmp_a->second<<" "<<tmp_b->second<<endl;

        //residual[p][cur].second -= weight;
        //residual[cur][p].second += weight;
        cur = pre[cur];
    }
    return true;
}



void work(){
    while(1){
        bool ok = bfs();
        if(ok == false)break;
    }


    cout<<"printing network"<<endl;

    for(int i=1; i<=N; i++){

        for(int j=0; j<residual[i].size(); j++){
            cout<<i<<" "<<residual[i][j].first<<" "<<residual[i][j].second<<endl;
        }
    }

        


    cout<<"ready"<<endl;
    cout<<"N = "<<N<<endl;
    for(int i=1; i<=N; i++){
        pii* tmp = get(N+1, i);
        cout<<"check "<<i<<" "<<N+1<<endl;
        if(tmp==NULL){
            cout<<"null "<<endl;
            continue;
        }

        if(tmp->second!= 0){
            cout<<"ans = "<<endl;
            cout<<tmp->first<<endl;
        }
    }
}

int main(){
    cin>>N;
    sink = N*2+1;
    cout<<"sink = "<<sink<<endl;
    for(int i=1; i<=N; i++){
        int t;
        cin>>t;
        t = t + N;
        graph[i].push_back(pii(t, INF) );
        graph[t].push_back(pii(i, 0));

        graph[0].push_back(pii(i, 1));
        graph[i].push_back(pii(0, 0));



        graph[t].push_back(pii(sink, 1));
        graph[sink].push_back(pii(t, 0));
    }
    for(int i=0; i<=sink; i++){
        residual[i] = graph[i];
    }
    cout<<"ok here"<<endl;

    work();

    return 0;
}



