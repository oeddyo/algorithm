#include <iostream>
#include <vector>
#include <algorithm>
#define MAXN 1000
using namespace std;
#define INF 2100000000

int T,N;
typedef  pair<int, int> mypair;

vector< mypair > Perl;
long long int dp[MAXN];
int paid[MAXN];
void work(){
    for(int i=0; i<MAXN; i++){
        dp[i]=INF;
        paid[i]=0;
    }
    dp[0] = 0;
    for(int i=1; i<=N; i++){
        int t_cost=INF;
        for(int j=1; j<i; j++){
            if(paid[j]==0){
                t_cost = min(t_cost, Perl[j].first*(Perl[i].second+10));
            }else{
                t_cost = min(t_cost, Perl[j].first*Perl[i].second);
            }
        }
        if(t_cost >= Perl[i].first*(Perl[i].second+10)){
            t_cost = Perl[i].first*(Perl[i].second+10);
            paid[i]=1;
        }
        if(dp[i-1]+t_cost < dp[i]){
                dp[i]=dp[i-1]+t_cost;
        }
        //cout<<"dp["<<i<<"] is "<<dp[i]<<endl;
    }
    cout<<dp[N]<<endl;
}


int main(){
    cin>>T;
    while(T--){
        cin>>N;
        int n,p;
        
        Perl = vector< mypair >();
        for(int i=0; i<N; i++){
            cin>>n>>p;
            Perl.push_back(mypair(p,n));
        }
        reverse(Perl.begin(), Perl.end());
        Perl.insert(Perl.begin(),mypair(INF, INF));
        //sort(Perl.rbegin(), Perl.rend());
        for(int i=0; i<=N; i++){
            //cout<<Perl[i].second<<" "<<Perl[i].first<<endl;
        }
        work();

    }
    return 0;
}
