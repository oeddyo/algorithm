#include <iostream>
#include <iomanip>
using namespace std;
int N;
//double dp[20][1<<20];
long double dp[2][1<<20];
long double data[20][20];
inline int count(int s){
    int cnt =0;
    while(s){
        s = s&(s-1);
        cnt++;
    }
    return cnt;
}
int main(){
    cin>>N;
    for(int i=0; i<N; i++){
        for(int j=0;j<N; j++){
           cin>>data[i][j];
           data[i][j]/=100.0;
        }
    }
    for(int i=0; i<N; i++){
        dp[0][1<<(N-i-1)] = data[0][i];
    }
    int tt_cnt, tt_s,t,t_cnt;
    double pp;
    for(int i=1; i<N; i++){
        for(unsigned int s=0; s<=(1<<N)-1; s++){
            /*tt_cnt = 0;
            tt_s = s;
            while(tt_s){
                tt_s=tt_s&(tt_s-1);
                tt_cnt++;
            }*/
            tt_cnt = __builtin_popcount(s);
            //cout<<tt_cnt<<endl;
            if(tt_cnt==i+1){//as long as we could actually add one
                t = 1<<(N-1);
                t_cnt = 0;
                while(t>0){
                    if((t&s)!=0){
                        pp = dp[(i-1)&1][(~t)&s]*data[i][t_cnt];
                        if(pp > dp[i&1][s] ){
                            dp[i&1][s] = pp;
                        }
                    }
                    t_cnt++;
                    t>>=1;
                }
            }
        }
    }
    cout.setf(ios::fixed);
    cout<<setprecision(7)<<dp[(N-1)&1][(1<<N)-1]*100<<endl;
    return 0;
}
