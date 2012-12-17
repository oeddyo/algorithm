#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

int test, X, N, T;
const int MAXN = 1002;
int tree[MAXN][MAXN];
int max_val;

void do_update(int x, int y, int val){
    while(x<=max_val){
        int idx_y = y;
        while(idx_y<=max_val){
            tree[x][idx_y] += val;
            idx_y += (~(idx_y-1))&idx_y;
        }
        x+=(~(x-1))&x;
    }
}

void update(int x1, int y1, int x2, int y2){
    do_update(x1,y1,1);
    do_update(x2+1,y2+1,-1);
    do_update(x2+1,y1,-1);
    do_update(x1,y2+1,1);
}
int do_getsum(int x,int y){
    int sum = 0;
    while(x>0){
        int t_y = y;
        while(t_y>0){
            sum+=tree[x][t_y];
            t_y -= (~(t_y-1))&t_y;
        }
        x -= (~(x-1))&x;
    }
    return sum;
}


int get_sum(int x, int y){
    int sum = 0;
    int t;
    return do_getsum(x,y);
    /*sum+= t=do_getsum(x,y);
    sum-= t=do_getsum(x-1,y);
    sum-= t=do_getsum(x,y-1);
    sum+= t=do_getsum(x-1,y-1);
    return sum;
    */
}


int main(){
    scanf("%d",&test);
    while(test--){
        scanf("%d%d",&N,&T);
        memset(tree,0,sizeof(tree));
        max_val = N+1;
        char order;
        for(int i=0; i<T; i++){
            getchar();
            scanf("%c",&order);
            if(order=='C'){
                int x1,y1,x2,y2;
                scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
                //x1++,x2++,y1++,y2++;
                update(x1,y1,x2,y2);
            }else{
                int x,y;
                scanf("%d %d",&x,&y);
                //x++,y++;
                cout<<get_sum(x,y)%2<<endl;
            }
        }
        cout<<endl;


    }

    return 0;
}

