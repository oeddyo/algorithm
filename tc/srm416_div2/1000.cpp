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

class DancingCouples {
    public:
        int countPairs(vector <string>, int);
};

const int MAXN = 13;
const int MAXS = 1<<13;
int dp[MAXN][MAXS];

int DancingCouples::countPairs(vector <string> canDance, int K) {
    memset(dp,0,sizeof(dp));
    dp[0][0] = 1;
    int sz_boy = canDance.size();
    int sz_girl = canDance[0].size();
    for(int i=0; i<sz_boy; i++){
        for(int s=0; s<(1<<sz_girl); s++){
            for(int j=0; j<sz_girl; j++){
                if( ((s>>j)&1)==1 )continue;
                if(canDance[i][j]=='N')continue;
                int ns = (1<<j)|s;
                dp[i+1][ns] += dp[i][s];
            }
            dp[i+1][s] += dp[i][s];
        }
    }
    int ans = 0;
    for(int s=0; s<(1<<sz_girl); s++){
        if(__builtin_popcount(s)==K){
            ans+=dp[sz_boy][s];
        }
    }
    return ans;
}
double test0() {
    string t0[] = {"YYYY", 
        "YYYY",
        "YYYY"};
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    int p1 = 3;
    DancingCouples * obj = new DancingCouples();
    clock_t start = clock();
    int my_answer = obj->countPairs(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p2 = 24;
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
    string t0[] = {"YYNN", 
        "NYYN", 
        "NNYY"};
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    int p1 = 3;
    DancingCouples * obj = new DancingCouples();
    clock_t start = clock();
    int my_answer = obj->countPairs(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p2 = 4;
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
    string t0[] = {"YY", 
        "YY", 
        "YY"};
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    int p1 = 3;
    DancingCouples * obj = new DancingCouples();
    clock_t start = clock();
    int my_answer = obj->countPairs(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p2 = 0;
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
    string t0[] = {"YYNNNN",
        "NYYNNN",
        "NNYYNN",
        "NNNYYN",
        "NNNNYY",
        "YNNNNY"};
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    int p1 = 3;
    DancingCouples * obj = new DancingCouples();
    clock_t start = clock();
    int my_answer = obj->countPairs(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p2 = 112;
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

