#include <iostream>
#include <cmath>
#define MAXN 3200000
using namespace std;
long long int q;

int prime[MAXN];
int dp[MAXN];
void Prime(){
    int i, j;
        for (i=0; i<MAXN; i++) prime[i] = 1;
            prime[0] = prime[1] = 0;
            for (i=2; i<MAXN; i++)
            {
                if (!prime[i]) continue;
                for (j=i*2; j<MAXN; j+=i) prime[j] = 0;
            }
}
long long int first_move = -1;

int get_v(long long int value){
    if(value<MAXN){
        if(dp[value]!=-1){
            return dp[value];
        }
        if(prime[value]==1){
            dp[value]=1;
            return 1;
        }
    }
    int b = (int)sqrt(value)+1;
    int ok=0;
    for(int i=2; i<=b; i++){
        if(value%i==0){
            ok=1;
            int t = get_v(i);
            int t2 = get_v(value/i);
            if(t==0 || t2==0){
                if(value<MAXN)dp[value] = 1;
                if(first_move==-1){
                    if(t==0){
                        first_move = i;
                        //cout<<"first movie is i "<<i<<endl;
                    }
                    if(t2==0){
                        //cout<<"first movie is value/ i "<<value/i<<endl;
                        first_move = value/i;
                    }
                }
                return 1;
            }
        }
    }
    if(ok==0){
        return 1;
    }
    if(value<MAXN)
        dp[value]=0;
    return 0;
}


int main(){
    for(int i=0; i<MAXN;i++){
    	dp[i]=-1;
	}
    cin>>q;
    Prime();
    prime[1]=1;
    int ans = get_v(q);
    if(ans==1){
        cout<<1<<endl;
        if(first_move!=-1){
            cout<<first_move<<endl;
        }else{
            cout<<0<<endl;
        }
    }
    else{
        cout<<2<<endl;
    }
    return 0;
}
