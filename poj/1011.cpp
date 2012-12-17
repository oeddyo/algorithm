#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

const int MAXN = 50*65;
int N, data[MAXN];
const int INF = 999999999;
int length, ans;
bool used[MAXN];
bool should_return;
int max_depth = 0;
int box_number = 0;

void dfs(int num, int cur_len, int pre){
    if(ans!=-1)return ;
    //cout<<"num: "<<num<<", sum: "<<cur_len<<endl;
    if(num==N&&cur_len==0){
        ans = length;
        should_return = true;
        return ;
    }
    for(int i=pre+1; i<N; i++){
        if(used[i]==false){
            if(cur_len+data[i]>length){
               return ;
                continue;
            }
            used[i]=true;
            if(cur_len+data[i]==length){
                //cout<<"box!!!"<<endl;
                dfs(num+1, 0, -1);
                used[i]=false;
                break;
            }else{
                dfs(num+1, cur_len+data[i], i);
                used[i]=false;
            }
            int p = i;
            while(data[p]==data[i]&&p<N){
                p++;
            }
            i = p;
        }
    }
}

void work(){
    sort(data,data+N);
    reverse(data,data+N);
    int all_sum = 0;
    for(int i=0; i<N; i++){
        //cout<<data[i]<<" ";
        all_sum+=data[i];
    }
    //cout<<endl;
    ans = -1;
    int t_min = INF, t_max = -INF;
    memset(used,0,sizeof(used));
    for(int i=0; i<N; i++){
        t_min = min(t_min, data[i]);
        t_max = max(t_max, data[i]);
    }
    //cout<<"from "<<t_min<<" to "<<MAXN<<endl;
   /* 
    max_depth = 0;
    length = 21;
    dfs(0,0,-1);
*/
    for(length = t_max; length<=all_sum; length++){
        memset(used,0,sizeof(used));
        //cout<<"now length "<<length<<endl;
        if(all_sum%length!=0)continue;
        dfs(0,0,-1);    
        if(ans!=-1){
            break;
        }
    }
    //cout<<"max depth "<<max_depth<<endl;
    cout<<ans<<endl;
}

int main(){
    while(1){
        cin>>N;
        if(N==0)break;
        for(int i=0; i<N; i++){
            cin>>data[i];
        }
        work();
    }
    return 0;
}

