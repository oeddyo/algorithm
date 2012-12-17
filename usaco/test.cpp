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

const int INF = 999999999;
typedef vector<int> vi;

vi num;
int len, N;
bool vis[10];

bool judge(vi & n){
    memset(vis,0,sizeof(vis));
    int t_len = len;
    int cur = 0;
    t_len--;
    while(t_len--){
        int cur = n[cur];
        if(vis[cur])return false;
        vis[cur] = true;
    }
    return true;
}

void print(vi &n){
    for(int i=0; i<n.size(); i++){
        cout<<n[i];
    }cout<<endl;
}

void get_next(vi &n){
    bool ok = 0;
    for(int i=len-1; i>=0; i--){
        if(n[i]<9){
            n[i]++;
            ok = 1;
            for(int j=i+1; j<=len-1; j++){
                n[j] = 1;
            }
            return ;
        }
    }
    vi t;
    t.push_back(1);
    for(int i=0; i<len; i++)t.push_back(1);
    len+=1;
    n = t;
}

vi< vi > numbers;



vi order;



void generate(int cur){
    if(cur==len){
        numbers.push_back(order); 
        return ;
    }
    

}


void work(){
    int t_N = N;
    while(t_N){
        num.push_back(t_N%10);
        t_N/=10;
    }
    reverse(num.begin(), num.end());
    get_next(num);
    len = num.size();

    vi w;
    for(int i=0; i<len; i++){
        w.push_back(i);
    }

    while(next_permutation(w.begin(), w.end())){
        if(judge(w)){
            order = w;
            generate(0);
        
        }
        //print(w);
    }



}

int main(){
    /*
    vi w;
    for(int i=0; i<9; i++){
        w.push_back(i);
    }

    len = w.size();
    int cnt = 0;
    */
    fin>>N;
    work();

    return 0;
}

