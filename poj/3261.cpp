#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 20001;

int num[MAXN], stp, N, K;
int P[20][MAXN], height[MAXN], mapping[MAXN];

struct entry {
    int nr[2];
    int p;
}L[MAXN];

bool mycmp(struct entry a, struct entry b){
    return a.nr[0]==b.nr[0]?(a.nr[1]<b.nr[1]?1:0):(a.nr[0]<b.nr[0]?1:0);
}

int lcp(int x, int y){
    int k,ret =0;
    if(x==y)return N-x;
    for(k=stp-1; k>=0 && x<N && y<N; k--){
        if(P[k][x]==P[k][y]){
            x+= 1<<k, y+=1<<k, ret += 1<<k;
        }
    }
    return ret;
}

void myprint(int start, int end){
    for(int i=start; i<=end; i++){
        cout<<num[i];
    }
}


void build_sa(){
    for(int i=0; i<N; i++){
        P[0][i] = num[i];
    }
    int cnt = 1;
    for(stp=1; cnt>>1 < N ; cnt<<=1, stp+=1){
        for(int i=0; i<N; i++){
            L[i].nr[0] = P[stp-1][i];
            L[i].nr[1] = i+cnt<N?P[stp-1][i+cnt]:-1;
            L[i].p = i;
        }
        sort(L,L+N,mycmp);
        for(int i=0; i<N; i++){
            P[stp][L[i].p] = i>0 && L[i].nr[0]==L[i-1].nr[0] && L[i].nr[1]==L[i-1].nr[1]? P[stp][L[i-1].p]:i;
        }
    }
    /*
    for(int i=0; i<N; i++){
        cout<<P[stp-1][i]<<" ";
    }cout<<endl;
    */

    for(int i=0; i<N; i++){
        mapping[ P[stp-1][i] ] = i;
    }
    /*
    cout<<"begin printing"<<endl;
    for(int i=0; i<N; i++){
        myprint(mapping[i], N-1);
        cout<<endl;
    } 
    */

    height[0] = 0;
    for(int i=1; i<N; i++){
        height[i] = lcp(mapping[i-1], mapping[i]);
    }
    /*
    for(int i=0; i<N; i++){
        cout<<"height["<<i<<"] = "<<height[i]<<endl;
    }
    */
}


bool judge(int len){
    bool in = false;
    int count = 0, ans = 0;
    bool ok = true;
    
    for(int i=0; i<N; i++){
        if(height[i]>=len && in){
            //cout<<"at pos "<<i<<" continue add 1"<<endl;
            count++;
        }else if(height[i]>=len && !in){
            //cout<<"at pos "<<i<<" initial 1"<<endl;
            in = true;
            count = 1;
        }else if(height[i]<len){
            //cout<<"at pos "<<i<<" go out set 0"<<endl;
            in = false;
            ans = max(ans, count);
            count = 0;
        }
    }
    ans = max(ans, count);
    ans+=1;
    //cout<<"checking length = "<<len<<" count = "<<ans<<endl;
    if(ans>=K){
        return true;
    }return false;
}


void work(){
    int low = 0, high = N-1;
    int ans = 0;
    while(low<=high){
        //cout<<"low = "<<low<<" high = "<<high<<endl;
        int mid = (low+high)/2;
        if(judge(mid)){
            low = mid+1;
            ans = mid;
        }else{
            high = mid-1;
        }
    }
    cout<<ans<<endl; 
}


int main(){
    
    
    while(scanf("%d %d", &N, &K)!=EOF){

        for(int i=0; i<N; i++){
            scanf("%d", &num[i]);

        }
        build_sa();
        work();
    }

    return 0;
}

