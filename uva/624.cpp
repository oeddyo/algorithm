#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;


const int MAXN = 1000;
const int INF = 99999999;
int data[MAXN];
int cnt;
int N;

int ans = -INF, pos, ans_sum;
vector<int> ans_v;

int dfs(int cur, int sum){
    if(cur>cnt){
        return sum;
    }
    int t1 = dfs(cur+1, sum);;
    int t2 = -INF;
    if(sum+data[cur]<=N){
        t2 = dfs(cur+1, sum+data[cur]);
    }
    if(t1>t2){
        return t1;
    }else{
        return t2;
    }
}
bool dfs2(int cur, int sum){
    if(ans_sum==sum){
        ans_v.push_back(data[cur]);
        return true;
    }
    for(int i=cur+1; i<=cnt; i++){
        if(data[i]+sum<=N){
            if(dfs2(i, sum+data[i])){
                ans_v.push_back(data[cur]);
                return true;
            }
        }
    }
    return false;
}

void work(){
    ans = -INF;
    ans_v.clear();
    ans_sum = dfs(1,0);
    //cout<<"ans_sum is "<<ans_sum<<endl;
    dfs2(0,0);
    reverse(ans_v.begin(), ans_v.end());
    for(int i=1; i<ans_v.size(); i++){    
        cout<<ans_v[i]<<" ";
    }cout<<"sum:"<<ans_sum<<endl;
}


int main(){
    while(cin>>N>>cnt){
        for(int i=1; i<=cnt; i++){
            cin>>data[i];
        }
        work();
    }
    return 0;
}

