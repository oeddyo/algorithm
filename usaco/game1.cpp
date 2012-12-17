/*
ID: xieke.b1
PROB: game1
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <string.h>
#include <cmath>

using namespace std;

ifstream fin("game1.in");
ofstream fout("game1.out");

typedef pair<int, int> pii;
const int MAXN = 251;
const int INF = 999999999;
int N;
int data[MAXN];

int dp[MAXN][MAXN][2];

int sum[MAXN][MAXN];
void get_sum(){
    for(int i=0; i<N; i++){
        for(int j=i; j<N;j++){
            int t = 0;
            for(int k=i; k<=j; k++){
                t+=data[k];
            }
            sum[i][j] = t;
        }
    }
}


int dfs(int left, int right, int k){
    if(dp[left][right][k]!=-1)return dp[left][right][k];
    if(left==right)return data[right];

    if(k==0){
        int c1 = data[left]+sum[left+1][right] - dfs(left+1, right, 1);
        int c2 = data[right]+sum[left][right-1] - dfs(left, right-1, 1);
        dp[left][right][k] = max(c1,c2);
    }else{
        int c1 = data[left]+sum[left+1][right] - dfs(left+1, right, 0);
        int c2 = data[right]+sum[left][right-1] - dfs(left, right-1, 1);
        dp[left][right][k] = max(c1,c2);
    }
    return dp[left][right][k];
}

void work(){
    get_sum();
    memset(dp,-1,sizeof(dp));
    int t = dfs(0,N-1,0);
    fout<<t<<" "<<sum[0][N-1]-t<<endl;

}


int main(){
    fin>>N;
    for(int i=0; i<N; i++){
        fin>>data[i];
    }
    work();
    return 0;
}

