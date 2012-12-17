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
const int MAXN = 5005;
int dp[MAXN], data[MAXN];
//int cnt[MAXN];
string cnt[MAXN];
set< vector<int> > my_s;


struct bigNum{
    string num;
};

void add(string a, string b, string &result){
    int sz_a = a.size();
    int sz_b = b.size();
    if(sz_a>sz_b){
        for(int i=sz_b; i<sz_a; i++){
            b+='0';
        }
    }else if(sz_b>sz_a){
        for(int i=sz_a; i<sz_b; i++){
            a+='0';
        }
    }
    string res;
    int m=0;
    for(int i=0; i<max(sz_a, sz_b); i++){
        int na = a[i]-'0';
        int nb = b[i]-'0';
        res+= (na+nb+m)%10 + '0';
        m = (na+nb+m)/10;
        /*
        if(na+nb+m>=10){
            res+= (na+nb+m)%10 + '0';
            m = (na+nb+m)/10;
        }else if(na+nb+m<10){
            res+=(na+nb+m)+'0';
            m = 0;
        }*/
    }
    if(m>0){
        res+=(m%10)+'0';
    }
    result = res;
}


void work(){
    data[0] = INF;
    //memset(cnt,0,sizeof(cnt));
    for(int i=0; i<MAXN; i++){
        cnt[i] = "0";
    }

    cnt[0] = "1";
    N++;
    int running_max = -1;
    for(int i=1; i<=N; i++){
        for(int j=i-1; j>=0 && data[j]!=data[i]; j--){
            if(data[i]<data[j]){
                //dp[i] = max(dp[i],dp[j]+1);
                if(dp[j]+1>dp[i]){
                    cnt[i] = cnt[j];
                    dp[i] = dp[j]+1;
                }else if(dp[j]+1==dp[i]){
                    //cnt[i] += cnt[j];
                    string res;
                    string a = cnt[i];
                    string b = cnt[j];
                    add(a,b, res);
                    //cout<<"add "<<a<<" + "<<b<<" = "<<res<<endl;
                    cnt[i] = res;
                }
            }
        }
        if(dp[i]>running_max){
            running_max = dp[i];
        }
    }
    for(int i=0; i<=N; i++){
        cout<<data[i]<<" ";
    }cout<<endl;
    for(int i=0; i<=N; i++){
        cout<<dp[i]<<" ";
    }cout<<endl;
    for(int i=0; i<=N; i++){
        cout<<cnt[i]<<" ";
    }cout<<endl;

    int ans_cnt = -1;
    //ans_cnt = cnt[N-1];
    reverse(cnt[N].begin(), cnt[N].end());
    fout<<dp[N]-1<<" "<<cnt[N]<<endl;
}


int main(){
    string a = "0082";
    string b = "00002";
    string res;
    add(a,b,res);
    reverse(res.begin(),res.end());
    cout<<res<<" res"<<endl;
    
    fin>>N;
    for(int i=1; i<=N; i++)fin>>data[i];
    //data[N] = 0;
    //N+=1;
    work();
    return 0;
}

