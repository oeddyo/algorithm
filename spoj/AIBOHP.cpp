#include <iostream>


using namespace std;
const int MAXN = 5001;
char *S;
short dp[MAXN][MAXN];
int N;
const int INF = 999999999;
int get_ans(int left, int right){
    if(left >= right){
        return 0;
    }

    if(dp[left][right]!=-1)return dp[left][right];
    int t_min = INF;
    if(S[left]==S[right]){
        t_min = min(t_min, get_ans(left+1,right-1));
    }else{
        t_min = min(t_min, get_ans(left,right-1)+1);
        t_min = min(t_min, get_ans(left+1, right)+1);
    }
    dp[left][right] = t_min;
    //cout<<"now in "<<left <<" "<<right<<endl;
    //cout<<"return "<<t_min<<endl;
    return t_min;
}


void work(){
    memset(dp,-1,sizeof(dp));
    int sz = strlen(S);
    int ans = get_ans(0,sz-1);
    cout<<ans<<endl;
}



int main(){
    S = (char*) malloc(sizeof(char)*MAXN);
    while(scanf("%d",&N)!=EOF){
        scanf("%s",S);
        work();
    }
    return 0;
}

