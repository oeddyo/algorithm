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

class AutoMarket {
    public:
        int maxSet(vector <int>, vector <int>, vector <int>);
};

typedef pair<int, int> pii;
typedef pair<int, pii> mypair;
vector< mypair > p;

const int MAXN = 52;
int dp[MAXN];

int AutoMarket::maxSet(vector <int> cost, vector <int> features, vector <int> fixTimes) {
    p.clear();
    int sz = cost.size();
    for(int i=0; i<sz; i++){
        p.push_back( mypair(cost[i], pii(features[i],fixTimes[i])) );
    }
    sort(p.begin(), p.end());

    for(int i=0; i<sz; i++){
        cout<<"data "<<i<<" "<<p[i].first<<" "<<p[i].second.first<<" "<<p[i].second.second<<endl;
    }
    for(int i=0; i<MAXN; i++){
        dp[i] = 1;
    }
    for(int i=1; i<sz; i++){
        for(int j=0; j<i; j++){
            if(p[j].second.first > p[i].second.first && p[j].second.second < p[i].second.second){
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }
    int ans = -1;
    for(int i=0; i<sz; i++){
        ans = max(ans, dp[i]);
    }
    return ans;
}
double test0() {
    int t0[] = {10000, 14000, 8000, 12000};
    vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
    int t1[] = {1, 2, 4, 3};
    vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
    int t2[] = {17, 15, 8, 11};
    vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
    AutoMarket * obj = new AutoMarket();
    clock_t start = clock();
    int my_answer = obj->maxSet(p0, p1, p2);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p3 = 3;
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
    int t0[] = {1,2,3,4,5};
    vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
    int t1[] = {1,2,3,4,5};
    vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
    int t2[] = {1,2,3,4,5};
    vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
    AutoMarket * obj = new AutoMarket();
    clock_t start = clock();
    int my_answer = obj->maxSet(p0, p1, p2);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p3 = 1;
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
    int t0[] = {9000, 6000, 5000, 5000, 7000};
    vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
    int t1[] = {1, 3, 4, 5, 2};
    vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
    int t2[] = {10, 6, 6, 5, 9};
    vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
    AutoMarket * obj = new AutoMarket();
    clock_t start = clock();
    int my_answer = obj->maxSet(p0, p1, p2);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p3 = 4;
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
    int t0[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
    int t1[] = {20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
    vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
    int t2[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
    AutoMarket * obj = new AutoMarket();
    clock_t start = clock();
    int my_answer = obj->maxSet(p0, p1, p2);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p3 = 20;
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
double test4() {
    int t0[] = {1000, 1000, 1000, 1000, 2000};
    vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
    int t1[] = {3,3,4,3,3};
    vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
    int t2[] = {3,3,3,4,3};
    vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
    AutoMarket * obj = new AutoMarket();
    clock_t start = clock();
    int my_answer = obj->maxSet(p0, p1, p2);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p3 = 1;
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

    time = test4();
    if (time < 0)
        errors = true;

    if (!errors)
        cout <<"You're a stud (at least on the example cases)!" <<endl;
    else
        cout <<"Some of the test cases had errors." <<endl;
}

