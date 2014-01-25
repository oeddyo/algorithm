#include<cstdio>
#include<iostream>
#include<sstream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<climits>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
#include<stack>
#include<set>
#include<map>
#define INF 0x3f3f3f3f
#define eps 1e-8
using namespace std;

const int MAXN=51000;
const int MAXM=510;
int d[MAXN][MAXM];
vector<int>M[MAXN];
long long ans;
int n,k;

void dfs(int u, int p) {
    d[u][0]=1;
    cout<<"in "<<u<<endl;
    for(int i=0; i<M[u].size(); i++) {
        int v=M[u][i];
        if(v==p) {
            continue;
        }
        dfs(v,u);
        for(int j=0; j<k; j++) {
            cout<<"multiplying d["<<v<<"]["<<j<<"] = "<<d[v][j]<<" d["<<u<<"]["<<k-1-j<<"] =  "<<d[u][k-1-j]<<endl;
            ans+=(long long)d[v][j]*d[u][k-1-j];
        }
        for(int j=0; j<=k; j++) {
            d[u][j+1]+=d[v][j];
        }
    }
}

int main() {
    cin>>n>>k;
    for(int i=1; i<n; i++) {
        int u,v;
        cin>>u>>v;
        //u--;
        //v--;
        M[u].push_back(v);
        M[v].push_back(u);
    }
    ans=0;
    dfs(0,-1);
    cout<<ans<<endl;
    return 0;
}
