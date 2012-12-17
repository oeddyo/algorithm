#include <iostream>
#include <map>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;
vector < pii > stamp;

map<string, int> mymap;
int N,M;
const int MAXN = 240;
int g[MAXN][MAXN];

int global_t;
int test_case = 0;
string alco[MAXN];

bool vis[MAXN];

void dfs(int cur){
    if(vis[cur])return ;
    vis[cur]=1;
    global_t++;
    for(int i=0; i<N; i++){
        if(g[cur][i]){
            dfs(i);
        }
    }
    global_t++;
    stamp.push_back( pii(global_t, cur));
}


void work(){
    global_t = 0;
    memset(vis,0,sizeof(vis));
    for(int i=0; i<N; i++){
        dfs( mymap[alco[i]]);
    }
    sort(stamp.rbegin(), stamp.rend());
   
    cout<<"Case #"<<test_case<<": Dilbert should drink beverages in this order:";
    for(int i=0; i<N; i++){
        cout<<" "<<alco[stamp[i].second];
    }
    cout<<"."<<endl;
}

void init(){
    memset(vis,0,sizeof(vis));
    memset(g,0,sizeof(g));
    stamp.clear();

}

int main(){
    int blank = 0;
    while(cin>>N){
        init();
        mymap.clear();
        if(blank!=0){
            cout<<endl;
        }
        test_case++;
        blank++;
        string s;
        string s1,s2;
        for(int i=0; i<N; i++){
            cin>>s;
            alco[i] = s;
            mymap[s] = i;
        }
        cin>>M;
        for(int i=0; i<M; i++){
            cin>>s1>>s2;
            g[mymap[s1]][mymap[s2]] = 1;
        }
        work();
    }

    return 0;
}

