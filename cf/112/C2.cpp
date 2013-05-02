#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;
int K;
string S;

const int MAXN = 1000001;
int pos[MAXN];
long long int dp[MAXN];
long long int sum[MAXN];


void calc(){
    sum[0] = 0;
    sum[1] = 1;
    int S_sz = S.size();
    for(int i=1; i<MAXN; i++){
        sum[i] = i+sum[i-1];
    }
    dp[0] = 0; 
    dp[1] = 1;
    for(int i=2; i<MAXN; i++){
        dp[i] = i+dp[i-1];
    }
    //cout<<dp[2]<<" "<<dp[3]<<" "<<dp[5]<<" "<<dp[6]<<endl;

}


void work(){
    int idx = 0;
    calc();
    int S_sz = S.size();
    for(int i=0; i<S_sz; i++){
        if(S[i]=='1'){
            pos[idx++] = i;
        }
    }
    if(idx<K){
        cout<<0<<endl;
        return ;
    }
    long long int ans = 0;
    int end = K-1, front = 0;
   
    if(K==0){
        if(idx==0){
            cout<<dp[S_sz]<<endl;
        }else{
            ans = dp[pos[0]];
            for(int i=1; i<idx; i++){
                ans += dp[pos[i]-pos[i-1] - 1];
            }
            ans += dp[S_sz-pos[idx-1]-1];
            cout<<ans<<endl;
        }
        return ;
    }



    while(1){
        if(end>=idx)break;
        long long int left, right;
        if(end==idx-1){
            right = S_sz - pos[end] -1 + 1;
        }else{
            right = pos[end+1] - pos[end] -1 + 1; 
        }
        if(front == 0){
            left = pos[0] + 1;
        }else{
            left = pos[front]-pos[front-1]-1 + 1;
        }
        //cout<<"front = "<<front<<" end = "<<end<<" left right = "<<left<<" "<<right<<endl;
        ans += left * right;
        front++, end++;
    }
    cout<<ans<<endl;
}

int main(){
    cin>>K;
    cin>>S;
    work();


    return 0;
}

