/*
ID: xieke.b1
PROB: cryptcow
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <stack>
#include <vector>
#include <string.h>
#include <queue>

using namespace std;
ifstream fin("cryptcow.in");
ofstream fout("cryptcow.out");

int INF = 999999999;
const int MAXN = 51;

string S;
string _goal = "Begin the Escape execution at the Break of Dawn";
string cur;

int countA[1000];
int countB[1000];
int ans = -1;

const int PRIME = 99991;
bool hash[PRIME];
bool hash2[PRIME];

int get_hash(string &t){
    unsigned long seed = 131313, h_value = 0;
    int sz = t.size();
    for(int i=0; i<sz; i++){
        h_value = h_value*seed+(t[i]);
    }
    return (h_value&0x7FFFFFFF) % PRIME;
}


void dfs(int depth){


}

void work(){    

}


int main(){
    getline(fin, S);
    work();
     
    return 0;
}

