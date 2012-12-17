/*
ID: xieke.b1
PROB: fence6
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <stack>
#include <vector>
#include <string.h>
#include <queue>

using namespace std;

ifstream fin("fence6.in");
ofstream fout("fence6.out");

int INF = 999999999;
const int MAXN = 1500;

int g[MAXN][MAXN];
int d[MAXN];
bool done[MAXN];
int n_nodes,N, ans = INF;
void dij(int s){
    for(int i=0; i<n_nodes; i++)d[i] = INF;
    memset(done,0,sizeof(done));
    d[s] = 0;

    while(1){
        int idx = -1, tmp = INF;
        for(int i=0; i<n_nodes; i++){
            if(d[i]<tmp&&done[i]==0 ){
                tmp = d[i];
                idx = i;
            }
        }
        done[idx] = 1;
        for(int j=0; j<n_nodes; j++){
            cout<<d[j]<<" ";
        }cout<<endl;
        bool finish = true;
        cout<<"ok index is "<<idx<<endl;
        for(int j=0; j<n_nodes; j++){
            cout<<"checking "<<g[idx][j]<<" + "<<d[idx]<<endl;
            if(g[idx][j] + d[idx] < d[j] ){
                d[j] = g[idx][j]+d[idx];
                finish=false;
            }
        }
        if(finish)break;
    }
    return ;
}

void work(){
    ans = INF;
    for(int i=0; i<N; i++){
        int t1 = g[i][i+N], t2 = g[i+N][i];
        g[i][i+N] = INF;
        g[i+N][i] = INF;
        dij(i);
        break;
        for(int j=0; j<n_nodes; j++){
            cout<<d[j]<<" ";
        }cout<<endl;
        cout<<"tmp ans is "<<d[i+N]+t1<<endl;
        g[i][i+N] = t1;
        g[i+N][i] = t2;
        ans = min(ans, d[i+N]);
    }
    cout<<ans<<endl;

}

int main(){
    fin>>N;
    n_nodes = N*2;
    cout<<"n nodes is "<<n_nodes<<endl;
    for(int i=0; i<n_nodes; i++){
        cout<<"see "<<i<<endl;
        for(int j=0; j<n_nodes; j++){
            g[i][j] = INF;
        }
        g[i][i] = 0;
    }
    cout<<"here"<<endl;
    for(int i=0; i<N; i++){
        cout<<i<<endl;
        int s, Ls, N1, N2;
        fin>>s>>Ls>>N1>>N2;
        g[s-1][s-1+N] = Ls;
        g[s-1+N][s-1] = Ls;

        int t;
        for(int j=0; j<N1; j++){
            fin>>t;
            if(s>t)continue;
            g[s-1][t-1] = 0;
            g[t-1][s-1] = 0;
        }

        for(int j=0; j<N2; j++){
            fin>>t;
            if(s>t)continue;
            g[s-1][t+N-1] = 0;
            g[t+N-1][s-1] = 0;
        }
    }
    for(int i=0; i<n_nodes; i++){
        for(int j=0; j<n_nodes; j++){
            if(g[i][j]==INF){
                cout<<" *";
            }else{
                cout<<" "<<g[i][j];
            }
        }
        cout<<endl;
    }

    work();
    return 0;
}

