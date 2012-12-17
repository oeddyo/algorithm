#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;

const int MAXN = 10000;
int prime[MAXN];
int p_cnt = 0;
long long int m,a,b;
int main(){
    for(int i=2; i<=50000; i++){
        bool p=true;
        for(int j=2; j*j<=i; j++){
            if(i%j==0){
                p=false;
                break;
            }
        }
        if(p){
            prime[p_cnt++] = i;
        }
    }

    while(1){   
    scanf("%lld %lld %lld",&m,&a,&b);
    if(m==0&&a==m&&b==a)break;
    long long int p, q;
    long long int limit = ceil(double(m*b)/double(a));
    long long int ans = 0;
    long long int ans_p, ans_q;
    for(int i=0; i<p_cnt; i++){
        p = prime[i];
        for(int j=i; j<p_cnt; j++){
            q = prime[j];
            /*if(q*q>limit){
                break;
            }*/
            if(p*q>m)break;
            if(a*q<=p*b){
                if(p*q > ans){
                    ans = p*q;
                    ans_p = p, ans_q = q;
                }
            }
        }
    }
    //cout<<ans<<endl;
    cout<<ans_p<<" "<<ans_q<<endl;

    }
    return 0;
}
