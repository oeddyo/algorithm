#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cstdio>
using namespace std;


const int MAXN = 200001;

int trees[MAXN*8];
int mark[MAXN*8];
int data[MAXN];

int N, Q;

void pushUp(int idx){
    trees[idx] = trees[idx<<1] + trees[idx<<1|1]; 
}

void pushDown(int idx){
    if(mark[idx]){
        //cout<<"now at "<<idx<<" and i'm pushing down"<<endl;
        mark[idx<<1] = mark[idx<<1|1] = mark[idx];
        trees[idx<<1] += trees[idx];
        trees[idx<<1|1] += trees[idx];
        
        trees[idx] = 0;
        
        mark[idx] = 0;
    }
}

void insert(int L, int R, int l, int r, int idx){
    //cout<<"try to insert "<<L<<" "<<R<<" "<<l<<" "<<r<<endl;
    if(L<=l && R>=r){
        //cout<<"insert!"<<endl;
        trees[idx] += 1;
        //ncout<<" idx = "<<idx<<" cur = "<<trees[idx]<<endl;
        mark[idx] = 1;
        return ;
    }
    pushDown(idx);
    int m = (l+r)>>1;
    if(L<=m){
        insert(L, R, l, m, idx<<1);
    }
    if(R>m){
        insert(L, R, m+1, r, idx<<1|1);
    }
    //pushUp(idx);
}

int query(int L, int R, int l, int r, int idx){
    if(L<=l && R>=r){
        return trees[idx];
    }
    pushDown(idx);
    int m = (l+r)>>1;
    if(L<=m){
        return query(L, R, l, m, idx<<1);
    }
    if(R>m){
        return query(L, R, m+1, r, idx<<1|1);
    }
}


void build(int l, int r, int idx){
    if(l==r){
        trees[idx] = 0;
        return ;
    }
    int m = (l+r)>>1;
    build(l, m, 2*idx);
    build(m+1, r, 2*idx + 1);
    pushUp(idx);
}




int main(){
    memset(trees,0,sizeof(trees));
    memset(mark, 0, sizeof(mark));
    scanf("%d %d", &N,&Q);
    
    
    //build(1, N, 1);
    for(int i=0; i<N; i++){
        scanf("%d",&data[i]);
    }

    
    int left, right;
    for(int i=0; i<Q; i++){
        //cout<<"inserting -> "<<i<<" tree[1] = "<<trees[1]<<endl;
        scanf("%d %d", &left, &right);
        insert(left, right, 1, N, 1);
    }
    long long int qts[MAXN];
    //cout<<"query 1 1 "<<query(1,1,1,N,1)<<endl;
    for(int i=0; i<N; i++){
        qts[i] = query(i+1, i+1, 1, N, 1);
        //cout<<"querying "<<i+1<<" res = "<<qts[i]<<endl;
    }
    sort(qts, qts+N, std::greater<int>());
    sort(data, data+N , std::greater<int>());
    long long int ans = 0;
    for(int i=0; i<N; i++){
        ans += (qts[i])*data[i];
        //cout<<"qts["<<i<<"] = "<<qts[i]<<" and data["<<i<<"] = "<<data[i]<<endl;
    }


    cout<<ans<<endl;

    return 0;
}

