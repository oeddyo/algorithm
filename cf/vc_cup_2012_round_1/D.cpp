#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

typedef long long int ll;

const int MAXN = 50001;
//ll dp[MAXN][501];
vector<int> G[MAXN];
int N,K;

ll get_ans(int p, int k, int pre){
    //cout<<"into "<<p<<" "<<k<<endl;
    /*
    if(dp[p][k]!=-1){
        cout<<p<<" "<<k<<" already = "<<dp[p][k]<<endl;
        return dp[p][k];
    }
    */
    if(k==0){
        //cout<<"at "<<p<<" "<<k<<" return 1"<<endl;
        //dp[p][k] = 1;
        return 1;
    }

    ll tmp_ans = 0;
    for(int i=0; i<G[p].size(); i++){
        if(G[p][i]!=pre){    
            tmp_ans += get_ans(G[p][i], k-1, p);
        }

    }
    /*
    if(pre!=-1){
        tmp_ans -= dp[pre][k-1];
    }
    */

    //dp[p][k] = tmp_ans;
    return tmp_ans;
}


void work(){
    ll ans = 0;
    for(int i=1; i<=N; i++){
        //cout<<"begin "<<i<<endl;
        ans += get_ans(i, K, -1);
    }
    cout<<ans/2<<endl;
}

int main(){
    for(int i=0; i<MAXN; i++){
        for(int j=0; j<500; j++){
            //dp[i][j] = -1;
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

