#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>
#include <stack>
#include <map>
#include <set>
using namespace std;

#define DEBUG
#define REP(i,a) for(i=0;i<a;i++)
#define FOR(i,a,b) for(i=a;i<b;i++)
#define VE vector<int>
#define SZ size()
#define PB push_back

const int MAXN = 21;
const int INF = 99999999;
int N;
int data[MAXN];
int dp[1<<MAXN];

int get_ans(int state){
    if(state==0){
        return 0;
    }
    if(dp[state]!=-1)return dp[state];
 

    int damage= 0;
    for(int i=0; i<N; i++){
        if(((state>>i)&1)==1){
            damage += data[i];
        }
    }

    int cur = INF;
    for(int i=0; i<N; i++){
        int f = (i-1+N)%N;
        int m = i;
        int n = (i+1)%N;
        int td = damage;

        if( ( (state>>f)&1 ) + ((state>>m)&1) + ((state>>n)&1) == 0){
            continue;
        }
        int ns = state;;
        if(((state>>f)&1)==1){
            ns = (1<<f)^ns;
            td -= data[f];
        }
        if(((state>>m)&1)==1){
            ns = (1<<m)^ns;
            td -= data[m];
        }
        if(((state>>n)&1) == 1){
            ns = (1<<n)^ns;
            td -= data[n];
        }

        int next = get_ans(ns);
        cur = min(cur, next + td);
    }
    
    dp[state] = cur;
    return cur;

}

void work(){
    for(int i=0; i<(1<<MAXN); i++){
        dp[i] = -1;
    }

    int ans = get_ans((1<<N)-1);

    cout<<ans<<endl;
}

int main(){
    cin>>N;
    for(int i=0; i<N;i++)cin>>data[i];


    work();
    return 0;
}

