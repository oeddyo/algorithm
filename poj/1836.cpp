#include <iostream>
#include <stdio.h>

#define MAXN 1001
#define eps 1e-9
#define INF 99999999
using namespace std;
int N;
double d[MAXN];
int dp_up[MAXN],dp_down[MAXN];

void work(){
    //LIS up

    for(int i=0; i<N; i++){
        dp_up[i] = 1;
        dp_down[i] = 1;
    }
    for(int i=1; i<N; i++){
        for(int j=0; j<i; j++){
            if(d[j]<d[i]){
                if(dp_up[j]+1>dp_up[i]){
                    dp_up[i]=dp_up[j]+1;
                }
            }
        }
    }
    for(int i=N-2; i>=0; i--){
        for(int j=N-1; j>i; j--){
            if(d[j]<d[i]){
                if(dp_down[j]+1>dp_down[i]){
                    dp_down[i]=dp_down[j]+1;
                }
            }
        }
    }
    /*
    for(int i=0; i<N; i++){
        cout<<dp_up[i]<<" ";
    }
    cout<<endl;

    for(int i=0; i<N; i++){
        cout<<dp_down[i]<<" ";
    }
    cout<<endl;
    */
    int ans = INF;
    for(int i=0; i<N; i++){
        int sum = dp_up[i]+dp_down[i]-1;
        if(N-sum<ans){
            ans=N-sum;
        }
    }
    for(int i=0; i<N; i++){
        for(int j=N-1; j>i; j--){
            int t_sum = dp_up[i]+dp_down[j];
            ans = min(ans, N-t_sum);
        }
    }

    
    cout<<ans<<endl;
}

int main(){
    while(cin>>N){    
    for(int i=0;i<N;i++)cin>>d[i];
        work();
    }

    return 0;
}

