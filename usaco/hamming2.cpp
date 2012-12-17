/*
ID: xieke.b1
PROG: hamming
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <stack>
#include <map>

using namespace std;

ofstream fout("hamming.out");
ifstream fin ("hamming.in");
const int INF = 999999999;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define all(c) (c).begin(), (c).end()
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++) 
int N,B,D;
const int MAXN = 270;
int list[MAXN][MAXN];
int szs[MAXN];

int ans[MAXN], ptr = 0;
bool should_break;
void dfs(int num, int cur){
    if(cur==N){
        for(int i=0; i<cur; i++){
            cout<<ans[i]<<" ";
        }cout<<endl;
        should_break = true;
        exit(0);
    }

    for(int next = num; next<(1<<B); next++){
        bool ok = true;
        for(int j=0; j<cur; j++){
            if(  __builtin_popcount(ans[j]^next)<D){
                ok=false;break;
            }
        }
        if(ok){
            ans[cur] = next;
            dfs(next+1, cur+1);

    }
    }
}

/*
    for(int i=0; i<szs[num]; i++){
        int next = list[num][i];
        bool ok = true;
        for(int j=0; j<cur; j++){
            int tmp = next^ans[j];
            if( __builtin_popcount(tmp) < D){
                ok=false;
                break;
            }
        }
        if(ok){
            ans[cur] = num;
            dfs( next, cur+1);
        }
    }
*/

void work(){
    
    
    for(int i=0; i<(1<<B); i++){
        for(int j=i+1; j<(1<<B); j++){
            int t = i^j;
            if( __builtin_popcount(t) >= D){
                list[i][ szs[i] ] = j;
                //list[j][ szs[j] ] = i;
                szs[i]++;
                //szs[j]++;
            }
        }
    }
    should_break = false;
    ans[0] = 0;
    dfs(1, 1);
}

int main(){
    fin>>N>>B>>D;
    work();

    return 0;
}

