#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int N,K;
char R;
const int MAXN = 51;
const int MAXK = 2501;
//string dp[4][MAXN][11];

long long int dp[4][MAXN][MAXK];

int g[4][2] = {
    {2,1},
    {3,0},
    {0,3},
    {1,2}
};
void print(long long int state){
    for(int i=N-1; i>=0; i--){
        cout<<((state>>i)&1);
    }
    cout<<endl;
}
void work(){
    long long int INF = (long long int)(1) << 62;
    for(int i=0; i<4; i++)for(int j=0; j<MAXN; j++)for(int k=0; k<MAXK; k++)dp[i][j][k]=INF;
    
    long long int cur, s_zero, s_one, ptr;
    dp[0][0][1] = 0;
    for(int j=0; j+1<=N; j++){
        for(int i=0; i<=3; i++){
            for(int k=1; k<MAXK; k++){
            if(dp[i][j][k]==INF)continue;
                cur = dp[i][j][k];
                //cur = dp[i][j][1];
                int c_zero = g[i][0];
                int c_one = g[i][1];
                s_zero = (cur<<1);
                s_one = (cur<<1)|1;
                //int *ptr = lower_bound(dp[c_zero][j+1]+1, dp[c_zero][j+1]+MAXK+1,s_zero);
                int ptr = 1; 
                while(dp[c_zero][j+1][ptr] < s_zero){
                    ptr++;
                }
                if(ptr<=MAXK){
                    for(int tt = MAXK; tt>ptr; tt--){
                        dp[c_zero][j+1][tt] = dp[c_zero][j+1][tt-1];
                    }
                    dp[c_zero][j+1][ptr] = s_zero;
                }
                ptr = 1;

                while(dp[c_one][j+1][ptr] < s_one){
                    ptr++;
                }
                if(ptr<=MAXK){
                    for(int tt = MAXK; tt>ptr; tt--){
                        dp[c_one][j+1][tt] = dp[c_one][j+1][tt-1];
                    }
                    dp[c_one][j+1][ptr] = s_one;
                }
            }
        }
    }
    
    /*
    for(int k=0; k<=N; k++){
        for(int c = 0; c<=3; c++){
            if(dp[c][k]==INF)continue;
            cout<<"now k is "<<k<<endl;
            int c_zero = g[c][0];
            int c_one = g[c][1];
            string cur = dp[c][k];
            string s_zero, s_one;
            cout<<"from city "<<char(c+'A')<<" to 0 city "<<char(c_zero+'A')<<endl;
            cout<<"from city "<<char(c+'A')<<" to 1 city "<<char(c_one+'A')<<endl;
            s_zero = cur+"0";
            s_one = cur+"1";
            cout<<"s_one is "<<s_one<<endl;
            cout<<"s_zero is "<<s_zero<<endl;
            
            if( s_zero<dp[c_zero][k+1] ){
                dp[c_zero][k+1] = s_zero;
            }
            if( s_one<dp[c_one][k+1]){
                dp[c_one][k+1] = s_one;
            }
            if(k==N-1 && c_zero==R-'A'){
                cout<<"!!!!final!!!!!"<<endl;
                cout<<s_zero<<endl;
            }
            if(k==N-1 && c_one ==R-'A'){
                cout<<"!!!!final!!!!!"<<endl;
                cout<<s_one<<endl;
            }

        }
    }*/
    /*for(int i=1; i<=10; i++){
        print(dp[R-'A'][N][i]);
    }
    return ;
    */
/*
    for(int i=0; i<4; i++){
        for(int j=0; j<=50; j++){
            for(int k=1; k<=10; k++){
                print(dp[i][j][k]);
            }
        }
    }
    */
    if(dp[R-'A'][N][K]!=INF){
        //cout<<dp[R-'A'][N][K]<<endl;     
        print(dp[R-'A'][N][K]);
    }else{
        cout<<"impossible"<<endl;
    }
}

int main(){
    
    cin>>R>>N>>K;
    work();
    return 0;
}

