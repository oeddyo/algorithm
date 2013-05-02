#include <iostream>

using namespace std;

const int MOD = 100000000;

typedef long long int ll;

ll dp[201][100][100];

int n1, n2, k1, k2;

int main(){
    memset(dp,0,sizeof(dp));
    cin>>n1>>n2>>k1>>k2;
    dp[0][1][0] = 1;
    dp[0][0][1] = 1;

    for(int i=1; i<n1+n2; i++){
        for(int k=1; k<=min(k2,i); k++){
            if(k>n2)break;
            dp[i][1][0] += dp[i-1][0][k]; 
        }
        for(int k=2; k<=min(k2,i); k++){
            if(k>n1)break;
            dp[i][k][0] += dp[i-1][k-1][0];
        }
        for(int k=1; k<=min(k1, i); k++){
            if(k>n1)break;
            dp[i][0][1] += dp[i-1][k][0];
        }
        for(int k=2; k<=min(i,k1); k++){
            if(k>n2)break;
            dp[i][0][k] += dp[i-1][0][k-1];
        }
    }

    int ans = 0;
    for(int k=1; k<=min(k1, n1); k++){
        ans += dp[n1+n2-1][k][0];
        cout<<"dp["<<n1+n2-1<<"]["<<k<<"][0] = "<<dp[n1+n2-1][k][0]<<endl;
    }
    for(int k=1; k<=min(k2, n2); k++){
        ans += dp[n1+n2-1][0][k];
        cout<<"dp["<<n1+n2-1<<"]["<<0<<"]["<<k<<"] = "<<dp[n1+n2-1][0][k]<<endl;
    }

    cout<<ans<<endl;

    return 0;
}

