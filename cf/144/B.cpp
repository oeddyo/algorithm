#include <iostream>
#include <map>
#include <vector>
#include <cmath>

using namespace std;

const int MAXN = 10000;
const int INF = 99999999;
long long int N;

long long int get_digits_sum(long long int x){
    int sum = 0;
    while(x){
        sum+=x%10;
        x/=10;
    }
    return sum;
}

long long int solve(int k){
    long long int ans = 0;
    long long int tn = -N;
    long long int test = k*k-4*tn;
    if(test <0){
        return -1;
    }else{
        ans = (long long int ) ( (-k+sqrt(test))/2 );
        return ans;
    }
}


int main(){
    cin>>N;
    long long int left = solve(162);
    long long int right = solve(1);
    right+=1;
    if(left<1){
        left = 1;
    }
    long long int ans = -1;
    for(long long int x = left; x<=right; x++){
        long long int t = N/x;
        double tt = N*1.0/x;
        if( N%x==0 && get_digits_sum(x) == t-x ){
            ans = x;
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}

