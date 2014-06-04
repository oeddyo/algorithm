#include <iostream>
#include <string.h>
#include <string>
#include <stdio.h>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 51000;
int P[20][MAXN], N, steps;
struct node{
    int nr[2];
    int p;
}L[MAXN];
char S[MAXN];
/*
inline int cmp(const struct node &a, const struct node &b){
    return (a.nr[0]==b.nr[0])?(a.nr[1]<b.nr[1]):(a.nr[0]<b.nr[0]);
}
*/
inline int cmp(const struct node *a, const struct node *b){
    return (a->nr[0]==b->nr[0])?(a->nr[1]<b->nr[1]):(a->nr[0]<b->nr[0]);
}

int lcp(int x, int y){
    int ans = 0;
    if(x==y)return N-x;
    for(int s = steps; s>=0 && x<N && y<N; s--){
        if(P[s][x] == P[s][y]){
            ans += (1<<s);
            x += 1<<s;
            y += 1<<s;
        }
    }
    return ans;
}

struct node *pointers[MAXN];
void build_suffix_array(){
    for(int i=0; i<N; i++){
        P[0][i] = S[i] - 'a';
    }
    for(int s=1, cnt=1; cnt>>1 <N; s++, cnt<<=1){
        steps = s;
        for(int i=0; i<N; i++){
            L[i].nr[0] = P[s-1][i];
            L[i].nr[1] = (i+cnt<N)?P[s-1][i+cnt]:-1;
            L[i].p = i;
        }
        for(int i=0; i<N; i++){
            pointers[i] = &L[i];
        }
        //sort(L, L+N, cmp);
        sort(pointers, pointers+N, cmp);
        for(int i=0; i<N; i++){
            //P[s][L[i].p] = (i>0 && L[i-1].nr[0]==L[i].nr[0] && L[i-1].nr[1]==L[i].nr[1])? P[s][L[i-1].p]:i;
            P[s][pointers[i]->p] = (i>0 && pointers[i-1]->nr[0]==pointers[i]->nr[0] && pointers[i-1]->nr[1]==pointers[i]->nr[1])? P[s][pointers[i-1]->p]:i;
        }
    }

    //int ans = N-L[0].p; 
    int ans = N-pointers[0]->p; 
    for(int i=1; i<N; i++){
        int c = lcp(pointers[i-1]->p, pointers[i]->p); 
        ans += (N-(pointers[i]->p)) - c;  
    }
    cout<<ans<<endl;
}



int main(){
    int T;
   
    scanf("%d", &T);
    while(T--){
        scanf("%s", S);
        N = strlen(S);
        build_suffix_array();
    }

    return 0;
}

