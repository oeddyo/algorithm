/*
ID: xieke.b1
PROG: subset
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <stack>
#include <map>

using namespace std;

ofstream fout("subset.out");
ifstream fin ("subset.in");
const int INF = 999999999;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define all(c) (c).begin(), (c).end()
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++) 

int N;
const int MAXN = 100;
long long int dp[MAXN][1000];


void work(){
    int v = (1+N)*N/2;
    if(v%2==1){
        fout<<0<<endl;
        return ;
    }
    dp[0][0] = 1;
    
    for(int i=1; i<=N; i++){
        for(int j=0; j<=v; j++){
            dp[i][j]+=dp[i-1][j];
            if(j-i>=0)
                dp[i][j]+=dp[i-1][j-i];
        }
    }
/*

    for(int i=0; i<N; i++){
        for(int j=v; j>=0; j--){
            if(dp[i][j]){
                //don't pick i
                dp[i+1][j] += dp[i][j];
                //pick i
                int add = i+1;
                if(j+add<=v)
                    dp[i][j+add] += dp[i][j];
            }
        }
    }
  */
    cout<<"v is "<<v<<endl;
    cout<<N<<" "<<v/2<<endl;
    cout<<dp[N][v/2]<<endl;
    fout<<dp[N][v/2]/2<<endl;
    
    for(int i=0; i<=N; i++){
        for(int j=0; j<=(1+N)*N/2; j++){
            if(dp[i][j]){
                cout<<"dp["<<i<<"]["<<j<<"] = "<<dp[i][j]<<endl;
            }
        }
    }
}

int main(){
    fin>>N;
    work();
    return 0;
}

