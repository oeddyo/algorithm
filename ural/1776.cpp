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

const int MAXN = 500;
long double dp[MAXN][MAXN];
const double INF = 999999999.9;
const double mark = -INF;
int N;

long double get_dp(int left, int right){
    if(left>right)return 0.0;
    if(left==right)return 10.0;
    if(dp[left][right]!=mark){
        return dp[left][right];
    }
    long double ans_tmp = 10.0;
    long double tmp = 0;
    for(int i=left; i<=right; i++){
        long double tmp1 = get_dp(left,i-1);
        long double tmp2 = get_dp(i+1,right);
        tmp += max(tmp1,tmp2);
    }
    ans_tmp += tmp/(1.0*(right-left+1));
    //dp[left][right] = ans_tmp + tmp/(1.0*(right-left+1));
    dp[left][right] = ans_tmp;
    cout<<"with "<<left<<" "<<right<<" ans is "<<ans_tmp<<endl;
    return ans_tmp;
}


void work(){
    for(int i=0; i<MAXN; i++)for(int j=0; j<MAXN; j++){
        dp[i][j] = mark;
    }


    long double ans = get_dp(1, N-2);
    cout<<setprecision(15)<<ans<<endl;



}


int main(){
    cin>>N;
    work();

    return 0;
}

