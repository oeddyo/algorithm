#include <iostream>
#include <string.h>
using namespace std;

int C,G;
int L[21], W[21], right_side;

const int MMAX = 8000;
int dp[21][MMAX];
int magic = 4000;
void work(){
    memset(dp,0,sizeof(dp));
    dp[0][magic] = 1;
        
    
    for(int j=1; j<=G; j++){
        for(int i=-magic; i<magic; i++){
            for(int k=1; k<=C; k++){
                int t = W[j]*L[k];
                int now = i+magic;
                int pre = i-t+magic;
                dp[j][now] += dp[j-1][pre];
            }
        }
    }
    cout<<dp[G][magic]<<endl;
}

int main(){

    cin>>C>>G;
    for(int i=1; i<=C; i++){
        cin>>L[i];
    }
    for(int i=1; i<=G; i++){
        cin>>W[i];
    }
    work();

    return 0;
}

