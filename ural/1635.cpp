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

string S;
const int INF =65000;
const int MAXN = 4001;
unsigned short dp[MAXN][MAXN];
bool is_p[MAXN][MAXN];
vector<string> ans_s;

int get_ans(int left, int right){
    if(left>right){
        return 0;
    }
    if(dp[left][right]!=INF){
        return dp[left][right];
    }
    if(is_p[left][right]){
        dp[left][right ] = 1;
        return 1;
    }

    if(left==right){
        dp[left][right] = 1;
        return 1;
    }
    int tmp = INF;
    if(left+1 == right){
        if(S[left]==S[right]){
            tmp = 1;
        }else{
            tmp = 2;
        }
    }

    if(S[left]==S[right] && left+1<right){
        if(is_p[left][right]){
            int c = get_ans(left+1, right-1);
            if(c == 1){
                tmp = 1;
            }else{
                tmp = c + 2;
            }
        }
    }
    for(int i=left; i<right; i++){
        if(is_p[left][i] || is_p[i+1][right])
            tmp = min(tmp, get_ans(left, i)+get_ans(i+1, right) );
    }
    dp[left][right] = tmp;
    return tmp;
}

string print(int left, int right){
    string t = "";
    if(dp[left][right]==1){
        for(int i=left; i<=right; i++){
            t += S[i];
        }
        ans_s.push_back(t);
        return t;
    }
    int pos = -1;
    for(int i=left; i<right; i++){
        if((is_p[left][i] || is_p[i+1][right] )&& get_ans(left, i) + get_ans(i+1, right) == dp[left][right]){
            pos = i;
        }
    }
    if(pos == -1){
            t = S[left];
            t += print(left+1, right-1);
            t += S[right];
    }else{
        t += print(left, pos);
        t += print(pos+1, right);
    }
    return t;
}


void work(){
    for(int i=0; i<MAXN; i++)for(int j=0; j<MAXN; j++){
        dp[i][j] = INF;
    }
    int ans = get_ans(0, S.size()-1);
    cout<<ans<<endl;
    print(0, S.size() - 1);
    for(int i=0; i<ans_s.size(); i++){
        cout<<ans_s[i]<<" ";
    }cout<<endl;
}

void _do(int front, int rear, int sz){
    while(front>=0 && rear<sz && S[front]==S[rear]){
        is_p[front][rear] = true;
        front--, rear++;
    }

}


void pre(){
    int sz = S.size();
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

