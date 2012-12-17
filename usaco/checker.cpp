/*
ID: xieke.b1
PROG: checker
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
ofstream fout("checker.out");
ifstream fin ("checker.in");
const int INF = 999999999;
int N;

const int MAXN = 15;

int ys[MAXN];
bool y_ocupy[MAXN];
bool og[MAXN*3];
bool og2[MAXN*3];


int ans_cnt = 0;
void dfs(int cur){
    if(cur==N){
        ans_cnt++;
        if(ans_cnt<=3){
            for(int i=0; i<N-1; i++){
                fout<<ys[i]+1<<" ";
            }
            fout<<ys[N-1]+1<<endl;
        }
        return ;
    }
    for(int i=0; i<N; i++){
        if(!y_ocupy[i]){
            bool ok = true;
            if(!og[i-cur+MAXN] && !og2[i+cur]){
                og[i-cur+MAXN]=true;
                og2[i+cur] = true;
                y_ocupy[i] = true;
                ys[cur] = i;
                dfs(cur+1);
                y_ocupy[i] = false;
                og[i-cur+MAXN] = false;
                og2[i+cur] = false;
            }
            /*
            for(int j=0; j<cur; j++){
                int pre_x = j;
                int pre_y = ys[j];
                    if( abs(cur-pre_x)==abs(i-pre_y) ){
                        ok = false;
                        break;
                    }
            }
            if(ok){
                y_ocupy[i] = true;
                ys[cur]  = i;
                dfs(cur+1);
                y_ocupy[i] = false;
            }
            */
        }
    }

}

void work(){
    memset(y_ocupy, 0, sizeof(y_ocupy));
    dfs(0);
    fout<<ans_cnt<<endl;
}
int main(){
    fin>>N;
    work();
    return 0;
}

