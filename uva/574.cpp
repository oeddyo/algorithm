#include <iostream>
#include <string.h>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

const int MAXN = 13;
int N,T,data[MAXN], pre[MAXN];
vector< vector<int> > ans;
void dfs(int cur, int sum){
    if(sum>T)return ;
    if(sum==T){
        int pos = cur;
        vector<int> t_v;
        while(pos!=-1){
            t_v.push_back(data[pos]);
            pos = pre[pos];
        }
        reverse(t_v.begin(), t_v.end());
        ans.push_back(t_v);
    }
    for(int i=cur+1; i<N; i++){
        pre[i] = cur;
        dfs(i,sum+data[i]);
    }
}
void print(vector<int> &v){
    cout<<v[0];
    for(int i=1; i<v.size(); i++){    
        cout<<"+"<<v[i];
    }cout<<endl;
}

void work(){
    memset(pre,-1,sizeof(pre));
    ans.clear();
    dfs(-1, 0);
    set< vector<int> >S;
    cout<<"Sums of "<<T<<":"<<endl;
    if(ans.size()==0){
        cout<<"NONE"<<endl;
    }else{
        for(int i=0; i<ans.size(); i++){
            if(S.find(ans[i])==S.end()){
                S.insert(ans[i]);
                print(ans[i]);
            }
        }
    }
}

int main(){
    while(cin>>T>>N){
        if(T==0&&N==0)break;
        for(int i=0; i<N; i++){
            cin>>data[i];
        }
        work();
    }
    return 0;
}

