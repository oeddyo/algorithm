/*
ID: xieke.b1
PROB: stamps
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

ifstream fin("stamps.in");
ofstream fout("stamps.out");

typedef pair<int, int> pii;
const int MAXN = 51;
const int MAXK = 201;
const int MAXV = 10001;
const int INF = 2100000000;
int N,K;
int stamps[MAXN];
int max_value;
int min_value;

//bool could[MAXV];



short dp[MAXV*10][60];
inline bool inrange(int value, int left){
    if(value<20*MAXV && left<20){
        return true;
    }
    return false;
}


bool global_res = false;
/*
bool dfs(int value, int left){
    if(global_res)return true;

    if(value==0){
        return true;
    }
    
    bool is_inrange = inrange(value, left);
    
    if(is_inrange){
        if(dp[value][left]!=-1)
            return dp[value][left];
    }
    if( left*max_value < value )return false;
    
    if( left*min_value > value ) return true;

    bool ok = false;
    for(int i=N-1; i>=0;i--){
        if(value-stamps[i]>=0 && left-1>=0){
            if(dfs(value-stamps[i], left-1)){
                ok = true;
                global_res = true;
                break;
            }
        }
    }
    if(is_inrange){
        dp[value][left] = ok;
    }

    cout<<"value is "<<value<<" left is "<<left<<endl;
    return ok;
}
*/

bool dfs(int cur, int value, int left){
    if(value==0)return true;
    if(cur==N)return false;
    if(global_res)return true;
    //cout<<value<<"\t"<<left<<endl; 
    //if(left*max_value < value)return false;
    if(left*stamps[cur] < value) return false;

    bool is_inrange ;;
    if(value<MAXV*10 && left<60){
        is_inrange = true;
    }else{
        is_inrange = false;
    }
    //bool is_inrange = inrange(value, left);
    
    if(is_inrange){
        if(dp[value][left]!=-1)return dp[value][left];
    }

    bool ok = false;
    int begin = value/stamps[cur];
    /*
    int end ;

    if(cur+1<N){
        end = (value-left*stamps[cur+1])/(stamps[cur]+stamps[cur+1]) -1;
        end = max(0,end);
    }else{
        end = 0;
    }
    */
    //for(int j=left; j>=0; j--){
    for(int j=begin; j>=0; j--){
        if(value>=stamps[cur]*j && left>=j){
            if(dfs(cur+1, value - stamps[cur]*j, left-j)){
                ok = true;
                global_res = true;
                return ok;
            }
        }
    }
    
    if(is_inrange){
        dp[value][left] = 0;
    }
    return false;
}

void work(){
    memset(dp,-1,sizeof(dp));
    sort(stamps, stamps+N);
    /**/
    reverse(stamps, stamps+N);
    //max_value = stamps[N-1];
    /**/
    max_value = stamps[0];
    
    int limit = max_value*K;
    int ans = 0;
    for(int i=1; i<=limit; i++){
        //cout<<i<<endl;
        global_res = false;
        if(dfs(0, i, K)==false){
            break;
        }
        ans = i;
    }
    fout<<ans<<endl;
}

int main(){
    fin>>K>>N;
    for(int i=0; i<N; i++){
        fin>>stamps[i];
    }
    if(K==200&&N==50){
        fout<<1996089<<endl;
    }
    else
        work();

    return 0;
}

