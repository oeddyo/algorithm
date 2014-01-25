#include <iostream>
#include <cstring>

using namespace std;

int N,M,K;
const int MAXN = 201;
const int INF = -99999999;
const int SPECIAL = 932492348;
int dp[MAXN][MAXN];
int n_min;
string train;
string s_tmp;
int ctr[MAXN];

int dfs(int min, int st_pos ){
    if(st_pos == ctr[min]){
        return min;
    }
    if(min==n_min-1){
        return INF;
    }

    if(dp[min][st_pos]!=SPECIAL){
        return dp[min][st_pos];
    }
    
    //cout<<"in "<<min<<" "<<st_pos<<endl; 
    int caught = INF; 
    if(train[min]=='0'){
        //moves
        //cout<<"go first"<<endl;
        int tail=-1, head=-1, stay=-1;
        if(st_pos+1==ctr[min] && st_pos+1<N){
            tail = min+1;
        }else if(st_pos+1<N){
            tail = dfs(min+1, st_pos+1);
        }
        if(st_pos-1==ctr[min]){
            head = min+1;
        }else if(st_pos-1>=0){
            head = dfs(min+1, st_pos-1);
        }
        stay = dfs(min+1, st_pos);
        //cout<<"min = "<<min<<" "<<tail<<" "<<head<<" "<<stay<<endl;
        if(tail==INF ||  head==INF || stay==INF){
            caught = INF;
            //cout<<"go to first"<<endl;
        }else{
            //cout<<"go to second"<<endl;
            caught = max(tail, max(head, stay));
        }
    }else{
        int t_max = INF;
        caught = -1;
        //cout<<"go second"<<endl;
        for(int i=0; i<N; i++){
            //if(ctr[min]!=i){
                int t = dfs(min+1, i);    
                t_max = max(t_max, t);
                if(t==INF){
                    caught = INF;
                }
            //}
        }
        if(caught!=INF){
            caught = t_max;
        }
    }
    dp[min][st_pos] = caught;

    return caught;
}




void work(){
    int ans = dfs(0, M);
    if(ans==INF){
        cout<<"Stowaway"<<endl;
    }else{
        cout<<"Controller "<<ans<<endl;
    }

}


int main(){
    for(int i=0; i<MAXN; i++){
        for(int j=0; j<MAXN; j++){
            dp[i][j] = SPECIAL;
        }
    }

    cin>>N>>M>>K;
    M--,K--;
    cin>>s_tmp;
    cin>>s_tmp;
    cin>>train;
    
    n_min = train.length();
    int dir = -1;
    //dir = 0 head --
    //dir = 1 tail ++
    if(s_tmp[0]=='h'){
        dir = 0;
    }else{
        dir = 1;
    }
    int cur_time = 0;
    int pos = K ;
    while(cur_time<n_min){
        ctr[cur_time] = pos;
        if(dir==0){
            pos--;
        }else{
            pos++;
        }
        if(pos==N-1){
            dir = 0;
        }else if(pos==0){
            dir = 1;
        }
        cur_time+=1;
    }
    work();
    return 0;
}

