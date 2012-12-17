#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <string.h>

using namespace std;
int N;
int sum;

const int MAXN = 150000;
int values[MAXN];
int f[MAXN];
int d[MAXN];
const int INF = 999999999;


int find(int n){
    if(f[n]==-1){
        return n;
    }else{
        f[n] = find(f[n]);
    }
    return f[n];
}

int Union(int from, int to){
    if(from==to){
        return 0;
    }
    f[from] = to;
}

int main(){
    //memset(values, 0, sizeof(values));
    memset(f,-1,sizeof(f));
    memset(d,0,sizeof(d));

    scanf("%d",&N);
    int k, v,x;
    for(int i=1; i<=N; i++){
        scanf("%d",&k);
        if(k==0)continue;

        int d_max = 0;
        int t_sum = 0;
        for(int j=0; j<k; j++){
            scanf("%d %d",&v,&x);
            int r = find(v);
            d[i] += d[v]+x;
            cout<<"at "<<i<<"; "<<v<<"'s root is "<<r<<" and adding hight="<<d[v]<<", x="<<x<<endl;
            //values[i] += d[r]-d[v]+x;
            Union(r, i);
        }
        sum+=d[i]+x;
        cout<<"d["<<i<<"]="<<d[i]+x<<endl;
    }
    cout<<sum<<endl;
    for(int i=1; i<=N; i++){
        //sum+=values[i];
    }

    cout<<sum<<endl;
    return 0;
}

