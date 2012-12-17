/*
ID: xieke.b1
PROB: buylow
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <vector>
#include <string.h>

using namespace std;
ifstream fin("buylow.in");
ofstream fout("buylow.out");

const int INF = 999999999;
int N;
const int MAXN = 5001;
int dp[MAXN], diff_count[MAXN], data[MAXN];

void work(){
    for(int i=0; i<N; i++){diff_count[i] = 1;dp[i] = 1;}

    for(int i=0; i<N; i++){
        int t_max = -INF;
        for(int j=0; j<i; j++){
            if(data[i]<data[j]){
                t_max = max(t_max,dp[j]+1);
            }
        }
        if(t_max>dp[i]){
            for(int j=0; j<i; j++){
                if(dp[j]+1==t_max){

                }
            }
        }

        for(int j=0; j<i; j++){
            if(data[i]<data[j]){
                dp[i] = max(dp[j]+1,dp[i]);
            }
        }
        if(dp[i]>running_max){
            running_max = dp[i];
        }
    }
    
    for(int i=0; i<N; i++){
        cout<<dp[i]<<" ";
    }cout<<endl;
     
    for(int i=0; i<N; i++){
        if(dp[i]==running_max){
            vector<int> empty_v;
            get_pre(i, empty_v);
        }
    }

    fout<<running_max<<" "<<my_s.size()<<endl;
}


int main(){
    fin>>N;
    for(int i=0; i<N; i++)fin>>data[i];
    work();
    return 0;
}

