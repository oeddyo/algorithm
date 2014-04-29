#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <string.h>
using namespace std;
 
#define DEBUG
#define REP(i,a) for(i=0;i<a;i++)
#define FOR(i,a,b) for(i=a;i<b;i++)
#define VE vector<int>
#define SZ size()
#define PB push_back
int N;

const int MAXN = 10002;
typedef long long ll;
const int MOD = 1000000000+9;
ll dp[MAXN][150];

vector<int> prime;
int p_size = prime.size(); 

bool convert(int A, int B){
    if(A%100 == B/10){
        return true;
    }
    return false;
}

bool convertible[200][200];
void pre(){
    memset(convertible, 0, sizeof(convertible));
    for(int i=0; i<p_size; i++){
        for(int j=0; j<p_size; j++){
            if(convert(prime[i], prime[j])){
                convertible[i][j] = 1;
                //cout<<prime[i]<<"->"<<prime[j]<<endl;
                //cout<<"conv["<<i<<"]["<<j<<"] = "<<1<<endl;
            }
        }
    }
}

void work(){
    memset(dp, 0, sizeof(dp));
    for(int i=100; i<=999; i++){
        bool ok = true;
        for(int j=2; j<i; j++){
            if(i%j==0){
                ok = false;
            }
        }
        if(ok){
            prime.push_back(i);
            dp[0][prime.size()-1] = 1;
            //cout<<"prime.push_back("<<i<<")"<<endl;
        }
    }
    p_size = prime.size();
    pre();

    for(int i=0; i<N; i++){
        for(int j=0; j<p_size; j++){
            if(dp[i][j]>0){
                for(int k=0; k<p_size; k++){
                    if(convertible[j][k]){
                        dp[i+1][k] += dp[i][j];
                        dp[i+1][k] %= MOD;
                        //cout<<"now "<<dp[i+1][k] <<endl;
                    }
                }
            }
        }
    }
    ll ans = 0;
    for(int i=0; i<p_size; i++){
        ans += dp[N-3][i];
        ans %= MOD;
    }
    cout<<ans%MOD<<endl;
}

int main(){
    cin>>N; 
    work();
    return 0;
}

