#include <iostream>
#include <string>
#include <cstring>

using namespace std;

string S;

bool dp[1<<26];
int cnt[26];
const int INF = 99999999;

int get_ans(int state){
    if(dp[state]!=INF){
        return dp[state];
    }
    int num = __builtin_popcount(state);
    if(num== 0 || num == 1){
        return 1;
    }
    int ok = 0;
    for(int i=0; i<26; i++){
        if( ((state>>i)&1)==1 ){
            int ns = (~(1<<i))&state;
            int ans = get_ans(ns);
            if(ans==0){
                ok = 1;
            }
        }
    }
    dp[state] = ok;
    return ok;
}


void work(){
    memset(cnt,0,sizeof(cnt));
    for(int i=0; i<S.size(); i++){
        cnt[ S[i]-'a' ] += 1;
    }
    int start = 0;
    for(int i=0; i<26; i++){
        if(cnt[i]%2==1){
            start |= (1<<i);
        }
    }
    for(int i=0; i<(1<<26); i++){
        dp[i] = INF;
    }
    int ans = get_ans(start);
    if(ans==1){
        cout<<"First"<<endl;
    }
    else{
        cout<<"Second"<<endl;
    }


}



int main(){
    cin>>S;
    work();

    return 0;
}

