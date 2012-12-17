#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdio.h>
#include <vector>
using namespace std;

typedef pair<int, int> mypair;
vector< mypair > my_vector;
const int MAXN = 500001;
int n;
long long data[MAXN],b[MAXN],d[MAXN],tree[MAXN];
long long max_val;

inline void update(long long val, long long idx){
    while(idx<=max_val){
        tree[idx]+=val;
        idx+=(~(idx-1))&idx;
    }
}

inline long long get_sum(long long idx){
    long long sum = 0; 
    while(idx>0){
        sum+=tree[idx];
        idx-=(~(idx-1))&idx;
    }
    return sum;
}
    
void work(){
    //discretify it
    memset(tree,0,sizeof(tree));
    sort(my_vector.begin(), my_vector.end());
    int cnt =1;
    int pre = -1;
    for(int i=0; i<n; i++){
        int num = my_vector[i].first ;
        int pos = my_vector[i].second ;
        if(num!=pre){
            pre = num;
            b[pos] = cnt++;
        }else{
            b[pos] = cnt;
        }
    }
    max_val = n;
    long long int ans = 0;
    for(int i=max_val; i>=1; i--){
        int t = b[i];
        ans+=get_sum( t-1);
        update(1, t);
    }
    printf("%lld\n",ans);
}

int main(){
    while(1){
        scanf("%d",&n);
        if(n==0)break;
        my_vector.clear();
        for(int i=0; i<n; i++){
            scanf("%lld",&data[i]);
            my_vector.push_back(mypair(data[i], i+1));
        }
        work();
    }
    return 0;
}

