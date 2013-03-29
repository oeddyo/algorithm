#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 2000001;
const int INF = 99999999;

string Str;
int  stp, N, K, test_cnt = 1;
int P[25][MAXN], height[MAXN], mapping[MAXN];

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
        cout<<Str[i];
    }
}


void build_sa(){
    N = Str.size();
    for(int i=0; i<N; i++){
        P[0][i] = Str[i]-'.';
    }
    //cout<<"here"<<endl;
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
    
    for(int i=0; i<N; i++){
        mapping[ P[stp-1][i] ] = i;
    }
    /*
    for(int i=0; i<N; i++){
        cout<<P[stp-1][i]<<" ";
    }cout<<endl;

    cout<<"begin printing"<<endl;
    for(int i=0; i<N; i++){
        cout<<i<<" ";
        myprint(mapping[i], N-1);
        cout<<endl;
    } 
    */
    height[0] = 0;
    for(int i=1; i<N; i++){
        height[i] = lcp(mapping[i-1], mapping[i]);
    }
    
    
    int initial_N = (N-1)/2;
    int ans = 0;
    int left = 0, right = 0;
    //odd
    for(int i=0; i<initial_N-1; i++){
        int pre = lcp(i+1, initial_N*2+1-i-1+1);
        if(2*pre+1>ans){
            ans = 2*pre+1;
            left = i-pre;
            right = i+pre;
        }
    }
    //even
    for(int i=0; i<initial_N; i++){
        int pre = lcp(i, initial_N*2+1-i-1+1);
        if(2*pre>ans){
            ans = pre*2;
            left = i-pre;
            right = i+pre-1;
        }
    }

    //cout<<"ans = "<<ans<<endl; 
    myprint(left, right);
    cout<<endl;
    //cout<<"Case "<<test_cnt<<": "<<ans<<endl;
    test_cnt++;
}

void work(){

}


int main(){
    
    while(std::getline(std::cin, Str)){
        if(Str=="END"){
            break;
        }

        string rev = Str;
        reverse(rev.begin(), rev.end());
        Str += '#';
        Str += rev;
        build_sa();

        work();
    }

    return 0;
}

