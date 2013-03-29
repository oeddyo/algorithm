#include <iostream>


using namespace std;


const int MAXN;

typedef struct priority_queue{
    int pq[MAXN];
    int sz;
}pq;


void buble_up(pq *Q){
    int cur = Q->sz;
    while(cur>1){
        if(Q->pq[sz]>Q->pq[sz/2]){
            swap(Q->pq[cur], Q->pq[cur/2]);
            cur = cur/2;
        }else{
            break;
        }
    }
}

void buble_down(pq *Q){
    int cur = 1;
    while(cur<Q->sz){
        int tmp_min = INF;
        if(cur*2<=Q->sz){
            if(tmp_min>Q->pq[cur*2]){
                next = cur*2;
                tmp_min = min(tmp_min, Q->pq[cur*2]);
            }
        }
        if(cur*2+1<=Q->sz){
            if(tmp_min>Q->pq[cur*2+1]){
                next = cur*2+1;
                tmp_min = min(tmp_min, Q->pq[cur*2+1]);
            }
        }
        swap(Q->pq[cur], Q->pq[next]);
        cur = next;
    }
}

void insert(pq *Q, int num){
    Q.pq[sz+1] = num;
    sz++;
    buble_up(pq *Q);
}

void pop(pq *Q, int num){
    int res = Q->pq[1];
    Q->pq[1] = Q->pq[sz];
    sz-=1;
    buble_down(Q);

}



int main(){




    return 0;
}

