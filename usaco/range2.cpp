/*
ID: xieke.b1
PROB: range
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <string.h>
#include <cmath>

using namespace std;

ifstream fin("range.in");
ofstream fout("range.out");

typedef pair<int, int> pii;
const int MAXN = 251;
const int INF = 999999999;
string t;
int N;


bool sq[MAXN][MAXN];
int sq_ans[MAXN];
int rows[MAXN][MAXN];
int cols[MAXN][MAXN];

void work(){
    memset(rows,0,sizeof(rows));
    memset(cols,0,sizeof(cols));
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            int t_cnt = 0;
            for(int k=j; k<N; k++){
                if(sq[i][k]){
                    t_cnt+=1; 
                }else{
                    break;
                }
            }
            rows[i][j] = t_cnt;
            t_cnt = 0;
            for(int k=i; k<N; k++){
                if(sq[k][j]){
                    t_cnt+=1;
                }else{
                    break;
                }
            }
            cols[i][j] = t_cnt;
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(sq[i][j]==0)continue;

            int sz = 1;
            while(sz<=N){
                if( j+sz<N && cols[i][j+sz]>sz && i+sz<N && rows[i+sz][j]>sz){
                    sz++;
                }else{
                    break;
                }
            }
           // cout<<i<<" "<<j<<" size="<<sz<<endl;
           // cout<<"cols[i][j+1] = "<<cols[i][j+1]<<" rows[i+1][j] = "<<rows[i+1][j]<<endl;
            for(int i=2; i<=sz; i++){
                sq_ans[i]+=1;
            }
        }
    }
    
    for(int i=0; i<=N; i++){
        if(sq_ans[i]){
            fout<<i<<" "<<sq_ans[i]<<endl;
        }

    }

}

int main(){
    fin>>N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            char t;
            fin>>t;
            sq[i][j] = t-'0';
            //cout<<sq[i][j];
        }//cout<<endl;
    }
    //cout<<"start"<<endl;
    work();
    return 0;
}

