#include <iostream>
#include <queue>
#include <cmath>
#include <stdio.h>
#define MAXN 1000002
using namespace std;


int N,K, data[MAXN];
//int max_ans[MAXN], min_ans[MAXN];
//int cnt_max=0, cnt_min = 0;
int limit = -1;
//int rmq_min[MAXN][21];
//int rmq_max[MAXN][21];

int rmq_min[MAXN][2];
int rmq_max[MAXN][2];

void build_rmq_min(){
    for(int j=1; j<=limit; j++){
        for(int i=0; i+(1<<j) <= N; i++){
            rmq_min[i][j&1] = min( rmq_min[i][(j-1)&1], rmq_min[i+(1<<(j-1))][(j-1)&1]);
        }
    }
}

void build_rmq_max(){
    for(int j=1; j<=limit; j++){
        for(int i=0; i+(1<<j) <= N; i++){
            rmq_max[i][j&1] = max( rmq_max[i][(j-1)&1], rmq_max[i+(1<<(j-1))][(j-1)&1]);
        }
    }
}

/*int query_max(int len, int left, int right){
    //int t = log10((right-left))/log10(2);
    return max(rmq_max[left][len%2], rmq_max[right-(1<<len)][len%2]);
}

int query_min(int len, int left, int right){
    return min(rmq_min[left][len%2], rmq_min[right-(1<<len)][len%2]);
}
*/

void work(){
    for(int i=0; i<N; i++){
        rmq_min[i][0] = data[i];
        rmq_max[i][0] = data[i];
    }
    //limit = ceil(log10(N)/log10(2));
    limit = ceil(log((double)K)/log(2.0));
    build_rmq_min();
    build_rmq_max();
    int len = floor(log((double)K)/log(2.0));
    /*for(int i=K-1; i<N; i++){
        //max_ans[cnt_max++] = query_max(len, i-K+1, i+1);
        max_ans[cnt_max++] = max(rmq_max[i-K+1][len&1], rmq_max[(i+1)-(1<<len)][len&1]);
        min_ans[cnt_min++] = min(rmq_min[i-K+1][len&1], rmq_min[(i+1)-(1<<len)][len&1]);
        //min_ans[cnt_min++] = query_min(len, i-K+1, i+1);
    }*/

    for(int i=K-1; i<N-1; i++){
        printf("%d ",min(rmq_min[i-K+1][len&1], rmq_min[(i+1)-(1<<len)][len&1]));
    }
    printf("%d\n", min(rmq_min[N-1-K+1][len&1], rmq_min[(N-1+1)-(1<<len)][len&1]));

    for(int i=K-1; i<N-1; i++){
        printf("%d ",max(rmq_max[i-K+1][len&1], rmq_max[(i+1)-(1<<len)][len&1]));
    }
    printf("%d\n", max(rmq_max[N-1-K+1][len&1], rmq_max[(N-1+1)-(1<<len)][len&1]));
    /*for(int i=0; i<cnt_min-1; i++){
        printf("%d ",min_ans[i]);
    }printf("%d\n",min_ans[cnt_min-1]);

    for(int i=0; i<cnt_max-1; i++){
        printf("%d ",max_ans[i]);
    }printf("%d\n",max_ans[cnt_max-1]);
  */
}
int main(){
    scanf("%d %d",&N,&K);
    for(int i=0; i<N; i++)scanf("%d",&data[i]);
    work();
    return 0;
}

