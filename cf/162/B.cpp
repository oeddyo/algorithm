#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAXN = 100002;
int N, d[MAXN], dp[MAXN], c[MAXN], idx[MAXN];

int my_gcd(int a, int b){
    while(b!=0){
        int t = b;
        b = a%t;
        a = t;
    }
    return a;
}


int main(){

    cin>>N;
    for(int i=0; i<N; i++){
        cin>>d[i];
        dp[i] = 1;
    }
    
    int ans = 1, sz = 1;

    for(int i=1; i<N; i++){
        int up = sqrt(dp[i])+1;
        for(int k=1; k<=up; k++){
            if(i%k==0){
                if(my_gcd(d[k], d[i])>1 && dp[k]+1<dp[i]){
                    dp[i] = dp[k]+1;
                }
            }
        }
        ans = max(dp[i], ans);
    }
    cout<<ans<<endl;
    return 0;
}

