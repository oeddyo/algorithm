/*
ID: xieke.b1
PROB: race3
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <stack>
#include <vector>
#include <string.h>

using namespace std;
ifstream fin("race3.in");
ofstream fout("race3.out");

const int INF = 999999999;
int N;
const int MAXN = 150;
int g[MAXN][MAXN];


bool vis[MAXN];

bool dfs(int cur, int end){
    if(vis[cur])return false;
    if(cur==end){
        return true;
    }
    vis[cur] = true;
    bool ok = false;
    for(int i=0; i<MAXN; i++){
        if(g[cur][i]!=INF){
            if(dfs(i, end)){
                ok=true;
            }
        }
    }
    return ok;
}


int tmp_row[MAXN], tmp_col[MAXN];

void delete_out(int node){
    for(int k=0; k<MAXN; k++){
        tmp_row[k] = g[node][k];
        g[node][k] = INF;
    }
}
void delete_in(int node){
    for(int k=0; k<MAXN; k++){
        tmp_col[k] = g[k][node];
        g[k][node] = INF;
    }
}
void recover_out(int node){
    for(int k=0; k<MAXN; k++){
        g[node][k] = tmp_row[k];
    }
}

void recover_in(int node){
    for(int k=0; k<MAXN; k++){
        g[k][node] = tmp_col[k];
    }
}

void print_graph(){
    for(int i=0; i<=N; i++){
        for(int j=0; j<=N; j++){
            if(g[i][j]!=INF){
                cout<<"edge "<<i<<" "<<j<<" "<<g[i][j]<<endl;
            }
        }
    }
}



void work(){
    vector<int> unavoidable;
    vector<int> splitting;
    
    
    for(int i=1; i<N-1; i++){
        //delete a node
        delete_out(i);
        delete_in(i);
        memset(vis,0,sizeof(vis));
        
        if(dfs(0, N-1)==false){
            unavoidable.push_back( i );
        }else{
            recover_in(i);
            recover_out(i);
            continue;
        }
        recover_in(i);
        vector<int> first_set;
        vector<int> second_set;
        memset(vis,0,sizeof(vis));
        dfs(0,-1);
        for(int k=0; k<MAXN; k++){
            if(vis[k])first_set.push_back(k);
        }
        cout<<"cur node "<<i<<endl;
        cout<<"in first set"<<endl;
        for(int k=0; k<first_set.size(); k++){
            cout<<first_set[k]<<" ";
        }cout<<endl;

        delete_in(i);
        recover_out(i);
        memset(vis,0,sizeof(vis));
        dfs(i, -1);
        for(int k=0; k<MAXN; k++){
            if(vis[k])second_set.push_back(k);
        }
        cout<<"in second set"<<endl;
        for(int k=0; k<second_set.size(); k++){
            cout<<second_set[k]<<" ";
        }cout<<endl;
        
        recover_in(i);
        bool ok = true;
        for(int k1=0; k1<first_set.size(); k1++){
            for(int k2=0; k2<second_set.size(); k2++){
                if(g[i][first_set[k1]]!=INF){
                    ok = false;
                }
                if(first_set[k1]==i || second_set[k2]==i)continue;
                
                
                if( g[first_set[k1]][second_set[k2]]!=INF || g[second_set[k2]][first_set[k1]]!=INF ){
                //if( g[second_set[k2]][first_set[k1]]!=INF ){
                    //|| g[second_set[k2]][i]!=INF ){
                    ok = false;
                    cout<<"ok "<<first_set[k1]<<" "<<second_set[k2]<<" bad "<<g[second_set[k2]][first_set[k1]]<<endl;
                }
            }
        }
        if(ok==true){
            splitting.push_back(i);
        }
    
    }
    
    fout<<unavoidable.size();
    for(int i=0; i<unavoidable.size(); i++){
        fout<<" "<<unavoidable[i];
    }
    fout<<endl;

    fout<<splitting.size();
    for(int i=0; i<splitting.size(); i++){
        fout<<" "<<splitting[i];
    }
    fout<<endl;
}


int main(){
    for(int i=0; i<MAXN; i++){
        for(int j=0;j<MAXN; j++){
            g[i][j] = INF;
        }
    }

    int cur;
    int cur_line = 0;
    while(fin>>cur){
        if(cur==-2){
            cur_line+=1;
        }
        else if(cur==-1){
            break;
        }else{
            g[cur_line][cur] = 1;
        }
    }
    N = cur_line;
    work();
    return 0;
}

