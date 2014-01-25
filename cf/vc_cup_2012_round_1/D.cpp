#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

typedef long long int ll;

const int MAXN = 50001;
ll dp[MAXN][501];
vector<int> G[MAXN];
int N,K;

ll get_ans(int p, int k){
    //cout<<"into "<<p<<" "<<k<<endl;
    if(k==0){
        dp[p][k] = 1;
        return 1;
    }
    if(dp[p][k]!=-1){
        cout<<p<<" "<<k<<" already = "<<dp[p][k]<<endl;
        return dp[p][k];
    }
    
    ll tmp_ans = 0;
    for(int i=0; i<G[p].size(); i++){
        int u = G[p][i];
        for(int x=1; x<k; x++){
            ll ta,tb,tc;
            ta = get_ans(u, x-1);
            tb = get_ans(p, k-x);
            tc = get_ans(u, k-x-1);
            tmp_ans += ta*(tb - tc);
            //tmp_ans+=dp[u][x-1]*(dp[p][k-x] - dp[u][k-x-1]); 
        }
        //tmp_ans += get_ans(G[p][i], k-1, p);
    }
    cout<<"tmp = "<<tmp_ans<<endl;
    dp[p][k] = tmp_ans/2;
    return dp[p][k];
}


void work(){
    ll ans = 0;
    for(int i=1; i<=N; i++){
        ans += get_ans(i, K);
    }
    cout<<ans<<endl;
}

int main(){
    for(int i=0; i<MAXN; i++){
        for(int j=0; j<500; j++){
            dp[i][j] = -1;
        }
    }

    scanf("%d%d",&N,&K);
    for(int i=0; i<N-1; i++){
        int a,b;
        scanf("%d%d",&a,&b);
        G[a].push_back(b);
        G[b].push_back(a);
    }
    //cout<<"ready to work"<<endl; 
    work();

    return 0;
}

