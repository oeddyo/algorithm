#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

ifstream fin("input.txt");


const int MAXN = 5000;
int data[MAXN];
int dp[MAXN];

int cnt = 0;
int ans = 0;
void get_dp(int end){
    memset(dp,0,sizeof(dp));
    dp[0] = 1;
    for(int i=0; i<end; i++){
        for(int j=MAXN-1; j>=0; j--){
            if(j-data[i]>=0 && dp[j-data[i]]>0){
                dp[j] += dp[j-data[i]];
            }
        }
    }
    //cout<<"end is "<<end;
    for(int i=0; i<10; i++){
        //cout<<"dp["<<i<<"] = "<<dp[i]<<endl;
    }
    if(dp[data[end]]){
        cout<<"ok "<<data[end]<<" num = "<<dp[data[end]]<<endl;
        ans+=dp[data[end]];
    }

}

void work(){
    for(int i=1; i<cnt; i++){
        get_dp(i);  
    }
    cout<<ans<<endl;
}



int main(){
    cnt = 0;
    int t;
    while(fin>>t){
        data[cnt++] = t;
    }
    cout<<"cnt is "<<cnt<<endl;
    work();


    return 0;
}

