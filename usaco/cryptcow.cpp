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
const int MAXM = 80;
string S;
string _goal = "Begin the Escape execution at the Break of Dawn";
int g_sz;
int ans = -1;

const int PRIME = 999991;

bool hash[PRIME];

/*
int get_hash(string &t, int sz){
    unsigned long seed = 131313, h_value = 0;
    for(int i=0; i<sz; i++){
        h_value = h_value*seed+(t[i]);
    }
    return (h_value&0x7FFFFFFF) % PRIME;
}*/

int get_hash(string &t, int sz){
    unsigned long h = 0;
    for(int i=0; i<sz; i++){
        h = (h<<4) + t[i];
        unsigned long g = h & (0xf0000000L);
        if(g)
            h^= g>>24;
        h&=~g;
    }return h%PRIME;
}


void dfs(string &S, int sz, int C, int depth){
    if(ans!=-1)return ;
    if(C==0){
        if(S==_goal){
            ans = depth;
        }
        return ;
    }
    int h_value = get_hash(S,sz);
    if( hash[h_value] ){
        return ;
    }
    hash[h_value] = 1;
    int rear = g_sz-1;
    for(int i=0; i<sz; i++){
        if(S[i]=='C')break;
        if(S[i] != _goal[i])return ;
        if(S[i] == 'W' || S[i]=='O')return ;
    }
    for(int i=sz-1; i>=0; i--){
        if(S[i]=='W')break;
        if(S[i] != _goal[rear--])return ;
        if(S[i]=='C' || S[i]=='O')return ;
    }

    int cnt=0, c_cnt = 0, o_cnt = 0, w_cnt = 0;
int c[MAXM], o[MAXM], w[MAXM], label[MAXM];
    memset(c,0,sizeof(c));
    memset(o,0,sizeof(o));
    memset(w,0,sizeof(w));
    memset(label,0,sizeof(label));
    for(int i=0; i<sz; i++){
        if(S[i]=='C'){
            c[c_cnt++] = i;
            label[cnt++] = i;
        }else if(S[i]=='O'){
            o[o_cnt++] = i;
            label[cnt++] = i;
        }else if(S[i]=='W'){
            w[w_cnt++] = i;
            label[cnt++] = i;
        }
    }
    label[cnt++] = sz;
    for(int i=0; i<cnt-1; i++){
        if(label[i]+1 < label[i+1]){
            string sub = S.substr(label[i]+1, label[i+1]-1-label[i]);
            if(_goal.find(sub) == string::npos){
                return ;
            }
        }
    }

    for(int i=0; i<o_cnt; i++){
        for(int j=0; j<c_cnt; j++){
            for(int k=w_cnt-1; k>=0; k--){
                if(c[j]<o[i] && o[i]<w[k]){
                    string t1 = S.substr(0,c[j]);
                    string t2 = S.substr(o[i]+1, w[k]-o[i]-1);
                    string t3 = S.substr(c[j]+1,o[i]-c[j]-1);  
                    string t4 = S.substr(w[k]+1,sz-w[k]);  
                    string t = t1+t2+t3+t4 ;  
                    dfs(t, sz-3, C-1, depth+1);  
                }
            }
        }

    }
}


void work(){
    g_sz = _goal.size();
    int C = 0;
    for(int i=0; i<S.size(); i++){
        if(S[i]=='C'){
            C++;
        }
    }
    ans = -1;
    dfs(S, S.size(), C,  0);
    if(ans==-1){
        fout<<"0 0"<<endl;
    }else{
        fout<<1<<" "<<ans<<endl;
    }

}

int main(){
    getline(fin, S);
    cout<<"S is "<<S<<endl;
    work();

    return 0;
}

