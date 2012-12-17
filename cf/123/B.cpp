#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <string.h>

using namespace std;

typedef pair<int, double> pii;
typedef pair< pii, int> piii;


int N,M;
int bask[200000];


void work(){
    double mid = (M+1.0)/2.0;
    memset(bask,0,sizeof(bask));
    priority_queue <pii, vector<piii>, greater<piii> > Q; 
    piii tmp;
    for(int i=1; i<=M; i++){
        tmp.first.first = 0;//num
        tmp.first.second = fabs(mid-i);
        tmp.second = i;
        Q.push(tmp); 
    }

    int n = N;

    for(int i=1; i<=N; i++){
        tmp = Q.top();
        Q.pop();
        tmp.first.first+=1;
        bask[i]=tmp.second;
        Q.push(tmp);
    }
    for(int i=1; i<=N; i++){
        cout<<bask[i]<<endl;
    }
}

int main(){
    cin>>N>>M;
    work();

    return 0;
}

