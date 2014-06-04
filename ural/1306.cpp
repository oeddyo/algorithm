#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <iomanip>
#include <queue>
#include <list>
#include <stack>
#include <map>
#include <set>
using namespace std;
 
#define DEBUG
#define REP(i,a) for(i=0;i<a;i++)
#define FOR(i,a,b) for(i=a;i<b;i++)
#define VE vector<int>
#define SZ size()
#define PB push_back


const int MAXN=250005;
//unsigned int data[MAXN];
priority_queue<unsigned int> Q;

int N;


void work(){
    int cnt = 0;
    int half = N/2 + 1;
    for(int i=0; i<N; i++){
        unsigned int t;
        scanf("%u", &t);
        Q.push(t);
        //Q.push(data[i]);
        if(Q.size() > half){
            Q.pop();
        }
    }
       
    double ans  = 0.0;
    if(N%2==0){
        unsigned int A=Q.top();Q.pop(); unsigned int B = Q.top();
        ans = A*1.0;
        ans += B;
        ans/=2.0;
    }else{
        ans = Q.top()*1.0;
    }
    cout<<setprecision(1)<<fixed<<ans<<endl;
}

int main(){

    scanf("%d", &N);
    /*
    for(int i=0; i<N; i++){
        scanf("%u", &data[i]);
    }
    */

    work(); 

    return 0;
}

