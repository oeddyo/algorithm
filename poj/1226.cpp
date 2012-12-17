#include <iostream>
#include <map>
#include <stdio.h>


using namespace std;
int T;
const int MAXN = 101;
char d[MAXN][MAXN], r_d[MAXN][MAXN];
const int M = 1000003;
int N;
int row = -1;

typedef struct h_node{
    int a,b,c,pre;
    int num;
    struct h_node *next;
}node;
node *h_table[M];

int get_hash(char d[][MAXN], int a, int b, int c){
    int h = 0;
    if(b<=c){
        for(int i=b; i<=c; i++){
            h = (h<<4) + d[a][i];
            unsigned long g = h&0Xf0000000L;
            if (g) h^= g>>24;
            h&=~g;
        }
    }else{
        for(int i=b; i>=c; i--){
            h = (h<<4) + d[a][i];
            unsigned long g = h&0Xf0000000L;
            if (g) h^= g>>24;
            h&=~g;
        }
    }
    return h % M;
}

bool match(char d[][MAXN], int a1, int b1, int c1, int a2, int b2, int c2){
    if(b1-a1!=c2-b2){
        return false;
    }
    for(int i=b1,p=b2; i<=c1; i++,p++){
        if(d[a1][i]!=d[a2][i]){
            return false;
        }
    }
    return true;
}

int insert(char d[][MAXN], int a,int b,int c, int h){
    int re = 0;
    if(h_table[h] == NULL){
        node *n = new node();
        n->a = a,n->b=b, n->c=c;
        n->num = 1;
        n->pre = row;
        n->next = NULL;
        h_table[h] = n;
        re = 1;
    }else{
        bool exist = false;
        node* t = h_table[h];
        while(t!=NULL){
            if(match(d,a,b,c,t->a, t->b, t->c) && t->pre!=row){
                t->num++;
                exist = true;
                re = t->num;
                t->pre = row;
                break;
            }
            t = t->next;
        }
        if(exist==false){
            node *n = new node();
            n->a = a,n->b=b, n->c=c;
            n->num = 1;
            n->pre = row;
            n->next = h_table[h];
            h_table[h] = n;
            re = 1;
        }
    }
    return re;
}


int look_up(char d[][MAXN],int a,int b,int c){
    int h1 = get_hash(d,a,b,c);
    int r1 = insert(d,a,b,c,h1);
    return r1;    
}

int ans = 0;
void work(){
    for(int i=0; i<M; i++)h_table[i] = NULL;
    ans = 0;
    for(int i=0; i<N; i++){
        row = i;
        int sz = strlen(d[i]);
        for(int j=0; j<sz; j++){
            for(int k=j; k<sz; k++){
                int num = look_up(d,i,j,k);
                if(i==N-1 && num==N){
                    if(k-j+1>ans){
                        ans = k-j+1;
                    }
                }
            }
        }
        for(int j=0; j<sz; j++){
            for(int k=j; k<sz; k++){
                int num = look_up(r_d,i,j,k);
                if(i==N-1 && num==N){
                    if(k-j+1>ans){
                        ans = k-j+1;
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
        for(int i=0; i<N; i++){
            scanf("%s",d[i]);
            int sz = strlen(d[i]);
            int p1 = 0, p2 = sz-1;
            while(p1<sz){
                r_d[i][p1] = d[i][p2];
                p2--, p1++;
            }
        }
        for(int i=0; i<N; i++){
            cout<<r_d[i]<<endl;
        }
        work();
    }

    return 0;
}

