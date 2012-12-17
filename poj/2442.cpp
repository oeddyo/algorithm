#include <iostream>
#include <cmath>
#include <algorithm>
#include <stdio.h>
#include <vector>
#define MAXN 20001
using namespace std;

int T,m,n;

//int data[500][MAXN];
vector<int> data[500];
int store[20000*500];
int ptr,limit;
void dfs( int depth, int pos, int sum){
    if(ptr>n*2){
        return ;
    }
    if(depth>=m-1){
        store[ptr]=sum+data[depth][pos];
        ptr++;
        return ;
    }
    sum = sum+data[depth][pos];
    for(int i=0; i<limit; i++){
        dfs(depth+1,i,sum);
    }
}

void work(){
    int v = (int) (ceil(pow(n,1.0/m)));
    limit = (v> n)?n:v;
    //cout<<"limit is "<<limit<<endl;

    ptr = 0;
    for(int i=0; i<limit; i++){
        dfs(0,i, 0);
    }
    sort(store,store+ptr);
    for(int i=0; i<n-1; i++){
        cout<<store[i]<<" ";
    }cout<<store[n-1]<<endl;
}
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d %d",&m,&n);
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int t;
                scanf("%d",&t);
                //scanf("%d",&data[i][j]);
                data[i].push_back(t);
            }
            sort(data[i].begin(), data[i].end());
        }
        sort(data, data+m);
        reverse(data, data+m);
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                cout<<data[i][j]<<" ";
            }cout<<endl;
        }
        //cout<<"go in work"<<endl;
        work();
    }
    return 0;
}
