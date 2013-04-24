#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>

using namespace std;

typedef long long int ll;

long long int dp[4][4];
long long int bf[4][4];
int N;

long long int MOD = 1000000007;

void multi(ll a[][4], ll b[][4], ll res[][4]){
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            ll tmp = 0;
            for(int k=0; k<4; k++){
                tmp += a[i][k]*b[k][j];
            }
            res[i][j] = tmp%MOD;
        }
    }
}


void print(ll a[][4]){
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}

void mypow(ll input[][4], ll output[][4], int n){
    ll tmp[4][4];
    ll tmp2[4][4];
    memset(tmp, 0 , sizeof(tmp));
    memset(tmp2, 0, sizeof(tmp2));
    //cout<<"input is "<<endl;
    //print(input);
    if(n==1){
        for(int i=0; i<4; i++){
            for(int j=0; j<4; j++){
                output[i][j] = input[i][j];
            }
        }
        return ;
    }else if(n%2==1 && n>1){
        mypow(input, tmp, n/2);
        multi(tmp, tmp, tmp2);
        multi(input, tmp2, output);
    }else if(n%2==0 && n>0){
        mypow(input, tmp,  n/2);
        multi(tmp, tmp, output); 
    }
}


void work(){
    ll ans[4][4];
    memset(ans,0,sizeof(ans));
    mypow(dp, ans, N);
    //print(ans);
    
    cout<<ans[3][3]<<endl;

}



int main(){
    cin>>N;
    for(int i=0; i<4; i++){
        for(int j=0;j<4; j++){
            if(i==j)continue;
            dp[i][j] = 1;
        }
    }
    work();
    
    
    
    return 0;
}

