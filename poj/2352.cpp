#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <algorithm>

using namespace std;
int N;
const int MAXN = 15001;
int stars[MAXN][2];
int star_x[MAXN],star_y[MAXN];

typedef pair<int,int> mypair;
vector < mypair > my_v;

int tree[MAXN*2];
int max_val;
int level[MAXN*2];
void update(int val, int idx){
    while(idx<=max_val){
        tree[idx]+=val;
        idx+= (~(idx-1))&idx;
    }
}
int query(int idx){
    int sum=0;
    while(idx>0){
        sum+=tree[idx];
        idx -= (~(idx-1))&idx;
    }
    return sum;
}


void work(){
    memset(level,0,sizeof(level));
    for(int i=0; i<N; i++){
        update(1,star_x[i]);
        level[query(star_x[i])-1] ++;
        //cout<<"adding level "<<query(star_x[i])-1<<endl;;
    }
    for(int i=0; i<N; i++){
        cout<<level[i]<<endl;
    }

/*
    for(int i=0; i<N; i++){
        update(star_x[i], star_y[i], 1);
    }
    
    for(int i=0; i<N; i++){
        cout<<query(star_x[i], star_y[i])<<endl;;
    }
*/
}
void preprocess(){
    for(int i=0; i<N; i++){
        my_v.push_back(mypair(star_x[i], i));
        //cout<<star_x[i]<<" ";
    }
    //cout<<endl;
    sort(my_v.begin(), my_v.end());
    int cnt = 1;
    int pre = -1;
    for(int i=0; i<N; i++){
        if(pre!=my_v[i].first){
            star_x[my_v[i].second] = cnt++;
            pre = my_v[i].first;
        }else{
            star_x[my_v[i].second] = star_x[my_v[i-1].second];
        }
    }
    max_val = cnt;
    my_v.clear();
    for(int i=0; i<N; i++){
        my_v.push_back(mypair(star_y[i], i));
    }
    sort(my_v.begin(), my_v.end());
    cnt = 1;
    pre = -1;
    for(int i=0; i<N; i++){
        //cout<<"seeing "<<my_v[i].first<<endl;
        if(pre!=my_v[i].first){
            star_y[my_v[i].second] = cnt++;
            pre = my_v[i].first;
        }else{
            star_y[my_v[i].second] = star_y[my_v[i-1].second];
        }
    }
    for(int i=0; i<N; i++){
        //cout<<star_x[i]<<" "<<star_y[i]<<endl;
    }
}


int main(){
    scanf("%d",&N);
    for(int i=0; i<N; i++){
        scanf("%d %d",&stars[i][0], &stars[i][1]);
        star_x[i] = stars[i][0];
        star_y[i] = stars[i][1];
    }
    preprocess();
    work();

    return 0;
}

