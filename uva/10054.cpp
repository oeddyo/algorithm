#include <iostream>
#include <vector>
#include <string.h>
using namespace std;


const int MAXN = 100;
int N, n_case;
int g[MAXN][MAXN], start;
vector<int> ans;
void dfs(int cur){
    for(int i=0; i<MAXN; i++){
        if(g[cur][i]>0){
            g[cur][i]--;
            g[i][cur]--;
            dfs(i);
        }
    }
    ans.push_back(cur);
}

void work(){
    for(int i=0; i<MAXN; i++){
        int t_sum = 0;
        for(int j=0; j<MAXN; j++){
            t_sum+=g[i][j];
        }
        if(t_sum%2!=0){
            cout<<"some beads may be lost"<<endl;
            return ;
        }
    }
    
    dfs(start);
    int sz = ans.size();
    for(int i=0; i<sz-1; i++){
        cout<<ans[i]<<" "<<ans[i+1]<<endl;
    }
}

int main(){
    int T,a,b;
    int blank= 0;
    cin>>T;
    for(n_case=1; n_case<=T; n_case++){
        if(blank>=1)cout<<endl;
        blank++;
        cin>>N;
        memset(g,0,sizeof(g));
        ans.clear();
        cout<<"Case #"<<n_case<<endl;
        for(int j=0; j<N; j++){
            cin>>a>>b;
            g[a][b] += 1;
            g[b][a] += 1;
            start = a;
        }
        work();
    }
    return 0;
}

