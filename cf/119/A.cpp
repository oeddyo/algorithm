#include <iostream>
#include <set>
#include <vector>

using namespace std;

const int MAXN = 5000;
const int INF = 99999999;
int dp[MAXN];
int N;


int main(){
    cin>>N;

    set<int> d;
    for(int i=0; i<3; i++){
        int t;
        cin>>t;
        d.insert(t);
    } 

    for(int i=0; i<MAXN; i++)dp[i] = -INF;
    dp[0] = 0;

    for(int i=0; i<=N; i++){
        if(dp[i]!=-INF){
            vector<int> tmp(d.begin(), d.end());
            for(int j=0; j<tmp.size(); j++){

                for(int j=0; j<tmp.size(); j++){
                    if(i+tmp[j]<=N){
                        dp[i+tmp[j]] = max( dp[i]+1, dp[i+tmp[j]]);
                    }
                }
            }
        }

    }
        cout<<dp[N]<<endl;
    return 0;
}

