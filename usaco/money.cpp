/*
ID: xieke.b1
PROB: money
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <stack>
#include <vector>
#include <string.h>

using namespace std;
ifstream fin("money.in");
ofstream fout("money.out");

const int INF = 999999999;

const int MAXN = 26;
const int MAXM = 10001;
int data[MAXN], N,V;
long long dp[MAXN][MAXM];

void work(){
    dp[0][0] = 1;

    for(int i=0; i<V; i++){
        for(int j=0; j<MAXM; j++){
            if(dp[i][j]){
                int w = data[i];
                if(w+j<MAXM){
                    dp[i][w+j] += dp[i][j];
                }
                dp[i+1][j] = dp[i][j];
            }
        }
    }
    fout<<dp[V-1][N]<<endl;
}


int main(){
    fin>>V>>N;
    for(int i=0; i<V; i++)fin>>data[i];
    
    work();
    
    return 0;
}

