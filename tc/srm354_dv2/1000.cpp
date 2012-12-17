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

class UnsealTheSafe {
    public:
        long long countPasswords(int);
};

const int MAXN = 31;
long long int dp[11][11][MAXN];

int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
bool check(int i, int j){
    if(i==3&&j==0){
        return true;
    }
    if(i<3&&j<3&&i>=0&&j>=0){
        return true;
    }
    return false;
}

long long UnsealTheSafe::countPasswords(int N) {
    memset(dp,0,sizeof(dp));
    for(int i=0; i<=3; i++){
        for(int j=0; j<3; j++){
            if(!check(i,j))continue;
            dp[i][j][1] = 1;
        }
    }
            
    for(int len=2; len<=N; len++){
        for(int i=0; i<=3; i++){
            for(int j=0; j<3; j++){
                if(!check(i,j))continue;
                for(int k=0; k<4; k++){
                    int nx = dir[k][0]+i;
                    int ny = dir[k][1]+j;
                    if(!check(nx,ny)){
                        continue;
                    }else{
                        dp[i][j][len] += dp[nx][ny][len-1];
                    }
                }
            }
        }
    }
    long long sum=0;
    for(int i=0; i<=3; i++){
        for(int j=0; j<3; j++){
            if(!check(i,j))continue;
                sum+=dp[i][j][N];
        }
    }
    return sum;
}
double test0() {
    int p0 = 2;
    UnsealTheSafe * obj = new UnsealTheSafe();
    clock_t start = clock();
    long long my_answer = obj->countPasswords(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    long long p1 = 26LL;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p1 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p1 != my_answer) {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
double test1() {
    int p0 = 3;
    UnsealTheSafe * obj = new UnsealTheSafe();
    clock_t start = clock();
    long long my_answer = obj->countPasswords(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    long long p1 = 74LL;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p1 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p1 != my_answer) {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
double test2() {
    int p0 = 25;
    UnsealTheSafe * obj = new UnsealTheSafe();
    clock_t start = clock();
    long long my_answer = obj->countPasswords(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    long long p1 = 768478331222LL;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p1 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p1 != my_answer) {
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

    if (!errors)
        cout <<"You're a stud (at least on the example cases)!" <<endl;
    else
        cout <<"Some of the test cases had errors." <<endl;
}

