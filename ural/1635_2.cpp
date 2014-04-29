#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>
#include <string.h>
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

string S;
const int INF =65000;
const int MAXN = 4001;
int dp[MAXN], sz;
bool is_p[MAXN][MAXN];
vector<string> ans_s;

int path[MAXN];

void work(){
    memset(path, -1, sizeof(path));
    for(int i=0; i<MAXN; i++)dp[i] = INF;
    dp[0] = 1;
    path[0] = -1;
    for(int i=1; i<sz; i++){
        for(int j=0; j<=i; j++){
            if(is_p[j][i]){
                if(j==0){
                    dp[i] = 1;
                    path[i] = 0;
                    continue;
                }
                if(dp[j-1] + 1 < dp[i]){
                    dp[i] = min(dp[j-1] + 1, dp[i]);
                    path[i+1] = j;
                }
            }
        }
    }
    cout<<dp[sz-1]<<endl;
    int cur = sz;
    vector<int> tmp;
    while(1){
        if(cur<0){
            tmp.push_back(0);
            break;
        }
        tmp.push_back(cur);
        cur = path[cur];
        //cur -= 1;
    }
    tmp = vector<int> (tmp.rbegin(), tmp.rend());

    for(int i=0; i<tmp.size()-1; i++){
        //cout<<"ok-> "<<tmp[i]<<" "<<tmp[i+1]<<endl;
        for(int k=tmp[i]; k<tmp[i+1]; k++){
            cout<<S[k];
        }
        cout<<" ";
    }
    cout<<endl;
    /*j
    for(int i=tmp.size()-1; i<sz; i++){
        cout<<S[i];
    }cout<<endl;

*/
}

void _do(int front, int rear, int sz){
    while(front>=0 && rear<sz && S[front]==S[rear]){
        is_p[front][rear] = true;
        front--, rear++;
    }
}
void pre(){
    sz = S.size();
    for(int i=0; i<sz; i++){
        int front = i; 
        int rear = i;
        _do(front, rear, sz);
        if(front-1>=0)
            _do(front-1, rear, sz);
    }
}

int main(){
    cin>>S;
    pre();
    work();
    return 0;
}

