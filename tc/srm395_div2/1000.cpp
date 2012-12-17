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

class TriviaGame {
    public:
        int maximumScore(vector <int>, int, vector <int>);
};

const int MAXN = 52;
const int INF = 999999999;
int dp[MAXN][MAXN];

int TriviaGame::maximumScore(vector <int> points, int tokensNeeded, vector <int> bonuses) {
    for(int i=0; i<MAXN; i++)for(int j=0; j<MAXN; j++)dp[i][j]=-INF;
    
    int sz = points.size();
    dp[0][0] = 0;

    for(int i=0; i<sz; i++){
        for(int j=0; j<=i; j++){
            if(dp[i][j]!=INF){
                cout<<"dp["<<i<<"]["<<j<<"] = "<<dp[i][j]<<endl;
                if(j+1==tokensNeeded){
                    dp[i+1][0] = max(dp[i][j]+bonuses[i]+points[i], dp[i+1][0]);
                }else{
                    dp[i+1][j+1] = max(dp[i][j]+points[i], dp[i+1][j+1]);
                }
                dp[i+1][j] = max(dp[i+1][j], dp[i][j] - points[i]);
            }
        }
    }
    int ans = -INF;
    for(int i=0; i<=sz; i++){
        ans = max(ans,dp[sz][i]);
    }
    return ans;
}
double test0() {
    int t0[] = {1, 2, 3, 4, 5, 6};
    vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
    int p1 = 3;
    int t2[] = {4, 4, 4, 4, 4, 4};
    vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
    TriviaGame * obj = new TriviaGame();
    clock_t start = clock();
    int my_answer = obj->maximumScore(p0, p1, p2);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p3 = 29;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p3 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p3 != my_answer) {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
double test1() {
    int t0[] = {1, 2, 3, 4, 5, 6};
    vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
    int p1 = 3;
    int t2[] = {1, 1, 1, 20, 1, 1};
    vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
    TriviaGame * obj = new TriviaGame();
    clock_t start = clock();
    int my_answer = obj->maximumScore(p0, p1, p2);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p3 = 39;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p3 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p3 != my_answer) {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
double test2() {
    int t0[] = {150, 20, 30, 40, 50};
    vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
    int p1 = 3;
    int t2[] = {0, 0, 0, 250, 0};
    vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
    TriviaGame * obj = new TriviaGame();
    clock_t start = clock();
    int my_answer = obj->maximumScore(p0, p1, p2);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p3 = 500;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p3 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p3 != my_answer) {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
double test3() {
    int t0[] = {500, 500, 500, 0, 500};
    vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
    int p1 = 3;
    int t2[] = {0, 0, 0, 500, 0};
    vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
    TriviaGame * obj = new TriviaGame();
    clock_t start = clock();
    int my_answer = obj->maximumScore(p0, p1, p2);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p3 = 2000;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p3 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p3 != my_answer) {
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

