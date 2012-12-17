/*
ID: xieke.b1
PROB: fence8
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <stack>
#include <vector>
#include <string.h>
#include <queue>

using namespace std;
ifstream fin("fence8.in");
ofstream fout("fence8.out");

int INF = 999999999;
const int MAXN = 1500;
const int MAXM = 10000;

int N, R;
int boards[MAXN]={-1}, rails[MAXM]={-1}, bags[MAXN], space, total, numr[MAXN], mid;


bool dfsid(int deep, int pos){
    if( deep<=0 )return true;
    if( space>total-numr[mid] )return false;
    for(int i=pos; i<=N; i++){
        if(bags[i]>=rails[deep]){
            bags[i]-=rails[deep];
            if(bags[i]<rails[1]){
                space+=bags[i];
            }
            if( rails[deep]==rails[deep-1]){
                if(dfsid(deep-1, i))return true;
            }else if( dfsid(deep-1, 1))return true;
            if(bags[i]<rails[1]){
                space-=bags[i];
            }
            bags[i]+=rails[deep];
        }
    }
    return false;
}


void work(){
    sort(boards+1, boards+N+1);
    sort(rails+1, rails+R+1);
    for(int i=1; i<=N; i++)total+=boards[i]; 
    bags[0] = numr[0] = rails[0] = 0;
    for(int i=1; i<=R; i++){
        numr[i] = numr[i-1]+rails[i];
    }

    int left=1, right = R;
    mid = (left+right)/2;
    while(left<=right){
        for(int i=1; i<=N; i++){
            bags[i] = boards[i];
        }
        space = 0;
        cout<<"now at "<<mid<<endl;
        if(dfsid(mid, 1)){
            left = mid+1;
            cout<<"mid = "<<mid<<" ok"<<endl;
            mid = (left+right)/2;
        }else{
            right = mid-1;
            mid = (left+right)/2;
        }
    }
    fout<<mid<<endl;
}

int main(){
    fin>>N;
    for(int i=1; i<=N; i++){
        fin>>boards[i];
    }
    fin>>R;
    for(int i=1; i<=R; i++){
        fin>>rails[i];
    }
    work();
    return 0;
}

