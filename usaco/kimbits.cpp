/*
ID: xieke.b1
PROB: kimbits
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

ifstream fin("kimbits.in");
ofstream fout("kimbits.out");

typedef pair<int, int> pii;
const int MAXN = 50;
const int INF = 2100000000;
long long int N,L,I;


void print(int number, int cur){
    if(cur==0){
        return ;
    }
    print(number>>1, cur-1);
    cout<<(number&1);
}

int dp[MAXN][MAXN];
long long int get_C(int n, int k){
    if(k==0)return 1;
    if(n==0)return 0;
    if(dp[n][k]!=-1)return dp[n][k];
    dp[n][k] = get_C(n-1,k-1)+get_C(n-1,k);
    return dp[n][k];
}

void work(){
    memset(dp,-1,sizeof(dp));
    string ans = ""; 
    I-=1;
    for(int i=N; i>=1; i--){
        // try set i_th position as 1
        long long int left = 0;
        for(int j=0; j<=L; j++){
            cout<<"getting C("<<i-1<<","<<j<<");"<<endl;
            left += get_C(i-1, j);
        }
        cout<<"left is "<<left<<endl;
        if(I==0 ){
            ans+='0';
        }else if( I < left ){
            //should set to zero
            ans+='0';
        }else{
            ans+='1';
            L--;
            I-=left;
        }
    }
    fout<<ans<<endl;
}

int main(){
    fin>>N>>L>>I;
    for(int i=0; i<(1<<N); i++){
        if(__builtin_popcount(i)<=L){
            print(i,N);
            cout<<endl;
        }
    }


    work();

    return 0;
}

