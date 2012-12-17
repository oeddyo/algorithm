#include <iostream>

using namespace std;
int dp[9][51][1<<11];

int N,M,K;
int main(){
    cin>>N>>M>>K;
    
    memset(dp,0,sizeof(dp));

    //initial
    /*
    for(int i=0; i<N; i++){
        int s = 1<<(M-1);
        while(s){
            dp[1][i][s] = 1;
            s>>=1;
        }
    }*/
        for(int s = 0; s<=(1<<(M-1)); s++){    
            if(!valid(s))continue;
            int cnt = count(s);
            if(cnt<=K)
                dp[cnt][0][s] = 1;
        }

    for(int i=1; i<N; i++){
        for(int s = 0; s<=(1<<M)-1; s++){
            if(!valid(s))continue;
            int cnt = count(s);
            if(cnt>K)continue;

            for(int ps = 0; ps<=(1<<M)-1; ps++){
                if( !ps&s==0 || !valid(ps)){
                   continue; 
                }
                for(int k=0; k<=K-cnt; k++){
                    dp[cnt][i][s] += dp[k][i-1][ps];
                }
            }
        }
    }


    return 0;
}

