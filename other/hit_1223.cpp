#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

string S;
const int MAXN = 210000;
int N, P[20][MAXN];

struct node{
    int nr[2];
    int p;
}L[MAXN];
int cmp(const struct node &a, const struct node &b){
    if(a.nr[0] == b.nr[0]){
        return a.nr[1]<b.nr[1];
    }else{
        return a.nr[0]<b.nr[0];
    }
}

struct node2{
    int p;
    int v[20];
    int id;
}potential[MAXN];



int vector_size = -1;
int cmp2(const struct node2 &a, const struct node2 &b){
    for(int i=0; i<vector_size; i++){
        if(a.v[i]==b.v[i]){
            continue;
        }
        return a.v[i]<b.v[i];
    }
    return a.p < b.p;
}




int build_suffix(){
    for(int i=0; i<N; i++){
        P[0][i] = S[i] -'a';
    }
    int step;
    for(step = 1; (1<<(step-1))<N; step++){
        for(int i=0; i<N; i++){
            L[i].nr[0] = P[step-1][i];
            if(i+(1<<(step-1))>=N){
                L[i].nr[1] = -1;
            }else{
                L[i].nr[1] = P[step-1][i+(1<<(step-1))];
            }
            L[i].p = i;
        }
        sort(L, L+N, cmp);

        P[step][L[0].p] = 0;
        int cnt = 0;
        for(int i=1; i<N; i++){
            if(L[i-1].nr[0] == L[i].nr[0] && L[i-1].nr[1] == L[i].nr[1]){
                P[step][L[i].p] = cnt;
            }else{
                cnt ++ ;
                P[step][L[i].p] = cnt;
            }
        }
    }
    /* 
       cout<<"step = "<<step-1<<endl;
       for(int i=0; i<N; i++){
       cout<<P[step-1][i]<<" ";
       }cout<<endl;
       */

    int half = N/2;
    int pos = -1;
    for(int i=0; i<half; i++){
        int tmp = half;
        int idx = i;
        potential[i].p = i;
        //potential[i].v.clear();
        potential[i].id = 0;
        for(int s=step-1; s>=0; s--){
            if((1<<s)<=tmp){
                //potential[i].v.push_back(P[s][idx]);
                potential[i].v[ potential[i].id++ ] = P[s][idx]; 
                idx += (1<<s);
                tmp -= (1<<s);
            }
        }
    }
    vector_size = potential[0].id; 
    sort(potential, potential+half, cmp2);
    /*
    for(int i=0; i<half; i++){
        cout<<"row "<<i; 
        for(int k=0; k<potential[i].id; k++){
            cout<<potential[i].v[k]<<" ";
        }cout<<endl;
    }
    */
    return potential[0].p;
}

int main(){
    int T;

    while(cin>>T){
        while(T--){
            int t;

            cin>>t>>S;
            S += S;
            N = S.size();
            int ans = build_suffix();
            cout<<ans<<endl; 
        }
    }


    return 0;
}

