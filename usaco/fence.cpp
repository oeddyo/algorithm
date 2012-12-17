/*
ID: xieke.b1
PROB: fence
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <string.h>
#include <cmath>

using namespace std;

ifstream fin("fence.in");
ofstream fout("fence.out");

typedef pair<int, int> pii;
const int MAXN = 501;
const int INF = 999999999;
int F;

vector< pii > g[MAXN];
vector<int> cir;

void dfs(int cur_pos){
    cout<<"at "<<cur_pos<<endl;
    int sz = g[cur_pos].size();
    for(int i=0; i< sz; i++){
        if(g[cur_pos][i].second == 0){
            g[cur_pos][i].second = 1;
            int v = g[cur_pos][i].first;
            for(int k=0; k<g[v].size(); k++){
                if( g[v][k].first== cur_pos && g[v][k].second==0){
                    cout<<"mark"<<endl;
                    g[v][k].second=1;break;
                }
            }
            dfs(g[cur_pos][i].first);
        }
    }
    cout<<"push "<<cur_pos<<endl;
    cir.push_back(cur_pos);
}


void work(){
    //odd vetice?
    int start_pos = -1;
    for(int i=1; i<MAXN; i++){
        if((g[i].size() & 1) ==1){
            start_pos = i;
            break;
        }
    }
    
    if(start_pos==-1){
        for(int i=1; i<=500; i++){
            if(g[i].size()>0){
                start_pos = i;
                break;
            }
        }
    }
    dfs(start_pos);
    reverse(cir.begin(), cir.end());
    for(int i=0; i<cir.size(); i++){
        fout<<cir[i]<<endl;
    }
}


int main(){
    fin>>F;
    for(int i=0; i<F; i++){
        int a,b;
        fin>>a>>b;
        g[a].push_back(pii(b,0));
        g[b].push_back(pii(a,0));
    }
    for(int i=0; i<MAXN; i++){
        sort(g[i].begin(), g[i].end());
    }
    work();
    return 0;
}

