/*
ID: xieke.b1
PROB: butter
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

ifstream fin("butter.in");
ofstream fout("butter.out");

typedef pair<int, int> pii;
const int MAXN = 501;
const int INF = 999999999;

int N,P,C;
int cows[MAXN*2];
int g[MAXN][MAXN];

bool vis[MAXN];
int sp[MAXN];
int ans = INF;

void dij(int start){
    for(int i=0; i<P; i++)sp[i] = INF;
    priority_queue< pii, vector<pii>, greater<pii>  > Q;
    Q.push( pii(0, start) );
    //memset(vis,0,sizeof(vis));
    int count = P; 
    while(!Q.empty()){
        pii cur = Q.top();
        Q.pop();
        //cout<<"now at "<<cur.second<<" dis is "<<cur.first<<endl;
        sp[cur.second] = cur.first;
        for(int i=0; i<P; i++){
            if(g[cur.second][i]!=INF && sp[i]==INF){
                //cout<<"at "<<cur.second<<" add "<<i<<endl;
                Q.push( pii(cur.first+g[cur.second][i] , i) );
            }
        }
        count--;
        if(count==0)break;
    }
    int t_ans = 0;
    for(int i=0; i<N; i++){
        t_ans += sp[cows[i]];
    }
    ans = min(ans, t_ans);
    //cout<<"P "<<start<<" ans = "<<t_ans<<endl;
}

void work(){
    for(int i=0; i<P; i++){
        dij(i);
    }
    fout<<ans<<endl;
}


int main(){
    fin>>N>>P>>C;
    for(int i=0; i<MAXN; i++)for(int j=0; j<MAXN; j++)g[i][j]=INF;
    for(int i=0; i<N; i++){
        fin>>cows[i];
        cows[i]--;
    }
    for(int i=0; i<C; i++){
        int a,b,c;
        fin>>a>>b>>c;
        a--,b--;
        g[a][b] = c;
        g[b][a] = c;
    }
    cout<<"here"<<endl;
    work();

    return 0;
}

