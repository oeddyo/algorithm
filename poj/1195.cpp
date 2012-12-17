#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
const int MAXN = 1050;
int S,tree[MAXN][MAXN];

int max_val;
void update(int x, int y, int val){
    int idx_x=x, idx_y = y;
    while(idx_x<=max_val){
        idx_y = y;
        while(idx_y<=max_val){
            tree[idx_x][idx_y] += val;
            idx_y += (~(idx_y-1))&idx_y;
        }
        idx_x += (~(idx_x-1))&idx_x;
    }
}

int get_sum(int x, int y){
    int idx_x = x, idx_y = y,sum=0;
    while(idx_x>0){
        idx_y = y;
        while(idx_y>0){
            sum+= tree[idx_x][idx_y];
            idx_y -= (~(idx_y-1))&idx_y;
        }
        idx_x-=(~(idx_x-1))&idx_x;
    }
    return sum;
}



int main(){
    int order,X,Y,A,L,B,R,T;


    while(1){    
        scanf("%d",&order);
        if(order==3){
            break;
        }else if(order==1){
            scanf("%d%d%d",&X,&Y,&A);
            X++,Y++;
            update(X,Y,A);
        }else if(order==2){
            scanf("%d%d%d%d",&L,&B,&R,&T);
            L++,B++,R++,T++;
            int ans = 0;
            ans = get_sum(R,T);
            int whole = get_sum(R,T);
            int left = get_sum(L-1, T);
            int down = get_sum(R, B-1);
            ans -= left;
            ans -= down;
            ans += get_sum(L-1,B-1);
            cout<<ans<<endl;
            //cout<<"final "<<ans<<endl;
        }else if(order==0){
            scanf("%d",&S);
            max_val = S;
            memset(tree,0,sizeof(tree));
        }
    }
    return 0;
}

