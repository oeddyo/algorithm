#include <iostream>
#include <vector>
#include <map>

using namespace std;

const int MAXN = 1000;
int N, cnt;
int dp[MAXN][2];
string str;
string boss;
map<string, int> mp;
vector<int> G[MAXN];

bool is_unique = true;



int get_number(string &str){
    int res;
    if(mp.find(str)!=mp.end()){
        res = mp[str];
    }else{
        res = cnt;
        mp[str] = cnt++;
    }
    return res;
}


void check(int v){
    if(dp[v][0]>dp[v][1]){
        int sz = G[v].size();
        for(int i=0; i<sz; i++){
            int nt = G[v][i];
            if(dp[nt][0]==dp[nt][1]){
                is_unique = false;
                return ;
            }
        }
    }

}

void get_ans(int u, int pre){
    dp[u][1] = 1;
    dp[u][0] = 0;
    for(int i=0; i<G[u].size(); i++){
        int v = G[u][i];
        if(v==pre)continue;
        get_ans(v, u);
        dp[u][1] += dp[v][0];
        dp[u][0] += max(dp[v][0], dp[v][1]);
    }

}


int main(){
    while(1){
        cin>>N;
        if(N==0)break;
        cin>>boss;
        is_unique = true;
        cnt = 0;
        for(int i=0; i<MAXN; i++)G[i].clear();
        mp = map<string, int>();
        for(int i=0; i<MAXN; i++){
            dp[i][0] = dp[i][1] = -1;
        }

        for(int i=0; i<N-1; i++){
            cin>>str;
            int a, b;
            a = get_number(str);
            cin>>str;
            b = get_number(str);
            G[a].push_back(b);
            G[b].push_back(a);
            //G2[b].push_back(a);
        }

        int b = mp[boss];
        get_ans(b, -1);
        for(int i=0; i<N-1; i++){
            is_unique = true;
            check(i);
            if(is_unique==false)break;
        }
        //cout<<max(dp2[0][0], dp2[0][1])<<" ";
        int ans = max(dp[b][0], dp[b][1]);
        cout<<ans<<" ";
        if(!is_unique || dp[b][0]==dp[b][1]){
            cout<<"No"<<endl;
        }else{
            cout<<"Yes"<<endl;
        }

    }

    return 0;
}

