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
 
const int MAXN = 250;
const int MAXM = 60001;
int squres[MAXN], N;
bool dp[MAXN][MAXM];

int main(){
    cin>>N;
    dp[0][0] = 1;
    int ptr = 0;
    for(int i=1; i*i<MAXM; i++){
        squres[ptr++] = i*i;
    }

    bool ok = false;
    for(int i=0; i+1<MAXN; i++){
        for(int j=0; j<=N; j++){
            if(dp[i][j]){
                for(int k=0; k<ptr; k++){
                    if(j+squres[k] < MAXM){
                        dp[i+1][j+squres[k]] = 1;
                        if(dp[i+1][N])
                            ok = true;
                    }else{
                        break;
                    }
                }
            }
        }
        if(ok==true)break;
    }
    for(int i=1; i<MAXN; i++){
        if(dp[i][N]){
            cout<<i<<endl;
            break;
        }
    }


   return 0;
}

