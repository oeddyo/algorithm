#include <iostream>

using namespace std;

const int MOD = 100000000;

typedef long long int ll;

ll dp[201][100][2];

int n1, n2, k1, k2;

int main(){
    memset(dp,0,sizeof(dp));
    cin>>n1>>n2>>k1>>k2;
    dp[1][0][0] = 1;
    dp[0][1][1] = 1;
    

    for(int i=1; i<n1+n2; i++){


    }




    return 0;
}

