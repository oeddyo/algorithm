#include <iostream>
#include <stdio.h>
#include <string.h>
#define INF 99999999
#define MAXN 120000
using namespace std;

#define LL long long int 

LL tree[MAXN*8];
LL col[MAXN*8];

int N,Q;

void pushUp(int idx){
    tree[idx] = tree[idx<<1]+tree[idx<<1|1];
}

void pushDown(int idx, int m){
    if(col[idx]!=0){
        col[idx<<1] += col[idx];
        col[idx<<1|1] += col[idx];
        tree[idx<<1] += (m-(m>>1))*col[idx];
        tree[idx<<1|1] += (m>>1)*col[idx];
        col[idx] = 0;
    }
}

void build(int l, int r, int idx){
    if(l==r){
        //cin>>tree[idx];
        scanf("%lld",&tree[idx]);
        col[idx] = 0;
        return ;
    }
    int m = (l+r)>>1;
    build(l,m,idx<<1);
    build(m+1,r,(idx<<1|1));
    pushUp(idx);
}

void insert(int L, int R, int l, int r, int idx, int value){
    if(L<=l && r<=R){
        tree[idx] += (r-l+1)*(LL)value;
        col[idx] += value;
        return ;
    }
    pushDown(idx, r-l+1);
    int m = (l+r)>>1;
    if(L<=m){
        insert(L,R,l,m,idx<<1,value);
    }
    if(R>m){
        insert(L,R,m+1,r,(idx<<1|1),value);
    }
    pushUp(idx);
}

LL query(int L, int R, int l, int r, int idx){
    if(L<=l && r<=R){
        return tree[idx];
    }
    pushDown(idx, r-l+1);
    LL ret = 0;
    int m = (l+r)>>1;

    if(L<=m){
        ret+=query(L,R,l,m,idx*2);
    }
    if(R>m){
        ret+=query(L,R,m+1,r,idx*2+1);
    }
    return ret;
}

int main(){
    while(scanf("%d%d",&N,&Q)!=EOF){
        memset(tree, 0, sizeof(tree));
        memset(col, 0, sizeof(col));
        build(1, N, 1);

        for(int i=0; i<Q; i++){
            char op[2];
            //cin>>op;
            scanf("%s",op);
            int a,b,c;
            if(op[0]=='Q'){
                scanf("%d%d",&a,&b);
                //cin>>a>>b;
                cout<<query(a,b,1,N,1)<<endl;
            }else{
                scanf("%d%d%d",&a,&b,&c);
                //cin>>a>>b>>c;
                insert(a,b,1,N,1,c); 
            }
        }
    }

    return 0;
}

