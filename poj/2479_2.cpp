#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 100000
#define INF 999999999
using namespace std;

int data[MAXN],dp_left[MAXN], dp_right[MAXN];
int T,num;

int pos_left[MAXN], pos_right[MAXN];

void compute_left(int left, int right){
    memset(dp_left,0,sizeof(dp_left));
    dp_left[left] = data[left];
    int t_max = data[left];
    pos_left[left] = data[left];
    //int ans = -INF;
    for(int i=left+1; i<right; i++){
        //t_max = max(t_max+data[i], data[i]);
        //ans = max(ans, t_max);
        dp_left[i] = max(dp_left[i-1]+data[i], data[i]);
        if(t_max < dp_left[i]){
            t_max = dp_left[i];
        }
        pos_left[i] = t_max; 
    }
    //return t_max;
}
void compute_right(int left, int right){
    memset(dp_right, 0, sizeof(dp_right));
    dp_right[right-1] = data[right-1];
    int t_max = dp_right[right-1];
    pos_right[right-1] = data[right-1];
    for(int i=right-2; i>=left; i--){
        dp_right[i] = max(dp_right[i+1]+data[i], data[i]);
        if(dp_right[i]>t_max)t_max=dp_right[i];
    
        pos_right[i] = t_max;

    }
    //return t_max;
}


int get_ans(int left, int right){
    compute_left(left, right);
    /*
    for(int i=left; i<right; i++){
        cout<<pos_left[i]<<" ";
    }cout<<endl;
    */
    compute_right(left, right);
    /*
    for(int i=left; i<right; i++){
        cout<<pos_right[i]<<" ";
    }cout<<endl;*/
    int t_max = -INF;
    for(int i=left; i<right-1; i++){
        int t1 = pos_left[i];
        int t2 = pos_right[i+1];
        //cout<<"i "<<i<<" "<<t1<<" "<<t2<<endl;
        if(t1+t2>t_max){
            t_max = t1+t2;
        }
    }
    cout<<t_max<<endl;

}



int main(){
    scanf("%d",&T);
    while(T--){
        getchar(); 
        scanf("%d", &num);
        for(int i=0;i <num; i++){
            scanf("%d",&data[i]);
        }
        get_ans(0,num); 
    
    }
    return 0;
}

