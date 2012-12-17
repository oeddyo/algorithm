#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
using namespace std;
const int MAXN = 5001;
long long  dp[MAXN];
string S;

void work(){
    memset(dp,0,sizeof(dp));
    int sz = S.size();
    
    dp[0] = 1;
    if(sz==1){
        cout<<1<<endl;
        return ;
    }
    if((S[0]-'0')*10+S[1]-'0' <=26 && S[1]!='0'){
        dp[1] = 2;
    }else{
        dp[1] = 1;
    }

    
    for(int i=2; i<sz; i++){
        if((S[i-1]-'0')*10+S[i]-'0' <=26 && S[i-1]!='0'){
                dp[i]+=dp[i-2];
        }
        if(S[i]!='0')
            dp[i]+=dp[i-1];
    }
    cout<<dp[sz-1]<<endl;

}


int main(){
    while(1){
        cin>>S;
        if(S=="0"){
            break;
        }
        work();
    }

    return 0;
}

