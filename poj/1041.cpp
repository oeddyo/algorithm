#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 100;
typedef pair<int, int> pii;

int m;

vector< int > graph[MAXN][MAXN];
int g[MAXN][MAXN];
int used[MAXN][MAXN];

void init(){
    m = 0;
    for(int i=0; i<MAXN; i++){
        for(int j=0; j<MAXN; j++){
            graph[i][j].clear();
        }
    }
    memset(used,0,sizeof(used));
}

void dfs(vector<int> v, int cur, int pre){


}

void work(){
    for(int i=0; i<MAXN; i++){
        int t_sum = 0;
        for(int j=0; j<MAXN; j++){
            g[i][j] = graph[i][j].size();
            sort(graph[i][j].begin(), graph[i][j].end());
            t_sum += g[i][j];
        }
        if(t_sum%2==1){
            cout<<"Round trip does not exist."<<endl;
            return ;
        }
    }

    for(int i=1; i<=m; i++){
        dfs(i);
    }

    
}

int main(){
    while(1){
        init();
        int a,b,c;
        scanf("%d %d",&a,&b);
        m = max(a,b);
        if(a==0 && b==0)break;
        scanf("%d",&c);
        graph[a][b].push_back(c);
        graph[b][a].push_back(c);
        while(scanf("%d%d",&a,&b)){
            if(a==0&&b==0)break;
            scanf("%d",&c);
            m = max(m, max(a,b));
            graph[a][b].push_back(c);
            graph[b][a].push_back(c);
        }
        work();
    }
    return 0;
}

