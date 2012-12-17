#include <iostream>

using namespace std;

int N;

int g[30][30];

int vis[30];
int t_v[30];
int ans = -1;
void dfs(int node){
    if(vis[node]!=0){
        return ;
    }
    //cout<<node<<endl;
    memset(t_v,0,sizeof(t_v));
    for(int j=0; j<N; j++){
        if(g[node][j] && vis[j]>0){
            t_v[vis[j]] = 1;
        }
    }
    int p = -1;
    for(int i=1; i<=N; i++){
        if(t_v[i]==0){
            p = i;
            break;
        }
    }
    vis[node] = p;
    if(p>ans){
        ans = p;
    }
    
    for(int j=0; j<N; j++){
        if(g[node][j]){
            dfs(j);
        }
    }
}

void work(){
    ans = -1;
    memset(vis,0,sizeof(vis));
    for(int i=0; i<N; i++){
        dfs(i);
    }
    if(ans<=1){
        cout<<ans<<" channel needed."<<endl;
    }else{
        cout<<ans<<" channels needed."<<endl;
    }
}


int main(){
    while(1){
        scanf("%d",&N);
        memset(g,0,sizeof(g));
        if(N==0)break;
        char s;
        char adj[30];
        for(int i=0; i<N; i++){
            scanf("%s",adj);
            for(int j=2; j<strlen(adj); j++){
                g[i][adj[j]-'A'] = 1;
            }
        }
        /*
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cout<<g[i][j]<<" ";
            }cout<<endl;
        }
        */
        work(); 
    
    }

    return 0;
}

