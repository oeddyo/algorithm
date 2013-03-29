#include <iostream>

using namespace std;

const int MAXN = 120001;
int tree[MAXN*8],N,T;
int lazy[MAXN*8];
int cur_case;
//int sum[MAXN*8];


void pushUp(int idx){
    tree[idx] = tree[idx*2] + tree[idx*2+1];
}

void pushDown(int idx, int m){
    if(lazy[idx]){
        lazy[idx<<1] = lazy[idx<<1|1]= lazy[idx];
        tree[idx<<1] = (m-(m>>1))*lazy[idx];
        tree[idx<<1|1] = (m>>1)*lazy[idx];
        lazy[idx] = 0;
    }
}
void build(int l, int r, int idx){
    if(l==r){
        tree[idx] = 1;
        lazy[idx] = 0;
        return;
    }
    int m = (l+r)>>1;
    build(l, m, idx*2);
    build(m+1, r, idx*2+1);
    pushUp(idx);
}
/*
void build(int l, int r, int idx){
    lazy[idx] = 0;tree[idx] = 1;
    if(l==r)return;
    int m = (l+r)>>1;build(l,m,idx*2);build(m+1,r,idx*2+1);
    pushUp(idx);
}
*/

void insert(int L, int R, int l, int r, int idx, int value){
    if(L<=l && r<=R){
        tree[idx] = (r-l+1)*value;
        lazy[idx] = value;
        return ;
    }
    pushDown(idx, r-l+1);
    int m = (l+r)>>1;
    if(L<=m){
        insert(L, R, l, m, idx*2, value);
    }
    if(R>m){
        insert(L, R, m+1, r, idx*2+1, value);
    }
    pushUp(idx);
}

void work(){
    int ops;
    scanf("%d",&ops);
    memset(tree,0,sizeof(tree));
    memset(lazy,0,sizeof(lazy));
    build(1,N,1);
    for(int i=0; i<ops; i++){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        insert(a,b,1,N,1,c);
    }
    cout<<"Case "<<cur_case<<": The total value of the hook is "<<tree[1]<<"."<<endl;
}

int main(){
    scanf("%d",&T);
    for(int t=1; t<=T; t++){
        cur_case = t;
        scanf("%d",&N);
        work();
    }

    return 0;
}

