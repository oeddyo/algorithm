#include <iostream>
#include <algorithm>
#define MAXN 100000
#define INF 999999999
using namespace std;

int data[MAXN],dp[MAXN], pos[MAXN];
int T,num;

int get_max_continuous(int start, int end, int *result_left, int *result_right){
    int tmp_sum = 0;
    memset(dp,0,sizeof(dp));
    dp[start] = data[start];
    pos[start]=-1;
    int t_max = -INF;
    for(int i=start+1; i<end; i++){
        if(dp[i-1]+data[i] > data[i]){
            dp[i] = dp[i-1]+data[i];
            pos[i] = i-1;
        }else{
            dp[i] = data[i];
            pos[i]=-1;
        }
        cout<<"i-> "<<i<<" "<<dp[i]<<endl;
        if(dp[i]>t_max){
            t_max = dp[i];
        }
    }
    
    int t_left = -1;
    int pre = start;
    int t_t_max = -INF;
    for(int i=start+1; i<end; i++){
        if(pos[i]==-1){
            int len = i-pre;
            if(len>t_t_max){
                t_t_max = len;
                *result_left = pre;
                *result_right = i-1;
            }
            pre = i;
        }
    }
    return t_max;
}

int main(){
    scanf("%d",&T);
    while(T--){
        char *t = (char*) malloc(sizeof(char)*5000);
        getchar(); 
        scanf("%d", &num);
        for(int i=0;i <num; i++){
            scanf("%d",&data[i]);
        }
        int start=-1,  end=-1;
        int t1 = get_max_continuous(0, num, &start, &end);
        cout<<"start and end are "<<start<<" "<<end<<endl;
        cout<<t1<<endl;
        int n_t, n_t2;
        int t2 = get_max_continuous(0, start,&n_t,&n_t2); 
        cout<<t2<<endl;
        int t3 = get_max_continuous(end, num, &n_t, &n_t2);
        cout<<t3<<endl;
        cout<<t1+max(t2,t3)<<endl;
    }
    return 0;
}

