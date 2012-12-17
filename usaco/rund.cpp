/*
ID: xieke.b1
PROB: runround
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <vector>
#include <string.h>

using namespace std;
ifstream fin("runround.in");
ofstream fout("runround.out");

const unsigned long INF = 4294967294;
typedef vector<int> vi;

unsigned long len, N;

bool vis[10];
int num[10];
int g_len;
bool judge(unsigned n){
    memset(vis,0,sizeof(vis));
    int cur =g_len-1;
    int len = g_len;
    while(n){
        int t = n%10;
        if(t==0)return false;
        if(vis[t])return false;
        vis[t] = true;
        n/=10;
        num[cur--] = t;
    }
    /*
    for(int i=0; i<g_len; i++){
        cout<<num[i]<<" ";
    }cout<<endl;
*/
    cur = 0;
    memset(vis,0,sizeof(vis));
    //cout<<"the len is "<<len<<endl;
    while(len--){
        cur = (cur+num[cur])%g_len;
        //cout<<"now at "<<cur<<endl;
        if(vis[cur])return false;
        vis[cur] = true;
    }
    return true;
}

void work(){
    N++;
    unsigned long t_N = N;
    while(t_N){
        t_N/=10;
        g_len++;
    }
    //cout<<judge(123);
   // return ;
    
    
    for(int i=N; i<INF; i++){
        //cout<<"now at "<<i<<endl;
        if(judge(i) ){
            fout<<i<<endl;
            break;
        }
    }
}

int main(){
    fin>>N;
    work();
     
    return 0;
}

