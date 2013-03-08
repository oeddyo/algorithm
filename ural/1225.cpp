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


const int MAXN = 60;

long long int dp[MAXN][3];
int N;


void work(){
    memset(dp,0,sizeof(dp));
    // 0 - red, 1 - blue, 2 - white
    dp[0][0] = 1;
    dp[0][1] = 0;
    dp[0][2] = 1;

    for(int i=1; i<N; i++){
        for(int color = 0; color < 3; color++){
            for(int pre_c = 0; pre_c<3; pre_c++){
                if(color==pre_c)continue;
                if(color==1){
                    if(pre_c==0){
                        dp[i+1][2] += dp[i-1][pre_c];
                    }else if(pre_c==2){
                        dp[i+1][0] += dp[i-1][pre_c];
                    }
                }else{
                    dp[i][color] += dp[i-1][pre_c];
                }
            }
        }
    }
    long long int ans = 0;
    for(int i=0; i<3; i++){
        ans+=dp[N-1][i];
    }
    cout<<ans<<endl;
}


int main(){
    cin>>N;
    work();

    return 0;
}

