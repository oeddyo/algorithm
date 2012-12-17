/*
ID: xieke.b1
PROB: humble
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

ifstream fin("humble.in");
ofstream fout("humble.out");

typedef pair<int, int> pii;
const int MAXN = 105;
const int INF = 2100000000;
int N,K;


int prime[MAXN];
int cnt = 0;
const int MAXX = 5000000;
bool ok[MAXX];

void work(){
    for(int i=0; i<K; i++){
        ok[prime[i]] = true;
    }
    int cnt=0;
    for(int i=2; i<MAXX; i++){
        if(ok[i]){
            cnt+=1;
            if(cnt==N){
                fout<<i<<endl;
                exit(0);
            }
            for(int j=0; j<K; j++){
                int t = i*prime[j];
                if(t<MAXX){
                    ok[t] = true;
                }
            }
        }
    }
}

int main(){
    fin>>K>>N;
    for(int i=0; i<K; i++){
        fin>>prime[i];
    }
    work();

    return 0;
}

