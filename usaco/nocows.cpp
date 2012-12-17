/*
ID: xieke.b1
PROB: nocows
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
ifstream fin("nocows.in");
ofstream fout("nocows.out");

const int INF = 999999999;
const int MAXN = 300;

int N,K;
int dp[MAXN][MAXN];
int MOD = 9901;

int get_ans(int n, int k){
    if(n==1 && k==1)return 1;
    if(n==0 || k==0)return 0;
    if(dp[n][k]!=-1)return dp[n][k];
    
    //if(k<=30){
        //if( n> my_pow(k)-1)return 0;
    //}
    
    /*
    if(n==3 && k==2){
        return 1;
    }*/
    
    int t_n = n-1, t_k = k-1;
    //n--, k--;
    int t_sum = 0;
    //cout<<"ok, n and k are "<<n<<" "<<k<<endl;
    int t1,t2,t_res;
    for(int left = 1; left<t_n; left++){
        int right = t_n-left;
        for(int h_left = 1; h_left<t_k; h_left++){
            if(h_left>left || t_k>right)continue;
            t1 = get_ans(left, h_left);
            t2 = get_ans(right, t_k);
            t_res = t1*t2;
            

            //if(!(left==right && h_left==t_k)){
                //t_sum = t_sum;
            //}else{
                if(t_res!=0){
                t_sum += (t1*t2) ;
                t_sum%=MOD;
                }
            //} 
            /*
            cout<<"i'm seeing ("<<left<<","<<k<<") and ("<<right<<","<<h_left<<") and res is "<<t1*t2<<endl;
            cout<<"one t1 t2 are "<<t1<<" "<<t2<<endl;
            */
                //}
        }
        for(int h_right = 1; h_right<t_k; h_right++){
            if(h_right>right || t_k>left)continue;
            t1 = get_ans(left, t_k);
            t2 = get_ans(right, h_right);
            t_res = t1*t2;
            /*
            cout<<"i'm seeing ("<<left<<","<<k<<") and ("<<right<<","<<h_right<<") and res is "<<t1*t2<<endl;
            cout<<"two t1 t2 are "<<t1<<" "<<t2<<endl;
            */
            if(t_res!=0){
            t_sum += t1*t2;
            t_sum%=MOD;
            }
        }

        t1 = get_ans( left, t_k);
        t2 = get_ans( right, t_k);
        t_res = t1*t2;
        if(t_res!=0){
        t_sum+= t1*t2;
        t_sum%=MOD;
        }
    }
    dp[n][k] = t_sum;
    //cout<<"("<<n<<","<<k<<") = "<<t_sum<<endl;
    //return t_sum;
    return dp[n][k];

}

void work(){
    memset(dp,-1,sizeof(dp));
    fout<<get_ans(N,K)<<endl;

}


int main(){
    fin>>N>>K;;
    work();
    return 0;
}

