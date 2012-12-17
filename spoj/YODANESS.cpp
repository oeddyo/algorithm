#include <iostream>
#include <map>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

map <string,int> mymap;
int t,n;
const int MAXN = 30001;

//char *words;
//char *order;

string words[MAXN];
int f[MAXN];
int tree[MAXN];
int max_val;
void update(int x, int idx){
    while(idx<=max_val){
        tree[idx]+=x;
        idx += (~(idx-1))&idx;
    }
}
int get_sum(int idx){
    int sum =0;
    while(idx>0){
        sum += tree[idx];
        idx-= (~(idx-1))&idx;
    }
    return sum;
}


void work(){
    int ans = 0;
    max_val = n;
    memset(tree,0,sizeof(tree));
    for(int i=n; i>=1; i--){
        //cout<<" for "<<f[i]<<" adding "<<get_sum(f[i])<<endl;
        ans+=get_sum(f[i]);
        
        update(1, f[i]);
    }
    cout<<ans<<endl;
}


int main(){
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0; i<n; i++){
            cin>>words[i];
        }
        string order; 
        for(int i=0; i<n; i++){
            cin>>order;
            mymap[order]=i;
        }
        for(int i=0; i<n; i++){
            f[i+1] = mymap[words[i]]+1;
        }
        work();
    }
    return 0;
}

