#include <iostream>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <vector>
#define MAXN 1500000

using namespace std;

int data[MAXN];
int rmq[MAXN][50];
int N,Q;
void build_rmq(){
    int fill_num = 1<<((int)floor(log10(N)/log10(2))+1);
    for(int i=N; i<fill_num; i++){
        data[i] = data[i-1]+1;
    }
    N = fill_num;

    for(int i=0; i<N; i++){
        rmq[i][0] = 1;
    }
    
    int log_length = (int)(floor(log10(N)/log10(2))+1);
    for(int j=1; j<=log_length; j++)
    {
        for(int i=0; (i + (1<<j) -1) <N; i++)
        {
            int t1 = rmq[i][j-1];
            int t2 = rmq[i+(1<<(j-1))][j-1];
            //int value = rmq[i][j-1];
            int value = data[ i + (1<<(j-1))-1 ];

            int left = i;
            int right = i+(1<<j);       // [ )
            int *t_left_pos = lower_bound( (data+left), (data+right),value);
            int *t_right_pos = upper_bound(data+left, data+right, value);
            //cout<<"search "<<value<<" in range "<<left<<","<<right<<" and find left right are "<<data+left-t_left_pos<<","<<data+right-t_right_pos<<endl;
           
            int sum = t_right_pos-t_left_pos;
            //cout<<" result is "<<sum<<endl;
            rmq[i][j] = max(t1,max(t2,sum));
            //cout<<"at "<<i<<" "<<j<<" "<<rmq[i][j]<<endl;
        }
    }
}

int query(int left, int right){
    int t_length = (int)(floor(log10(right-left+1)/log10(2)));
    int value = data[left+(1<<(t_length))-1];
    int *t_left_pos = lower_bound(data+left, data+right+1, value);
    int *t_right_pos = upper_bound(data+left, data+right+1, value);
    int t1 = t_right_pos-t_left_pos;

    value =  data[right-(1<<t_length)+1];
    t_left_pos = lower_bound(data+left, data+right+1, value);
    t_right_pos = upper_bound(data+left, data+right+1,value);
    int t2 = t_right_pos - t_left_pos;
    return max(max(t1,t2),max( rmq[left][t_length], rmq[right-(1<<t_length)+1][t_length] ));
}


int main(){
    while(scanf("%d",&N)&&N){
        scanf("%d",&Q);
    for(int i=0; i<N; i++)scanf("%d",&data[i]);
   
    int t_left, t_right;
    build_rmq();
    for(int i=0; i<Q; i++){
        scanf("%d %d",&t_left, &t_right);
        //cout<<"cin left and right are "<<t_left<<" "<<t_right<<endl;
        cout<<query(t_left-1, t_right-1)<<endl;
    }
    }
    return 0;
}

