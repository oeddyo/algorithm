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
int g[MAXN][MAXN], dis[MAXN], visited[MAXN], n_nodes, N;

void dij(int s){
    memset(visited,0,sizeof(visited));
    for(int i=0; i<MAXN; i++)dis[i] = INF;

    dis[s] = 0;

    for(int node=1; node<=n_nodes; node++){
        int tmp_min = INF, idx;
        for(int i=1; i<=n_nodes; i++){
            if(visited[i]==0 && tmp_min>dis[i]){
                tmp_min = dis[i];
                idx = i;
            }
        }

        
        for(int i=1; i<=n_nodes; i++){
            if(dis[idx]+g[idx][i] < dis[i] ){
                dis[i] = dis[idx]+g[idx][i];
            }
        }
        visited[idx] = 1;
    }
}


void work(){
    int ans = INF;
    for(int i=1; i<=N; i++){
        int t1 = g[i][i+N], t2 = g[i+N][i];
        g[i][i+N] = INF;
        g[i+N][i] = INF;
        dij(i);
        int tmp_ans = dis[i+N] + t1;
        ans = min(ans, tmp_ans);
        g[i][i+N] = t1;
        g[i+N][i] = t2;
    }
    cout<<"final ans = "<<ans<<endl;
    fout<<ans<<endl;
}

int lens[MAXN];
vector<int> A[MAXN];
vector<int> B[MAXN];

int main(){
    fin>>N;
    int s, Ls, N1, N2, t;
    for(int i=0; i<MAXN; i++){
        for(int j=0; j<MAXN; j++){
            g[i][j] = INF;
        }
    }

    for(int k=1; k<=N; k++){
        fin>>s>>Ls>>N1>>N2;
        lens[s] = Ls;
        for(int i=1; i<=N1; i++){
            fin>>t;
            A[s].push_back(t);
            /*if(s<t){
                g[s][t] = 0;
                g[t][s] = 0;
            }*/
        }
        for(int i=1; i<=N2; i++){
            fin>>t;
            B[s].push_back(t);
            /*
            if(s<t){
                g[s+N][t] = 0;
                g[t][s+N] = 0;
            }
            */
        }
        g[s][s] = 0;
        g[s+N][s+N] = 0;
        g[s][s+N] = Ls;
        g[s+N][s] = Ls;
    }

    for(int i=1; i<=N; i++){
        for(int j=0; j<A[i].size(); j++){
            int tmp = A[i][j];
            for(int k=0; k<A[tmp].size(); k++){
                if(i==A[tmp][k]){
                    g[i][tmp] = 0;
                    g[tmp][i] = 0;
                }
            }
            for(int k=0; k<B[tmp].size(); k++){
                if(i==B[tmp][k]){
                    g[i][tmp+N] = 0;
                    g[tmp+N][i] = 0;
                }
            }
        }

        for(int j=0; j<B[i].size(); j++){
            int tmp = B[i][j];
            for(int k=0; k<A[tmp].size(); k++){
                if(i==A[tmp][k]){
                    g[i+N][tmp] = 0;
                    g[tmp][i+N] = 0;
                }
            }
            for(int k=0; k<B[tmp].size(); k++){
                if(i==B[tmp][k]){
                    g[i+N][tmp+N] = 0;
                    g[tmp+N][i+N] = 0;
                }
            }
        }
    }


    for(int i=1; i<=N*2; i++){
        for(int j=1; j<=N*2; j++){
            if(g[i][j]!=INF){
                cout<<g[i][j]<<"  ";
            }else{
                cout<<"*  ";
            }
        }cout<<endl;
    }
    n_nodes = N*2;
    work();
    return 0;
}

