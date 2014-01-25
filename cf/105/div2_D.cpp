#include <iostream>
#include <iomanip>    


using namespace std;


const int MAXN = 1001;
double dp[MAXN][MAXN][2];
const double INF = 999999999.99;
int white, black;


double get_ans(int w, int b, int who){
    if(dp[w][b][who]!=INF){
        return dp[w][b][who];
    }
    if(w>0 && b<=0){
        return 1.0;
    }
    if(w<=0 || w+b<=0){
        return 0.0;
    }
    double w_prob = w*1.0/(w+b);
    if(who==0){
        double res = w_prob;
        res += (1-w_prob)*(1-get_ans(w,b-1,1-who));
        dp[w][b][who] = res;
        return res;
    }else{
        double res = w_prob;

        //take one black out
        int cur_b = b-1;
        int cur_w = w;

        //black jump
        if(cur_b-1 >= 0){
            res += (1-w_prob) * (cur_b*1.0/(cur_b + cur_w))*(1-get_ans(cur_w, cur_b-1, 1-who));
        }

        //white jump
        if(cur_w-1 >= 0){
            res += (1-w_prob) * (cur_w*1.0/(cur_w + cur_b))*(1-get_ans(cur_w-1,cur_b, 1-who));
        }
        dp[w][b][who] = res;
        return res;
    }
}



void work(){
    for(int i=0; i<=white; i++){
        for(int j=0;j<=black; j++){
            dp[i][j][0] = dp[i][j][1] = INF;
        }
    }
    
    double ans = get_ans(white, black, 0);
    cout<<std::setprecision(15)<< ans<<endl;
}


int main(){
    cin>>white>>black;
    work();
    return 0;
}

