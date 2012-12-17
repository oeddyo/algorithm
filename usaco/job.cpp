/*
ID: xieke.b1
PROB: job
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <vector>
#include <string.h>

using namespace std;
ifstream fin("job.in");
ofstream fout("job.out");

const int INF = 999999999;
const int MAXN = 10000;
int N, M1, M2;
int A[MAXN], B[MAXN];

int cost[MAXN][2], delay[MAXN][2];
int t[MAXN][2];
void work(){
    int len[2] = {M1, M2}; 
    for(int k=0; k<2; k++){
        memset(delay,0,sizeof(delay));
        for(int i=0; i<N; i++){
            int t_min = INF;
            int t_idx = -1;
            for(int j=0; j<len[k]; j++){
                if(t_min > delay[j][k] + t[j][k]){
                    t_min = delay[j][k]+t[j][k];
                    t_idx = j;
                }
            }
            cost[i][k] = t_min;
            delay[t_idx][k] += t[t_idx][k];
        }
    }
    int ans1 = -INF;
    int ans2 = -INF;
    for(int i=0; i<N; i++){
        ans1 = max(cost[i][0],ans1);
    }
    
    for(int i=0; i<N; i++){
        cout<<i<<" "<<cost[i][0]<<" "<<cost[N-i-1][1]<<endl;
        ans2 = max(ans2, cost[i][0]+cost[N-i-1][1]);
    }
    fout<<ans1<<" "<<ans2<<endl;
}

int main(){
    fin>>N>>M1>>M2;
    for(int i=0; i<M1; i++){
        fin>>t[i][0];
    }
    for(int i=0; i<M2; i++)fin>>t[i][1];
    work();
    return 0;
}

