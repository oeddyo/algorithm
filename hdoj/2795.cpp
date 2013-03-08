#include <iostream>

using namespace std;

int h,w,n;
const int MAXN = 300000, INF = 999999999;
int tree[MAXN*4];

void pushUp(int idx){
    tree[idx] = max(tree[idx<<1], tree[idx<<1|1]);
}

int query(int L, int R, int l, int r, int idx, int value){
    if(tree[idx] < value ){
        return INF;
    }
    if(l==r){
        if(value<=tree[idx]){
            return l;
        }else{
            return INF;
        }
    }
    int m = (l+r)>>1;
    int ret_left = INF, ret_right = INF;
    if(L<=m){
        ret_left = query(L, R, l, m, idx<<1, value);
        if(ret_left!=INF)return ret_left;
    }
    if(R>m){
        ret_right = query(L, R, m+1, r, idx<<1 | 1, value);
        return ret_right;
    }
    return INF;
}

void update(int p, int l, int r, int idx, int add){
    //cout<<"update "<<p<<" "<<l<<" "<<r<<" "<<idx<<" "<<add<<endl;
    if(p==l && p==r){
        tree[idx] += add;
        //cout<<"really updating "<<idx<<" to "<<tree[idx]<<endl;
        return;
    }
    int m = (l+r)>>1;
    if(p<=m){
        update(p, l, m, idx<<1, add);
    }else if(p>m){
        update(p, m+1, r, idx<<1|1, add);
    }
    pushUp(idx);
}

void build(int l, int r, int idx){
    if(l==r){
        tree[idx] = w;
        return ;
    }
    int m = (l+r)>>1;
    build(l,m,idx<<1);
    build(m+1,r,idx<<1|1);
    pushUp(idx);
}


int main(){
    while(scanf("%d %d %d",&h,&w,&n)!=EOF){
        int height = min(n,h);
        build(1, height, 1);
        int value;
        for(int i=0; i<n; i++){
            scanf("%d",&value);
            int res = query(1, height, 1, height,1, value); 
            //cout<<"res is "<<res<<endl;
            if(res==INF){
                printf("-1\n");
            }else{
                printf("%d\n",res);
                update(res, 1, height, 1, -value);
            }
        }
    }

    return 0;
}

