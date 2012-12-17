/*
ID: xieke.b1
PROB: stamps
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

ifstream fin("stamps.in");
ofstream fout("stamps.out");

typedef pair<int, int> pii;
const int MAXN = 51;
const int MAXK = 201;
const int MAXV = 10001;
const int INF = 2100000000;
int N,K;
int stamps[MAXN];
int max_value;
int min_value;

bool could[MAXV];

int dp[MAXV*MAXK];



void work(){
    sort(stamps, stamps+N);
    max_value = stamps[N-1];
    min_value = stamps[0];
    int limit = stamps[N-1]*K;
    for(int i=0; i<limit; i++)dp[i]=INF;

    dp[0] = 0;

    for(int s=0; s<=limit; s++){
        if(dp[s]!=INF){
            for(int i=0; i<N; i++){
                int t = s+stamps[i];
                if(t<=limit){
                    dp[t] = min(dp[t], dp[s]+1);
                }
            }
        }
    }
    int ans = 0;
    for(int i=0; i<=limit; i++){
        if(dp[i]>K||dp[i]==INF){
            break;
        }
        ans = i;
    }
    fout<<ans<<endl;
}

int main(){
    fin>>K>>N;
    for(int i=0; i<N; i++){
        fin>>stamps[i];
        could[stamps[i]] = true;
    }
    work();

    return 0;
}

