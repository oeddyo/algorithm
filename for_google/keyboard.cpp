#include <iostream>
#define MAXN 10000
using namespace std;


int dp[MAXN],M;


int get_max(int k){
        if(k<=0){
                return 0;
        }
if(dp[k]!=-1)return dp[k];


dp[k] = max(get_max(k-1)+1, get_max(k-3)*2);
return dp[k];

}





void work(){
        memset(dp,-1,sizeof(dp));
        cout<<get_max(M)<<endl;;
}



int main(){
        cin>>M;
        work();
return 0;
}
