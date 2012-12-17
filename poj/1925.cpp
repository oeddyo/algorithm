#include <iostream>
#include <cmath>
#define MAXN 5002
#define INF 999999999
#define MAXM 2001000
using namespace std;

int N,K,ans;
long long int dp[MAXM];
int d[MAXN][2];

void work(){
    for(int i=0; i<MAXM;i++)dp[i]=INF;
    dp[ d[0][0] ] = 0;
    long long int h = d[0][1];
    ans = INF;

    long long int x, y, rr;
    for(int i=1; i<N; i++){
        x = d[i][0], y = d[i][1];
        long long int delta =  floor(sqrt(y*y - (y - h)*(y-h)));
        for(int j=d[i][0] - delta; j<=d[i][0]; j++){
            if(j<0 || dp[j]==INF)continue;
            //cout<<"seeing "<<i<<" "<<j<<endl;
            //cout<<"delta here is "<<delta<<endl;
            int left = j;
            int right = 2*d[i][0] - j;
            if(dp[left]+1 < dp[right]){
                dp[right] = dp[left]+1;
                //cout<<"updating for "<<left<<"->"<<right<<endl;
                if(right>=d[N-1][0]){
                    if(dp[right]<ans){
                        ans = dp[right];
                    }
                }
            }
        }
    }
    if(ans==INF){
        cout<<"-1"<<endl;
    }else{
        cout<<ans<<endl;
    }
}
int main(){
    cin>>K;
    while(K--){
        cin>>N;
        for(int i=0; i<N; i++){
            cin>>d[i][0]>>d[i][1];
        }
        work();
    }
    return 0;
}
