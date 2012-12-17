/*
ID: xieke.b1
PROB: agrinet
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <vector>
#include <string.h>

using namespace std;

ifstream fin("agrinet.in");
ofstream fout("agrinet.out");

typedef pair<int, int> pii;
const int MAXN = 105;
const int INF = 999999999;
int N;
int g[MAXN][MAXN];
bool in_tree[MAXN];

void work(){
    int dis[MAXN];
    memset(in_tree,0,sizeof(in_tree));
    int ans = 0;
    for(int i=0; i<MAXN; i++){
        dis[i] = g[0][i];
    }
    in_tree[0] = true;
    int t_N = N;
    t_N--;
    while(t_N--){
        int t_min = INF;
        int min_node = -1;
        for(int i=0; i<N; i++){
            if(t_min>dis[i] && in_tree[i]==false){
                t_min = dis[i];
                min_node = i;
            }
        }
        in_tree[min_node] = true;
        cout<<"add node "<<min_node<<" value "<<t_min<<endl;
        ans+=t_min;
        cout<<"values for in_tree"<<endl;
        for(int i=0; i<N; i++){
            cout<<in_tree[i]<<"\t";
        }cout<<endl;
        for(int i=0; i<N; i++){
            if(in_tree[i]==false){
                cout<<"update "<<endl;
                dis[i] = min(dis[i], g[min_node][i]);
            }
        }
        cout<<"N now is "<<N<<endl;
        for(int i=0; i<N; i++){
            cout<<dis[i]<<" ";
        }cout<<endl;
    }
    fout<<ans<<endl;
}

int main(){
    fin>>N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            fin>>g[i][j];
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout<<g[i][j]<<"\t";
        }cout<<endl;
    }
    work();

    return 0;
}

