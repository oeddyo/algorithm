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

int dp[11][100];

int main(){
    memset(dp,0,sizeof(dp));
 
    dp[0][0] = 1;

    for(int i=1; i<=9; i++){
        for(int j=0; j<=81; j++){
            for(int k=0; k<=9; k++){
                if(j-k>=0 && j-k<=81 ){
                    dp[i][j] += dp[i-1][j-k];

                }
            }
        }
    }
    
    int S;
    int cnts[100];
    cin>>S;
    for(int i=0; i<=81; i++){
        int t_sum = 0;
        for(int j=0; j<=9; j++){
            t_sum+=dp[j][i];
        }
        cnts[i] = t_sum;
        cout<<t_sum<<",";
    }
    cout<<endl;
    cout<<cnts[S]<<endl;
    return 0;
}

