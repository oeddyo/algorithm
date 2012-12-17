#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class DengklekPaintingSquares {
    public:
        int numSolutions(int, int);
};
const int MAXN = 101;
const int MAXS = 1<<9;
long long int dp[MAXN][MAXS];
int g_M;
long long int MOD = 1000000007;

void show_bin(int k, int M){
    while(M--){
        cout<<k%2;
        k>>=1;
    }
    cout<<endl;
}
bool check(int cur, int pre){
    for(int i=0; i<g_M; i++){
        int cnt = 0;
        if( ((1<<i)&cur)!=0 ){
            if(   i-1 >= 0 &&  ((1<<(i-1))&cur)!=0 ){
                cnt++;
            }
            if( ((1<<(i+1))&cur) != 0){
                cnt++;
            }
            if( ((1<<i)&pre) != 0){
                cnt++;
            }
            if(cnt&1==1){
                return false;
            }
        }
        cnt = 0;
        if( ((1<<i)&pre)!=0 ){
            if(   i-1 >= 0 &&  ((1<<(i-1))&pre)!=0 ){
                cnt++;
            }
            if( ((1<<(i+1))&pre) != 0){
                cnt++;
            }
            if( ((1<<i)&cur) != 0){
                cnt++;
            }
            if(cnt&1 == 1){
                return false;
            }
        }
    }
    return true;
}

bool check_first(int s){
    int mask = 3;
    int t = s;
    while(t){
        if(s==5){
            cout<<"ok now t&mask="<<(t&mask)<<endl;
            cout<<(((t&mask)&3)==3)<<endl;
        }
        if( (t&mask) == 3){
            return false;
        }
        t>>=1;
    }
    return true;
}

int DengklekPaintingSquares::numSolutions(int N, int M) {
    memset(dp,0,sizeof(dp));
    
    /* 
    for(int s=0; s<(1<<M); s++){
        if(check_first(s)){
            dp[0][s] = 1;
            cout<<"state "<<s<<" is zero"<<endl;
        }
    }*/
    for(int s=0; s<(1<<M); s++){
        dp[0][s] = 1;
    }

    g_M = M;
    for(int i=1; i<N; i++){
        for(int pre=0; pre<(1<<M); pre++){
            for(int cur=0; cur<(1<<M); cur++){
                /*
                cout<<"pre is ";
                show_bin(pre, g_M);
                cout<<"cur is ";
                show_bin(cur, g_M);
                */
                if(check(cur, pre) ){
                    //cout<<"ok"<<endl;
                    dp[i][cur] += dp[i-1][pre];
                    dp[i][cur] %= MOD;
                }
            }
        }
    }
    
    int ans = 0;
    for(int s=0; s<(1<<M); s++){
        ans += dp[N-1][s];
        cout<<"dp["<<N-1<<"]["<<s<<"]="<<dp[N-1][s]<<endl;
        ans %= MOD;
    }
    return ans;
}
double test0() {
    int p0 = 2;
    int p1 = 4;
    DengklekPaintingSquares * obj = new DengklekPaintingSquares();
    clock_t start = clock();
    int my_answer = obj->numSolutions(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p2 = 48;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p2 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p2 != my_answer) {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
double test1() {
    int p0 = 2;
    int p1 = 3;
    DengklekPaintingSquares * obj = new DengklekPaintingSquares();
    clock_t start = clock();
    int my_answer = obj->numSolutions(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p2 = 19;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p2 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p2 != my_answer) {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
double test2() {
    int p0 = 2;
    int p1 = 2;
    DengklekPaintingSquares * obj = new DengklekPaintingSquares();
    clock_t start = clock();
    int my_answer = obj->numSolutions(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p2 = 8;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p2 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p2 != my_answer) {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
double test3() {
    int p0 = 47;
    int p1 = 7;
    DengklekPaintingSquares * obj = new DengklekPaintingSquares();
    clock_t start = clock();
    int my_answer = obj->numSolutions(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p2 = 944149920;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p2 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p2 != my_answer) {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
int main() {
    int time;
    bool errors = false;

    time = test0();
    if (time < 0)
        errors = true;
    time = test1();
    if (time < 0)
        errors = true;
    time = test2();
    if (time < 0)
        errors = true;
    time = test3();
    if (time < 0)
        errors = true;

    if (!errors)
        cout <<"You're a stud (at least on the example cases)!" <<endl;
    else
        cout <<"Some of the test cases had errors." <<endl;
}

