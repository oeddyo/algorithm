#include <iostream>
#include <cmath>
#include <stdio.h>
#define MAXN 50002
using namespace std;

int data[MAXN];
int N,Q;

int min_rmq[MAXN][20];
int max_rmq[MAXN][20];

void min_rmq_build(){
    for(int i=0; i<N; i++){
        //min_rmq[i][0] = data[i];
        min_rmq[i][0] = i;
    }

    for(int j=1; j<20; j++){
        for(int i=0; i+(1<<j)-1 < N; i++){
            //min_rmq[i][j] = min( min_rmq[i][ (j-1) ], min_rmq[i+(1<<(j-1))][(j-1)]);
            if( data[min_rmq[i][(j-1)]] > data[min_rmq[i+(1<<(j-1))][j-1]]){
                min_rmq[i][j] = min_rmq[i+(1<<(j-1))][j-1];
            }else{
                min_rmq[i][j] = min_rmq[i][j-1];
            }
        }
    }
}

int query_min(int t_left, int t_right){
    int length = floor(log10(t_right-t_left+1)/log10(2));
    return min(data[min_rmq[t_left][length]], 
    data[min_rmq[t_right- (1<<length)+1 ][length]]);
}

void max_rmq_build(){
    for(int i=0; i<N; i++){
        //min_rmq[i][0] = data[i];
        max_rmq[i][0] = i;
    }

    for(int j=1; j<20; j++){
        for(int i=0; i+(1<<j)-1 < N; i++){
            //min_rmq[i][j] = min( min_rmq[i][ (j-1) ], min_rmq[i+(1<<(j-1))][(j-1)]);
            if( data[max_rmq[i][(j-1)]] > data[max_rmq[i+(1<<(j-1))][j-1]]){
                max_rmq[i][j] = max_rmq[i][j-1];
            }else{
                max_rmq[i][j] = max_rmq[i+(1<<(j-1))][j-1];
            }
        }
    }
}

int query_max(int t_left, int t_right){
    int length = floor(log10(t_right-t_left+1)/log10(2));
    return max(data[max_rmq[t_left][length]], 
    data[max_rmq[t_right- (1<<length)+1 ][length]]);
    //return min(min_rmq[t_left][length], 
    //min_rmq[t_right- (1<<length)+1 ][length]);
}
/*void max_rmq_build(){
    for(int i=0; i<N; i++){
        max_rmq[i][0] = data[i];
    }

    for(int j=1; j<20; j++){
        for(int i=0; i+(1<<j)-1 < N; i++){
            max_rmq[i][j] = max( max_rmq[i][ (j-1) ], max_rmq[i+(1<<(j-1))][(j-1)]);
        }
    }
}

int query_max(int t_left, int t_right){
    int length = floor(log10(t_right-t_left+1)/log10(2));
    return max(max_rmq[t_left][length], 
    max_rmq[t_right- (1<<length)+1 ][length]);
}*/

int main(){
    scanf("%d %d",&N,&Q);
    for(int i=0; i<N; i++)scanf("%d",&data[i]);
    
    min_rmq_build();
    max_rmq_build();

    int t_left, t_right;
    for(int i=0; i<Q; i++){
        scanf("%d %d",&t_left, &t_right);
        int small = query_min(t_left-1, t_right-1);
        //cout<<small<<endl;
        int large = query_max(t_left-1, t_right-1);
        cout<<large-small<<endl;
    }

    return 0;
}

