/*
ID: xieke.b1
PROB: comehome
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <stack>
#include <vector>
#include <string.h>
#include <cmath>
#include <iomanip>

using namespace std;
ifstream fin("comehome.in");
ofstream fout("comehome.out");

const double INF = 999999999;
typedef pair<int, int> pii;

const int MAXN = 200;
vector< pii > points;

int N;
//vector <char> graph;
int g[MAXN][MAXN];


void floyd(){
    for(int k=0; k<MAXN; k++){
        for(int i=0; i<MAXN; i++){
            for(int j=0; j<MAXN; j++){
                g[i][j] = min( g[i][j], g[i][k]+g[k][j]);
            }
        }
    }
}

void work(){
    floyd();
    int ans = INF;
    char cur ;
    for(char w = 'A'; w<='Y'; w++){
        if(ans>g['Z'][w]){
            ans = g['Z'][w];
            cur = w;
        }
    }
    fout<<cur<<" "<<ans<<endl;
}


int main(){
    fin>>N;
    for(int i=0; i<MAXN; i++)for(int j=0; j<MAXN; j++)g[i][j] = INF;

    for(int i=0; i<N; i++){
        char a,b;
        int c;
        fin>>a>>b>>c;
        //cout<<(int)a<<" "<<(int)b<<endl;
        //g[a][b] = min(g[a][b], c);
        int t = g[a][b];
        g[a][b] = min(t, c);
        g[b][a] = g[a][b];
        //g[(int)b][(int)a] = min(g[(int)b][(int)a],c);
        //g[(int)a][(int)b] = min(g[(int)a][(int)b],c);
    }
    for(int i=0; i<MAXN; i++)g[i][i] = 0;

    for(int i=0; i<MAXN; i++){
        for(int j=0; j<MAXN; j++){
            if(g[i][j]<INF){
                //cout<<"from "<<i<<" to "<<j<<" "<<g[i][j]<<endl;
            }
        }
    }


    work();
    return 0;
}
