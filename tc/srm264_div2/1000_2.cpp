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

class SetMetric {
    public:
        int nearness(vector <int>, vector <int>);
};

const int MAXN = 21;
const int MAXS = 1<<MAXN;
int dp[1<<MAXN];
const int INF = 999999999;
int SetMetric::nearness(vector <int> target, vector <int> candidate) {
    for(int s=0; s<MAXS; s++)dp[s] = INF;
    
    dp[0] = 0;
    int sz = candidate.size();
    int t_sz = target.size();
    sort(target.begin(), target.end());
    sort(candidate.begin(), candidate.end());
    int ans = INF;
    for(int s=0; s<(1<<sz); s++){
        if(__builtin_popcount(s)==t_sz){
            int sum = 0;
            int t_idx = t_sz-1;
            int c_idx = sz-1;
            int ts = s;
            while(ts){
                if((1&ts)==1){
                    sum += abs(target[t_idx] - candidate[c_idx]);
                    t_idx--;c_idx--;
                }else{
                    c_idx--;
                }
                ts>>=1;
            }
            ans = min(ans, sum);
        }
    }
    return ans;
}

double test0() {
    int t0[] = {4,9,2,1};
    vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
    int t1[] = {9,1,2,3,5,6};
    vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
    SetMetric * obj = new SetMetric();
    clock_t start = clock();
    int my_answer = obj->nearness(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p2 = 1;
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
    int t0[] = {3,33,333};
    vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
    int t1[] = {33,333,3,32};
    vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
    SetMetric * obj = new SetMetric();
    clock_t start = clock();
    int my_answer = obj->nearness(p0, p1);
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
double test2() {
    int t0[] = {1000,-1000,0,5,289,-40};
    vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
    int t1[] = {30,821,-777,-52,91,444,-134,85};
    vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
    SetMetric * obj = new SetMetric();
    clock_t start = clock();
    int my_answer = obj->nearness(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p2 = 679;
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

    if (!errors)
        cout <<"You're a stud (at least on the example cases)!" <<endl;
    else
        cout <<"Some of the test cases had errors." <<endl;
}

