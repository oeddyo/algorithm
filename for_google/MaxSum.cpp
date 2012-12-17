#include <iostream>


#define MAXN 1000
using namespace std;


int dp[MAXN];
int q[MAXN];
int rec[MAXN];

void r_print(int data[], int pos){
    if(rec[pos]==-1){
        //cout<<"pos is "<<pos;
        cout<<data[pos]<<" ";
        return ;
    }
    r_print(data, rec[pos]);
    //cout<<"pos is "<<pos;
    cout<<data[pos]<<" ";
}

void work(int data[], int N, int max_sum){
        int len = -1;
        if(data[0] > max_sum){
            dp[0] = 0;
            q[0] = 0;        
        }else{
            dp[0] = 1;
            q[0] = data[0];
        }
        rec[0] = -1;

        int end_pos = -1;
        int max_ans = -1;
        for(int i=1; i<N; i++){
            //each step of dp we have a choice of including ith element in data or not
            int pos = -1;
            for(int j = 0; j<i; j++){
                if(data[i]+q[j] <=max_sum && dp[j]+1 > dp[i]){
                    dp[i] = dp[j]+1;
                    q[i] = data[i]+q[j];
                    pos = j;
                    rec[i] = j;
                    if(dp[i]> max_ans){
                        max_ans = dp[i];
                        end_pos = i;
                    }
                }
            }
        }
        cout<<"end pos is "<<end_pos<<endl;
        for(int i=0; i<N;i++){
            cout<<rec[i]<<" ";
        }cout<<endl;
        r_print(data, end_pos);
}



int main(){
        int data[] = {1, -2, 4, 5, -2, 6, 7};
        int N = 7;
        int max_sum = 7;
        work(data, N, max_sum);


return 0;
}
