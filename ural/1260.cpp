#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAXN = 100;
int N;
long long int dp[MAXN][MAXN][1<<5];
void work(){
    memset(dp,0,sizeof(dp));
    dp[0][0][1<<2] = 1;

    for(int i=1; i<N; i++){
        for(int j=0; j<N; j++){
            for(int k=j-2; k<=j+2; k++){
                if(k>N ||k==j|| k<0)continue;
                for(int s=0; s<(1<<5); s++){
                    if( ((s>>(j+2-k))&1)==1 )continue;
                    if( dp[i-1][j][s] == 0)continue;
                    
                     
                    int ns = s| (1<<(j+2-k));
                    if(k>j){
                        ns = ns<<(k-j);
                    }else if(k<j){
                        ns = ns>>(j-k);
                    }
                    ns&=31;
                    dp[i][k][ns] += dp[i-1][j][s];
                    //cout<<"now adding "<<j<<" to "<<k<<endl;
                }
            }
        }
    }
    long long int ans = 0;
    for(int i=0; i<N; i++){
        for(int s=0; s<(1<<5); s++){
            ans+=dp[N-1][i][s];
            if(dp[N-1][i][s]!=0)
                cout<<i<<" "<<s<<" "<<dp[N-1][i][s]<<endl;
        }
    }
    
    cout<<ans<<endl;

}

int main(){

    cin>>N;
    work();

    return 0;
}

