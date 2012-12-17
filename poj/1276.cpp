#include <iostream>

using namespace std;

int V,N;
int d[12][2];

int INF = 99999999;
int dp[1000001];

void work(){
    for(int i=0; i<=V; i++)dp[i]=0;

    for(int i=1; i<=N; i++){
        int cost, c = d[i][0],k=1;
        //cout<<"----"<<endl;
        while(1){
            if(c <= 0)break;
            if(c - k >=0){
                cost = k*d[i][1];;
                c = c-k;
            }else{
                cost = c*d[i][1];
                c = 0;
            }
            k*=2;
            for(int j = V; j>=1; j--){
                if(j-cost>=0){
                    dp[j] = max(dp[j], dp[j-cost]+cost);
                }else{
                    dp[j] = dp[j];
                }
            }
            //cout<<cost/d[i][1]<<" ";
        }
        //cout<<endl;
        //cout<<"----"<<endl;
    }
    
    int ans = -INF,pos=-1;
    for(int i=0 ;i<=V; i++){
    //    cout<<dp[i]<<" ";
        if(dp[i]>=ans){
            ans= dp[i];
        }
    }
    //cout<<endl;
    cout<<ans<<endl; 
}

int main(){
    while(cin>>V){
        cin>>N;
        for(int i=1; i<=N; i++){
            cin>>d[i][0]>>d[i][1];
        }
        work();
    }

    return 0;
}
