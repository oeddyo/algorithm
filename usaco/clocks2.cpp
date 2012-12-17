/*
ID: xieke.b1
PROG: clocks
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <string.h>
#include <queue>

using namespace std;

ofstream fout("clocks.out");
ifstream fin ("clocks.in");

//int s[9];
vector<int> start;
vector<int> final;

const int MAXN = 1200000;
int vis[MAXN];
string dir[10]={
    "",
    "ABDE",
    "ABC",
    "BCEF",
    "ADG",
    "BDEFH",
    "CFI",
    "DEGH",
    "GHI",
    "EFHI"
};

int szs[10] = {
    0,
    4,3,4,3,5,3,4,3,4};
int compute(vector<int> &s){
    int res = 0;
    for(int i=0; i<9; i++){
        res = res*4+s[i];
    }
    return res;
}

void print(vector<int> s){
    for(int i=0; i<s.size(); i++){
        cout<<s[i]<<" ";
    }
    cout<<endl;
}

typedef pair< vector<int> , string> mp;

void bfs(vector<int> s){
    int tmp = compute(s);
    vis[tmp] = 1;
    queue<pair< vector<int> , string> > Q;
    mp ns;
    Q.push( mp(s, "") );
    while(!Q.empty()){
        ns = Q.front();
        Q.pop();
        if(ns.first==final){
            cout<<ns.second<<endl;
            for(int i=0; i<ns.second.size()-1; i++){
                fout<<ns.second[i]<<" ";
            }fout<<ns.second[ns.second.size()-1]<<endl;

            return ;
        }
        for(int i=1; i<=9; i++){
            int sz = szs[i];
            vector<int> t= ns.first;
            for(int j=0; j<sz; j++){
                int pos = dir[i][j]-'A';
                t[pos]+=1;
                if(t[pos]==4)t[pos]=0;
            }
            int state = compute(t);
            if( vis[state]==0){
                Q.push( mp(t, ns.second+char('0'+i)) );
                vis[state] = 1;
            }
        }
    }
}

void work(){
    bfs(start);
}


int main(){
    for(int i=0; i<9; i++){
        int t;
        fin>>t;
        start.push_back((t/3)%4);
        final.push_back(0);
        //fin>>s[i];
    }
    work(); 
    return 0;
}

