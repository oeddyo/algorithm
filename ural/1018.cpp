#include <iostream>

using namespace std;

int N, Q;
int tree[101][2];
int num[101];
int dp[101][101];
const int MAXN = 101;
const int INF = 999999999;


void dfs(int now,int n_p){

    int left = tree[now][0];
    int right = tree[now][1];
    if(left==0&&right==0){
        return tree  
    }else{
        for(int i=0; i<=n_p-2; i++){

        }
    }
}


void work(){
    for(int i=0; i<MAXN; i++)for(int j=0; j<MAXN; j++)dp[i][j] = -INF;
    dfs(1,Q);
    cout<<dp[1][Q]<<endl;
}


int main(){
    cin>>N>>Q;
    int a,b,c;
    for(int i=0; i<N; i++){
        cin>>a>>b>>c;
        tree[a][num[a]++] =c; 
    }
    work();

    return 0;
}

