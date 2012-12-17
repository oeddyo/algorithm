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

class SimplifiedDarts {
    public:
        double tryToWin(int, int, int, int);
};

const int MAXN = 1001;
const int MAXM = 3001;
double dp[MAXN][MAXM];
const double INF = 99999999;
double SimplifiedDarts::tryToWin(int W, int N, int P1, int P2) {
    for(int i=0; i<MAXN; i++){
        for(int j=0; j<MAXM; j++){
            dp[i][j] = 0.0;
        }
    }
    dp[0][0] = 1;
    int t_sz = N*3;
    double p2 = P2*1.0/100;
    double p1 = P1*1.0/100;
    double ans = -INF;
    for(int i=0; i<N; i++){
        for(int j=0; j<=W; j++){
            if(dp[i][j]!=0.0){
                cout<<"dp["<<i<<"]["<<j<<"] = "<<dp[i][j]<<endl;
            }
            dp[i+1][j+3] += max(dp[i][j]*p1, dp[i+1][j+3]);
            dp[i+1][j] += max(dp[i][j]*(1-p1), dp[i][j]*(1-p2));
            dp[i+1][j+2] += max(dp[i][j]*p2, dp[i+1][j+2]);
        }
    }
    ans = 0.0;
    for(int i=W; i<=W+3; i++){
        ans += dp[N][i];
        cout<<"dp["<<N<<"]["<<i<<"] = "<<dp[N][i]<<endl;
    }

    return ans;
}
double test0() {
    int p0 = 5;
    int p1 = 2;
    int p2 = 50;
    int p3 = 25;
    SimplifiedDarts * obj = new SimplifiedDarts();
    clock_t start = clock();
    double my_answer = obj->tryToWin(p0, p1, p2, p3);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    double p4 = 12.5;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p4 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p4 != my_answer) {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
double test1() {
    int p0 = 6;
    int p1 = 3;
    int p2 = 90;
    int p3 = 20;
    SimplifiedDarts * obj = new SimplifiedDarts();
    clock_t start = clock();
    double my_answer = obj->tryToWin(p0, p1, p2, p3);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    double p4 = 73.30000000000001;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p4 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p4 != my_answer) {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
double test2() {
    int p0 = 30;
    int p1 = 384;
    int p2 = 3;
    int p3 = 1;
    SimplifiedDarts * obj = new SimplifiedDarts();
    clock_t start = clock();
    double my_answer = obj->tryToWin(p0, p1, p2, p3);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    double p4 = 18.344490479047746;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p4 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p4 != my_answer) {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
double test3() {
    int p0 = 999;
    int p1 = 333;
    int p2 = 0;
    int p3 = 100;
    SimplifiedDarts * obj = new SimplifiedDarts();
    clock_t start = clock();
    double my_answer = obj->tryToWin(p0, p1, p2, p3);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    double p4 = 100.0;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p4 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p4 != my_answer) {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
double test4() {
    int p0 = 1000;
    int p1 = 333;
    int p2 = 0;
    int p3 = 100;
    SimplifiedDarts * obj = new SimplifiedDarts();
    clock_t start = clock();
    double my_answer = obj->tryToWin(p0, p1, p2, p3);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    double p4 = 0.0;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p4 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p4 != my_answer) {
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
    return 0;
    time = test1();
    if (time < 0)
        errors = true;

    time = test2();
    if (time < 0)
        errors = true;

    time = test3();
    if (time < 0)
        errors = true;

    time = test4();
    if (time < 0)
        errors = true;

    if (!errors)
        cout <<"You're a stud (at least on the example cases)!" <<endl;
    else
        cout <<"Some of the test cases had errors." <<endl;
}

