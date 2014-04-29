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
 
const int MAXM = 90000, INF=100000000;
int squres[MAXM], N;
int dp[MAXM];

int main(){
    cin>>N;
    for(int i=0; i<MAXM; i++)dp[i] = INF;
    
    dp[0] = 0;
    for(int i=0; i*i<=N; i++){
        for(int j=i*i; j<=N; j++){
            dp[j] = min(dp[j], dp[j-i*i]+1);
        }
    }
    cout<<dp[N]<<endl;

   return 0;
}

