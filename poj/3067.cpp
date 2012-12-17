#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int T,N,M,K;

typedef pair<int, int> mypair;
vector < mypair > my_vector;
const int MAXN = 1000001;
long long int tree[MAXN];
int max_val;
void update(int idx, int val){
    while(idx<=max_val){
        tree[idx]+=val;
        idx+= (~(idx-1))&idx;
    }
}
long long int get_sum(int idx){
    int sum=0;
    while(idx>0){
        sum+=tree[idx];
        idx -= (~(idx-1))&idx;
    }
    return sum;
}

void brute(){
    int sum = 0;
    for(int i=0; i<K; i++){
        for(int j=i+1; j<K; j++){
            int L1, L2, R1, R2;
            L1 = my_vector[i].first;
            R1 = my_vector[i].second;
            L2 = my_vector[j].first;
            R2 = my_vector[j].second;
            if(L1<L2 && R1>R2){
                sum++;
            }else if(L1>L2 && L1<R2){
                sum++;
            }

        }
    }
    cout<<sum<<endl;
}

void work(){
    memset(tree,0,sizeof(tree));
    long long ans = 0,p,t;
    max_val = M;
    for(int i=0; i<K; i++){
        p = my_vector[i].second;
        t = get_sum(M) - get_sum(p);
        ans+=t;
        //cout<<"adding "<<t<<" for pair "<<my_vector[i].first<<" "<<my_vector[i].second<<endl;
        update(p,1);
    }
    cout<<ans<<endl;
}

int main(){
    scanf("%d",&T);
    for(int test=1; test<=T; test++){    
        scanf("%d %d %d",&N,&M,&K);
        my_vector.clear();
        for(int i=0; i<K;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            my_vector.push_back(mypair(a,b));
            //cout<<"now "<<a<<" "<<b<<endl;
        }
        sort(my_vector.begin(), my_vector.end());
        
        cout<<"Test case "<<test<<": ";
        work();
        //brute();
    }
    return 0;
}

