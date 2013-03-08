#include <iostream>
#include <list>

using namespace std;

const int MAXN = 6000;
const int INF = 999999999;
int N, tree[MAXN*8];

//,data[MAXN];

list<int> data;


void pushUp(int idx){
    tree[idx] = tree[idx*2]+tree[idx*2+1];
}

void clear(){
    memset(tree,0,sizeof(tree));
}

void build(int l, int r, int idx){
    if(l==r){
        tree[idx] = 0;
        return;
    }
    int m = (l+r)>>1;
    build(l,m,idx*2);
    build(m+1,r,idx*2+1);
    pushUp(idx);
}

int query(int L,int R, int l, int r, int idx){
    if(L<=l && R>=r ){
        return tree[idx];
    }
    int m = (l+r)>>1;
    int ret1=0, ret2=0;
    if(L<=m){
        ret1 = query(L, R, l, m, idx*2);
    }
    if(R>=m+1){
        ret2 = query(L, R, m+1, r, idx*2+1);
    }
    return ret1+ret2;
}

void update(int L, int R, int l, int r, int idx){
    if(L<=l && R>=r){
        tree[idx] += 1;
        return;
    }
    int m = (l+r)>>1;
    if(L<=m){
        update(L, R, l, m, idx*2);
    }
    if(R>m){
        update(L, R, m+1, r, idx*2+1);
    }
    pushUp(idx);
}


void work(){
    
    int cnt_N = N;
    int ans = INF;
    build(1,N, 1);
    int sum = 0;
    list<int>::iterator it;
    for(it = data.begin(); it!=data.end(); it++){
        int t = query(*it+2, N, 1, N, 1);
        sum += t;
        update(*it+1, *it+1, 1, N, 1);
    }
    ans = sum;
    cnt_N-=1;
    while(cnt_N--){
        int ttt = 3;
        int front = data.front();
        front+=1;
        data.pop_front();
        data.push_back(front);
        int smaller = front-1;
        int larger = N-front;
        sum -= smaller;
        sum += larger;
        ans = min(sum, ans);
    }
    cout<<ans<<endl;
        
}

int main(){
    while(scanf("%d",&N)!=EOF){
        data.clear();
        int tmp;
        for(int i=0; i<N; i++){
            scanf("%d",&tmp);
            data.push_back(tmp);
        }
        work();
    }
    return 0;
}


