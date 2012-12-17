/*
ID: xieke.b1
PROB: butter
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <string.h>
#include <cmath>

using namespace std;

ifstream fin("butter.in");
//ifstream fin("input9.txt");
ofstream fout("butter.out");

typedef pair<int, int> pii;
const int MAXN = 801;
const int INF = 999999999;

int N,P,C;
int cows[MAXN*2];

int cnt[MAXN];

int g[MAXN][MAXN];
int v[MAXN][MAXN];


//vector< pii > g[MAXN];

int sp[MAXN];
int ans = INF;

//priority_queue< pii, vector<pii>, greater<pii>  > Q;

void dij(int start){
    for(int i=0; i<P; i++)sp[i] = INF;
    
   // Q = priority_queue< pii, vector<pii>, greater<pii > > ();
    set< pii > Q;
    //Q.push( pii(0, start) );
    Q.insert( pii(0,start) );
    //sp[start] = 0; 
    int count = P;
    int cur_node, cur_value, next, value;

    pii cur;
    while(!Q.empty()){
        cur = *Q.begin();
        Q.erase(Q.begin());

        if(sp[cur.second]==INF){
            sp[cur.second] = cur.first;
        }

        cur_node = cur.second;
        cur_value = cur.first;

        if( cur_value <= sp[cur_node] ){
            for(int i=0; i< cnt[cur_node] ; i++){
                next = g[cur_node][i];
                value = v[cur_node][i];
                int next_value = value+cur_value;
                if( next_value < sp[next] ) {
                    //sp[next] = next_value;
                    cur.first = next_value, cur.second = next;
                    Q.insert(cur);
                }
            }
        }
    }
    int t_ans = 0;
    for(int i=0; i<N; i++){
        if(sp[cows[i]]!=INF)    
        t_ans += sp[cows[i]];
    }
    ans = min(ans, t_ans);
}

void work(){
    cout<<"in work"<<endl;
    for(int i=0; i<P; i++){
        dij(i);
    }
    fout<<ans<<endl;
}


int main(){
    fin>>N>>P>>C;
    for(int i=0; i<N; i++){
        fin>>cows[i];
        cows[i]--;
    }
    memset(cnt,0,sizeof(cnt));
    for(int i=0; i<C; i++){
        int a,b,c;
        fin>>a>>b>>c;
        a--,b--;
        
        //g[a].push_back( pii(c, b) );
        //g[b].push_back( pii(c, a) );
        
        g[a][cnt[a]] = b;
        g[b][cnt[b]] = a;
        v[a][cnt[a]] = c;
        v[b][cnt[b]] = c;
        cnt[a]++;
        cnt[b]++;
    }
//    for(int i=0; i<P; i++)cnt[i] = g[i].size();
    /*
    cout<<"graph is "<<endl;
    for(int i=0; i<P; i++){
        cout<<i<<"-> ";
        for(int j=0; j<g[i].size(); j++){
            cout<<g[i][j].second<<"\t";
        }
        cout<<endl;
    }
    cout<<"here"<<endl;
    */
    cout<<"begin"<<endl;
    work();

    return 0;
}

