#include <iostream>

using namespace std;

const int MAXN = 100001;
int tree[MAXN*8],N,T, lazy[MAXN*8];

void pushUp(int idx){
    tree[idx] = tree[idx*2] + tree[idx*2+1];
}

void build(int l, int r, int idx){
    if(l==r){
        tree[idx] = 1;
        return;
    }
    int m = (l+r)>>1;
    build(l, m, idx*2);
    build(m+1, r, idx*2+1);
    pushUp(idx);
}

void insert(int L, int R, int l, int r, int idx, int value){
    cout<<"now idx = "<<idx<<endl;
    if(L<=l && r<=R){
        cout<<"inserting "<<L<<" to "<<R<<" idx = "<<idx<<" value = "<<value<<endl;
        tree[idx] = (R-L+1)*value;
        return ;
    }
    int m = (l+r)>>1;
    if(L<=m){
        insert(L, m, l, m, idx*2, value);
    }
    if(R>m){
        insert(m+1, R, m+1, r, idx*2+1, value);
    }
    pushUp(idx);
}

void work(){
    int ops;
    scanf("%d",&ops);
    memset(tree,0,sizeof(tree));
    memset(lazy,0,sizeof(lazy));
    build(1,N,1);
    cout<<"ops = "<<ops<<endl;
    for(int i=0; i<ops; i++){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        insert(a,b,1,N,1,c);
    }
    cout<<tree[1]<<endl;
}



int main(){
    scanf("%d",&T);
    for(int t=1; t<=T; t++){
        scanf("%d",&N);
        work();
    }

    return 0;
}

