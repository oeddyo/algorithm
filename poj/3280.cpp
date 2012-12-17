#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
const int MAXN = 2005;
char s[MAXN];
int N,M,d[27][2];
int dp[MAXN][MAXN];

const int INF = 99999999;
int get_dp(int b, int e){
    if(dp[b][e]!=INF)return dp[b][e];
    if(b>=e)return 0;
    int t1 = get_dp(b,e-1)+ d[s[e]-'a'][0];
    int t2 = get_dp(b+1,e)+ d[s[b]-'a'][0];
    int t3 = get_dp(b+1,e)+ d[s[b]-'a'][1];
    int t4 = get_dp(b,e-1)+ d[s[e]-'a'][1];
    int t5 = INF;
    if(s[b]==s[e]){
        t5 = get_dp(b+1,e-1);
    }

    dp[b][e] = min(min(min(t1,t2), min(t3,t4)),t5);;
    return dp[b][e];
}

void work(){
    for(int i=0; i<MAXN; i++)for(int j=0; j<MAXN; j++)dp[i][j] = INF;
    int sz = strlen(s);

    int ans = get_dp(0,sz-1);
    cout<<ans<<endl;
}


int main(){
    scanf("%d%d",&N,&M);
    scanf("%s",s);
    int b,c;
    char a;
    getchar();
    for(int i=0; i<N; i++){
        scanf("%c %d %d",&a,&b,&c);
        getchar();
        d[a-'a'][0] = b;
        d[a-'a'][1] = c;
    }
    work();
    
    return 0;
}

