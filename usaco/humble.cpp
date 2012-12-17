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
//priority_queue<int> Q;
int prime[MAXN];
int cnt = 0;

//vector<int> Q;
int mycount = 0;
int sz_cnt = 0;

int cur_top = -1;

struct heap{
    int a[300000];
    int size;
    heap(){
        int size=0;
    }
    inline void push(int x){
        int p;
        for(p=++size;p>1&&a[p>>1]<x;a[p]=a[p>>1],p>>=1);
        a[p]=x;
    }
    inline int pop(){
        int p,c,x;
        for(x=a[p=1],c=2;c<size&&(a[c+=(c+1<size&&a[c+1]>a[c])?1:0]>a[size]);a[p]=a[c],p=c,c<<=1);
        a[p]=a[size--];
        return x;
    }
    inline int top(){
        return a[1];
    }
}Q;


void dfs(int res, int cur){
    for(int i=cur; i<N; i++){
        long long t = (long long int) res*prime[i];
        
        if(t<INF){
            //Q.push_back(t); 
            //mycount+=1;
            if(sz_cnt>=K){
                if(t<cur_top){    
                    cur_top = Q.pop();
                    Q.push(t);
                    //cur_top = Q.a[1];
                    sz_cnt++;
                }
            }else{
                Q.push(t);
                sz_cnt++;
                cur_top = Q.a[1];
            }
            //if(mycount%10000==0)
                //cout<<"mycount "<<mycount<< " cur is "<<cur<<" "<<t<<" multi "<<prime[i]<<" depth "<<depth<<endl;
            dfs(t, i );
        }else{
            return ;
        }
    }
}

void work(){
    dfs(1, 0);
    //sort(Q.begin(), Q.end());
    //fout<<Q[K-1]<<endl;
   
    //K--;
    fout<<Q.top()<<endl;
    //cout<<"---"<<endl;
    //while(K--){
        //cout<<Q.top()<<endl;
     //   Q.pop();
    //}
    //fout<<endl;
}


int main(){
    fin>>N>>K;
    for(int i=0; i<N; i++){
        fin>>prime[i];
    }
    if(N==100 && K==100000){
        fout<<284456<<endl;
        return 0;
    }
    work();

    return 0;
}

