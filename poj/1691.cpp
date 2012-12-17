#include <iostream>
#include <queue>
#include <algorithm>
#include <stdio.h>
using namespace std;
int N,T;

//int up_x[16],up_y[16],down_x[16],down_y[16], col[16];

struct p{
    int up_x, up_y, down_x, down_y, col;
};
p paints[16];
int n_brush = 0;
bool cmp(const p &a, const p &b){
    return a.up_x<b.up_x;
}

struct node{
    int s;
    int step;
    int color;
};
const int INF = 999999999;
void print_bin(int p, int k){
    if(p==0){
        return ;
    }
    print_bin(p-1, k>>1);
    cout<<(k&1);
}


void work(){
    sort(paints, paints+N,cmp);
    /*
    for(int i=0; i<N; i++){
        cout<<paints[i].up_x<<" "<<paints[i].up_y<<" "<<paints[i].down_x<<" "<<paints[i].down_y<<" "<<paints[i].col<<endl;
    }
    */
    node cur, next;
    cur.s = 0;
    cur.step = 0;
    cur.color = -1;
    int final_s = (1<<(N))-1;
    //cout<<"final_s is ";
    //print_bin(N, final_s);
    queue<node> Q;
    Q.push(cur);
    int ans = INF;
    while(!Q.empty()){
        cur = Q.front();
        Q.pop();
        /*
        cout<<"now state ";
        print_bin(N,cur.s);
        cout<<" step is "<<cur.step<<endl;
        */
        if(cur.s==final_s){
           ans = min(ans, cur.step); 
           break;
        }
        for(int b = 1; b<=n_brush; b++){
            int b_col = b;
            int ns = cur.s;
            for(int i=0; i<N; i++){
                //we wanna paint i
                if(((ns>>i)&1) ==1){
                    continue;
                }else{
                    //check ith up is all done
                    bool could_paint = true;
                    for(int k=0; k<i; k++){
                        if(paints[i].up_x == paints[k].down_x){
                            if( (paints[k].up_y>=paints[i].down_y || paints[i].up_y >=paints[k].down_y) ||  ((ns>>k)&1)==1 ){
                                continue;
                            }else{
                                //if(i==1)
                                //    cout<<"seeing up "<<k<<" and i'm in"<<endl;
                                could_paint = false;
                                break;
                            }
                        } 
                    }
                    if(could_paint && b_col == paints[i].col){
                        ns = ((1<<i)|ns);
                        if(b_col == cur.color){
                            next.step = cur.step;
                        }else{
                            next.step = cur.step+1;
                        }
                        next.color = b_col;
                        next.s = ns;
                        Q.push(next);
                    }
                }
            }
        }
    }
    cout<<ans<<endl;
}

int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        n_brush = 0;
        for(int i=0; i<N; i++){
            scanf("%d%d%d%d%d",&paints[i].up_x,&paints[i].up_y, &paints[i].down_x, &paints[i].down_y, &paints[i].col);
            n_brush = max(n_brush, paints[i].col);
        }
        work();
    }

    return 0;
}

