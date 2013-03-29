#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;


int T, N, Q;
const int MAXN = 120000;
const int INF = 99999999;
int lcis[MAXN*8];
int add[MAXN*8];
int test_case = 1;
int left_value[MAXN*8];
int right_value[MAXN*8];
int from_left[MAXN*8];
int from_right[MAXN*8];

void init(){
    memset(lcis,0,sizeof(lcis));
    memset(add,0,sizeof(add));
    memset(left_value, 0, sizeof(left_value));
    memset(right_value, 0, sizeof(right_value));
    memset(from_left, 0, sizeof(from_left));
    memset(from_right, 0, sizeof(from_right));
}


void pushUp(int idx, int l_len, int r_len){
    int left_right = right_value[idx*2];
    int right_left = left_value[idx*2+1];
    //cout<<"left node right value and right node left value = "<<left_right<<" "<<right_left<<endl;
    int t_max = max(lcis[idx*2], lcis[idx*2+1]);

    if(left_right<right_left){
        int tmp = from_right[idx*2]+from_left[idx*2+1];
        if(tmp>t_max){
            t_max = tmp;
        }
    }
    //cout<<"left lcis= "<<lcis[idx*2]<<" right lcis = "<<lcis[idx*2+1]<<endl;
    //cout<<"tmp max lcis = "<<t_max<<endl;
    lcis[idx] = t_max; 
    
    left_value[idx] = left_value[idx*2];
    right_value[idx] = right_value[idx*2+1];
    if(left_right<right_left){
        if(from_right[idx*2]==l_len){
            from_left[idx] = l_len + from_left[idx*2+1];
        }
        if(from_left[idx*2+1]==r_len){
            from_right[idx] = r_len + from_right[idx*2];
        }
        //cout<<"hmm... from_left["<<idx<<"] = "<<from_left[idx]<<" from_right["<<idx<<"] = "<<from_right[idx]<<endl;
    }else{
        from_left[idx] = from_left[idx*2];
        from_right[idx ] = from_right[idx*2+1];
    }

}

void build(int l, int r, int idx){
    if(l==r){
        lcis[idx] = 1;
        int t;
        scanf("%d",&t);
        left_value[idx] = t;
        right_value[idx] = t;
        add[idx]  = 0;
        from_left[idx] = 1;
        from_right[idx] = 1;
        return ;
    }
    int m = (l+r)>>1;
    build(l, m, idx*2);
    build(m+1, r, idx*2+1);
    pushUp(idx, m-l+1, r-(m+1)+1);
}


void pushDown(int idx){
    if(add[idx]){
        //cout<<"doing push down at "<<idx<<endl;
        add[idx*2] += add[idx];
        add[idx*2+1] += add[idx];
        left_value[idx*2] += add[idx];
        right_value[idx*2] += add[idx];
        left_value[idx*2+1] += add[idx];
        right_value[idx*2+1] += add[idx];
        add[idx] = 0;
    }
}


void insert(int L, int R, int l, int r, int idx, int value){
    if(L<=l && R>=r){
        //cout<<"full cover "<<l<<" "<<r<<" add "<<value<<endl;
        add[idx]+=value;
        left_value[idx] += value;
        right_value[idx] += value;
        return ;
    }
    pushDown(idx);
    int m = (l+r)>>1;
    //cout<<"L = "<<L<<" m = "<<m<<" R = "<<R<<endl;
    if(L<=m){
        insert(L,R,l,m,idx*2,value);
    }
    if(R>m){
        insert(L,R,m+1,r,idx*2+1,value);
    }
    pushUp(idx, m-l+1, r-(m+1)+1); 
}


int query(int L, int R, int l, int r, int idx){
    if(L<=l && R>=r){
        return lcis[idx];
    }
    pushDown(idx);
    
    int m = (l+r)>>1, lv = 0, rv = 0;
    if(L<=m){
        lv = query(L, R, l, m, idx*2);
    }
    if(R>m){
        rv = query(L,R,m+1,r,idx*2+1);
    }
    
    int tmp = max(lv, rv); 
    if(L<=m && R>m){
        int left_right = right_value[idx*2];
        int right_left = left_value[idx*2+1];
        if(left_right<right_left){
            int tt = min(from_right[idx*2], m-L+1) + min(from_left[idx*2+1], R-(m+1)+1);
            tmp = max(tt, tmp); 
        }
    }
    return tmp;
    //return lcis[idx];
}



int main(){
    scanf("%d",&T);
    for(test_case=1; test_case<=T; test_case++){
        init();
        scanf("%d%d",&N,&Q);
        build(1, N, 1);
        char op[3];
        printf("Case #%d:\n", test_case);
        
        for(int i=0; i<Q; i++){
            scanf("%s",op);
            int a,b,c;
            if(op[0]=='a'){
                scanf("%d%d%d",&a,&b,&c);
                insert(a,b,1,N,1,c); 
            }else{
                scanf("%d%d",&a,&b);
                int tt  = query(a,b,1,N,1);
                printf("%d\n",tt);
            }
        }
    }
    return 0;
}

