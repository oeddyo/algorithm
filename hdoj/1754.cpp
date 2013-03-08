#include <iostream>

using namespace std;
int N,M;
const int MAXN = 200000;
int data[MAXN*8];
const int INF = 999999999;

void pushUp(int idx){
    data[idx] = max( data[idx*2], data[idx*2+1]);
}


void build(int l, int r, int idx){
    if(l==r){
        scanf("%d",&data[idx]);
        return ;
    }
    int m = (l+r)>>1;
    build(l, m, idx*2);
    build(m+1, r, (idx*2)+1);
    pushUp(idx);
}


int query(int L, int R, int l, int r, int idx){
    if(L<=l && R>=r){
        return data[idx];
    }
    int m = (l+r)>>1;
    int ret1=-INF,ret2=-INF;
    if(L<=m)ret1 = query(L,R,l,m,idx*2);
    if(R>m)ret2 = query(L,R,m+1,r,idx*2+1);
    return max(ret1,ret2);
}

void update(int L, int R, int l, int r, int idx, int value){
    if(L<=l && R>=r){
        data[idx] = value;
        return;
    }
    int m = (l+r)>>1;
    if(R<=m){
        update(L,R,l,m,idx*2,value);
    }else if(L>=m+1){
        update(L,R,m+1,r,idx*2+1,value);
    }
    pushUp(idx);
}

int main(){
    while(scanf("%d%d",&N,&M)!=EOF){
        getchar();
        build(1,N,1);
        char op[2];
        int a,b;
        for(int i=0; i<M; i++){
            scanf("%s %d %d",op,&a,&b);
            if(op[0]=='Q'){
                cout<<query(a,b,1,N,1)<<endl;;
            }else{
                update(a,a,1,N,1,b);
            }
        }


    }

    return 0;
}




