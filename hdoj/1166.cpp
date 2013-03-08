#include <iostream>

using namespace std;

#define lson l , m , idx << 1
#define rson m + 1 , r , idx << 1 | 1

const int MAXN = 100000;

int data[MAXN*8];

void pushUp(int idx){
    data[idx] = data[idx*2] + data[idx*2+1];
}


void build(int l, int r, int idx){
    if(l==r){
        scanf("%d", &data[idx]);
        return ;
    }
    int m = (l+r)>>1;
    build(lson);
    build(rson);
    pushUp(idx);
}

void update(int p, int value, int l, int r, int idx){
    if(p==l && p==r){
        data[idx] += value;
        return ;
    }
    int m = (l+r)>>1;
    if(p<=m){
        update(p, value, lson);
    }else{
        update(p, value, rson);
    }
    pushUp(idx);
}

int query(int L, int R, int l, int r, int idx){
    if(L<=l && R>=r){
        return data[idx];
    }
    int m = (l+r)>>1;
    int ret = 0;
    if(L<=m) ret+= query(L,R,lson);
    if(R>m) ret+= query(L,R,rson);
    return ret;
}


int main(){
    int T , n;
    scanf("%d",&T);
    for (int cas = 1 ; cas <= T ; cas ++) {
        printf("Case %d:\n",cas);
        scanf("%d",&n);
        build(1 , n , 1);
        char op[10];
        while (scanf("%s",op)) {
            if (op[0] == 'E') break;
            int a , b;
            scanf("%d%d",&a,&b);
            if (op[0] == 'Q') printf("%d\n",query(a , b , 1 , n , 1));
            else if (op[0] == 'S') update(a , -b , 1 , n , 1);
            else update(a , b , 1 , n , 1);
        }
    }
    return 0;



    return 0;
}

