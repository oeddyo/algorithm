#include <iostream>
#include <cstring>

#include <vector>

using namespace std;


string S;
string forb[14];

const int INF = 99999999;
const int MAXN = 100005;
int N, dp[MAXN][2];

bool is_in(int a, int b, string &myS){
    for(int i=0; i<N; i++){
        if((forb[i][0]==myS[a] && forb[i][1]==myS[b])||(forb[i][0]==myS[b] && forb[i][1]==myS[a])){
            return true;
        }
    }
    return false;
}

typedef pair<int, int> pii;
void work(){
    S+="#"; 
    int n_char = S.length();
    vector< pii > V;
    int pre = 0, ans = 0;
    for(int i=1; i<n_char; i++){
        if(S[i]==S[pre]){
            continue;
        }else{
            int a = pre;
            int b = i-1;
            V.push_back( pii(a,b));
            pre = i;
        }
    }
    for(int i=0; i<MAXN; i++){
        dp[i][0] = dp[i][1] = INF;
    }


    dp[0][0] = V[0].second-V[0].first+1;
    dp[0][1] = 0;
    
    int sz = V.size();
    cout<<"sz = "<<sz<<endl;
    for(int i=0; i<sz; i++){
        cout<<V[i].first<<" "<<V[i].second<<endl;
    }
    for(int i=1; i<sz; i++){
        int l_a = V[i].second-V[i].first+1;
        if(is_in( V[i-1].first, V[i].first, S)){
            dp[i][1] = min(dp[i-1][0], dp[i][1]);
            dp[i][0] = min(dp[i-1][0],dp[i-1][1])+l_a;
        }else{
            dp[i][1] = min(min(dp[i-1][0], dp[i-1][1]), dp[i][1]);
            dp[i][0] = min(dp[i-1][0],dp[i-1][1])+l_a;
        }
        cout<<"dp["<<i<<"][0] = "<<dp[i][0]<<" dp["<<i<<"][1] = "<<dp[i][1]<<endl;
    }

    ans = min(dp[sz-1][0], dp[sz-1][1]);
    cout<<ans<<endl;
}


int main(){
   
    cin>>S;
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>forb[i];
    }
    work();

    return 0;
}

