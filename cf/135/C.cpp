#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

const int MAXN = 500001;
const int INF = 999999999;
int N,K;
string S;
int dp[MAXN][26];
int rec[MAXN][26];
void work(){
    for(int i=0; i<MAXN; i++){
        for(int j=0; j<K; j++){
            dp[i][j]= INF;
        }
    }
    
    for(int i=0; i<K; i++){
        if(i==S[0]-'A'){
            dp[0][i] = 0;
        }else{
            dp[0][i] = 1;
        }
        rec[0][i] = i;
    }

    for(int i=1; i<N; i++){
        for(int j=0; j<K; j++){
            for(int k=0; k<K; k++){
                if(j==k){
                    continue;
                }else{
                    if(j==(S[i]-'A') ){
                        if(dp[i][j] > dp[i-1][k]){
                            dp[i][j] = dp[i-1][k];
                            rec[i][j] = k;
                        }
                        //dp[i][j] = min(dp[i][j], dp[i-1][k]);
                    }else{
                        if(dp[i][j] > dp[i-1][k]+1){
                            dp[i][j] = dp[i-1][k]+1;
                            rec[i][j] = k;
                        }
                        //dp[i][j] = min(dp[i][j], dp[i-1][k]+1);
                    }
                }
            }
        }
    }

    int ans = INF;
    int cur = -1;
    for(int i=0; i<K; i++){
        if(dp[N-1][i]<ans){
            ans = dp[N-1][i];
            cur = i;
        }
    }
    cout<<ans<<endl;
    string ans_str = "";
    int pos = N-1;
    while(1){
        ans_str += (char)('A'+cur);
        cur = rec[pos][cur];
        pos-=1;
        if(pos==-1)break;
    }
    reverse(ans_str.begin(), ans_str.end());
    cout<<ans_str<<endl;
}

int main(){
    cin>>N>>K;
    cin>>S;
    work();
     
    return 0;
}



