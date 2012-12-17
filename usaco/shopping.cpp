/*
ID: xieke.b1
PROG: shopping
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <string.h>

using namespace std;

ifstream fin("shopping.in");
ofstream fout("shopping.out");


const int MAXN = 100;
const int MAXM = 6;
typedef pair<int, int> pii;

int dp[MAXM][MAXM][MAXM][MAXM][MAXM] ;
int s,b,INF;
int P[MAXN][7];
int c_map[1001];
int buy[7];

int get_ans(int a1, int a2, int a3, int a4, int a5){
    //cout<<"at "<<a1<<" "<<a2<<" "<<a3<<" "<<a4<<" "<<a5<<endl; 
    if( dp[a1][a2][a3][a4][a5] != INF ){
        return dp[a1][a2][a3][a4][a5];
    }

    int w1,w2,w3,w4,w5;
    long long int t_min = INF;
    for(int i=1; i<=s; i++){
        w1 = a1-P[i][1];
        w2 = a2-P[i][2];
        w3 = a3-P[i][3];
        w4 = a4-P[i][4];
        w5 = a5-P[i][5];
        if(w1<0 || w2<0 || w3<0 || w4<0 || w5<0){
            continue;
        }
        //cout<<"P is "<<P[i][0]<<endl;
        long long int t2 = P[i][0] + get_ans(w1,w2,w3,w4,w5);
        //cout<<"P[i][0]+get = "<<P[i][0]+get_ans(w1,w2,w3,w4,w5)<<endl;
        //t_min = min(t_min, P[i][0]+get_ans(w1,w2,w3,w4,w5)); 
        //cout<<"t2 = "<<t2<<endl;
        t_min = min(t_min, t2);
    }
    //cout<<"t_min = "<<t_min<<endl;
    dp[a1][a2][a3][a4][a5] = t_min; 
    return t_min;
}


void work(){
    fout<<get_ans(buy[1],buy[2], buy[3],buy[4],buy[5])<<endl;
}


int main(){
    memset(c_map, -1, sizeof(c_map));
    fin>>s;
    int n_cnt = 0;
    for(int i=1; i<=s; i++){
        int n;
        fin>>n;
        for(int j=0; j<n; j++){
            int c,k;
            fin>>c>>k;
            if( c_map[c] == -1){
                c_map[c] = ++n_cnt;
            }
            P[i][c_map[c]] = k;
        }
        fin>>P[i][0];
    }
    fin>>b;
    for(int i=1; i<=b; i++){
        int c,k,p;
        fin>>c>>k>>p;
        if( c_map[c] == -1){
            c_map[c] = ++n_cnt;
        }
        P[s+i][c_map[c]] = 1;
        P[s+i][0] = p;
        buy[c_map[c]] = k;

    }
    s+=b;
    memset(dp, 0xF, sizeof(dp));
    INF = dp[0][0][0][0][0];
    dp[0][0][0][0][0] = 0;
    cout<<"INF = "<<INF<<endl;
    work();
    
    return 0;
}

