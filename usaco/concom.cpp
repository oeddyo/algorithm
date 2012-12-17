/*
ID: xieke.b1
PROB: concom
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
ifstream fin("concom.in");
ofstream fout("concom.out");

const int INF = 999999999;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int MAXN = 102;

int own[MAXN][MAXN], N;
vi graph[MAXN];
map< pii, int > seen;


void work(){
    int cnt = 10000;
    while(cnt--){
        bool change = false;
        for(int i=1; i<MAXN; i++){
            int sum[MAXN];
            memset(sum,0,sizeof(sum));
            for(int j=0; j<graph[i].size(); j++){
                int other = graph[i][j];
                for(int k=0; k<MAXN; k++){
                    sum[k] += own[other][k];
                }
            }
            for(int j=0; j<MAXN; j++){
                if(sum[j]>50){
                    pii t(i, j);
                    if(seen.find(t)!=seen.end()){
                        continue;
                    }
                    graph[i].push_back(j);
                    change = true;
                    seen[t] = 1;
                }
            }
        }
        if(change==false)break;
    }
    for(int i=1; i<MAXN; i++){
        sort(graph[i].begin(), graph[i].end());
        for(int j=0; j<graph[i].size(); j++){
            if(i==graph[i][j])continue;
            fout<<i<<" "<<graph[i][j]<<endl;
        }

    }

}


int main(){
    fin>>N;
    
    for(int i=0; i<N; i++){
        int a,b,c;
        fin>>a>>b>>c;
        own[a][b] = c;
        if(c>50){
            pii t(a,b);
            if(seen.find(t)==seen.end()){
                seen[t] = 1;
                graph[a].push_back(b);
            }
        }
    }
    for(int i=0; i<MAXN; i++){
        graph[i].push_back(i);
    }

    
    cout<<"graph is "<<endl; 
    for(int i=0; i<MAXN; i++){
        if(graph[i].size()==0)continue;
        for(int j=0; j<graph[i].size(); j++){
            cout<<i<<" "<<graph[i][j]<<endl;
        }
    }

    work();
    
    
    return 0;
}

