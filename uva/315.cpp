#include <iostream>
#include <sstream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

const int MAXN = 500;
int N;
int low[MAXN], dis[MAXN];
int g[MAXN][MAXN];
bool ap[MAXN];

int order = 0;
void init(){
    memset(g,0,sizeof(g));
    memset(low, 0, sizeof(low));
    memset(dis, 0, sizeof(dis));
    memset(ap,0,sizeof(ap));
    order = 0;
}


void dfs(int cur, int par){
    dis[cur] = low[cur] = ++order;
    int child = 0;
    bool is_ap = false;
    for(int i = 0; i<N; i++){
        if(g[cur][i] && i!=par){
            if(dis[i]){
                low[cur] = min(low[cur], dis[i]);
            }else{
                child++;
                dfs(i, cur);
                low[cur] = min(low[cur], low[i]);
                if(dis[cur]<=low[i]){
                    is_ap = true;
                }
            }
        }
    }
    if((cur==par && child>1) || (cur!=par && is_ap)){
        ap[cur] = true;
    }
}

void work(){
    dfs(0,0);
    int ans = 0;
    for(int i=0; i<N; i++){
        if(ap[i]){
            ans++;
        }
    }
    cout<<ans<<endl;
}

int main(){
    while(1){
        init();
        cin>>N;
        if(N==0)break;
        string s;
        getline(cin, s);
        while(1){
            int a;
            getline(cin, s);
            istringstream is(s);
            is>>a;
            if(a==0)break;
            a--;
            int t;
            while(is>>t){
                t--;
                g[a][t]++;
                g[t][a]++;
            }
        }
        work();
    }
    return 0;
}

