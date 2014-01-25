#include <iostream>
#include <vector>
#include <map>

using namespace std;

const int MAXN = 1000;
int N, cnt;
//int dp[MAXN][2];
int dp[MAXN];
string str;
string boss;
map<string, int> mp;
vector<int> G[MAXN];
vector<int> G2[MAXN];

bool is_unique = true;

int dp2[MAXN][2];


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

int get_ans(int v, int pre){
    //cout<<"at "<<v<<" pre = "<<pre<<endl;
    if(dp[v]!=-1){
        return dp[v];
    }

    int sz = G[v].size();
    int next_cnt = 0;
    for(int i=0; i<sz; i++){
        if(G[v][i]!=pre){
            next_cnt++;
        }
    }
    if(next_cnt==0){
        dp[v] = 1;
        //cout<<"ok return dp["<<v<<"] = 0"<<endl;
        dp2[v][0] = dp2[v][1] = 1;
        return 1;
    }
    
    //not take v
    int cur1 = 0;
    for(int i=0; i<sz; i++){
        if(G[v][i]==pre)continue;
        int tmp = get_ans(G[v][i], v);
        cur1 += tmp;
    }

    //take v
    int cur2 = 1;
    for(int i=0; i<sz; i++){
        int child = G[v][i];
        if(child==pre)continue;
        int t_sz = G[child].size();
        for(int j=0; j<t_sz; j++){
            if(G[child][j]==v)continue;
            //cout<<"at "<<v<<" "<<pre<<" "<<"take. next would be "<<G[child][j]<<" "<<child<<endl;
            cur2 += get_ans(G[child][j], child);
        }
    }
   
    dp2[v][0] = cur1;
    dp2[v][1] = cur2;

    dp[v] = max(cur1, cur2);
    return dp[v];
}

void check(int v){
    if(dp2[v][0]>dp2[v][1]){
        int sz = G2[v].size();
        for(int i=0; i<sz; i++){
            int nt = G2[v][i];
            if(dp2[nt][0]==dp2[nt][1]){
                is_unique = false;
                return ;
            }
        }
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
            dp[i] = -1;
            dp2[i][0] = dp2[i][1] = -1;
        }
        for(int i=0; i<N-1; i++){
            cin>>str;
            int a, b;
            a = get_number(str);
            cin>>str;
            b = get_number(str);
            G[a].push_back(b);
            G[b].push_back(a);
            G2[b].push_back(a);
        }

        int b = mp[boss];
        int ans = get_ans(b, -1);
        //cout<<"ok "<<dp2[0][0]<<" "<<dp2[0][1]<<endl;
            for(int i=0; i<N-1; i++){
                is_unique = true;
                check(i);
                if(is_unique==false)break;
            }
        //cout<<max(dp2[0][0], dp2[0][1])<<" ";
        cout<<ans<<" ";
        if(!is_unique || dp2[b][0]==dp2[b][1]){
            cout<<"No"<<endl;
        }else{
            cout<<"Yes"<<endl;
        }

    }

    return 0;
}

