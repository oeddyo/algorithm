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
/*
void dfs(int num, int cur){
    if(should_break)return ;
    cout<<cur<<endl;
    if(cur==N){
        for(int i=0; i<cur; i++){
            cout<<ans[i]<<" ";
        }cout<<endl;
        should_break = true;
        return ;
    }

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
}
*/
void get_ans(int start){
    vector<int> S;
    S.push_back(start);
    for(int i=start+1; i<(1<<B); i++){
        bool ok = true;
        for(int j=0; j<S.size(); j++){
            if( __builtin_popcount( S[j]^i) < D ){
                ok=false;
            }
        }
        if(ok==false){
            continue;
        }else{
            S.push_back(i);
        }

        if(S.size()==N){
            should_break = true;
            fout<<S[0];
            for(int i=1; i<S.size(); i++){
                if(i%10!=0){
                    fout<<" "<<S[i];
                }else{
                    fout<<endl<<S[i];
                }
            }
            fout<<endl;
            /*
            for(int i=0; i<S.size()-1; i++){
                cout<<S[i]<<" ";

            }cout<<S[S.size()-1]<<endl;
            */
            return ;
        }
    }
}

void work(){
    for(int s = 0; s<(1<<B); s++){
        get_ans(s);
        if(should_break){
            return ;
        }
    }
/*
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
    for(int i=0; i<(1<<B); i++){
        dfs(i, 0);
    }
*/
}

int main(){
    fin>>N>>B>>D;
    work();

    return 0;
}

