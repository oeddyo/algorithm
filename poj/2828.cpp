#include <iostream>

using namespace std;


const int MAXN = 210000;
int tree[MAXN*8];



void build(int l, int r, int idx){
    if(l==r){
        tree[idx] = 0;
        return ;
    }
    int m = (l+r)>>1;
    build(l, m, idx*2);
    build(m+1, r, idx*2+1);
    pushUp(idx);
}



int main(){
    while(scanf("%d",&N)!=EOF){
        for(int i=0; i<N; i++){
            scanf("%d %d",&a,&b);
        }
    }
    return 0;
}
