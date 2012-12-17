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

class IncreasingSubsequences {
    public:
        long long count(vector <int>);
};

const int MAXN = 100;
long long int dp[MAXN];
long long int lis_dp[MAXN];
//const long long int INF = (1<<62);
const int INF = 99999999;
long long IncreasingSubsequences::count(vector <int> a) {
    int sz = a.size();
    for(int i=0; i<MAXN; i++)lis_dp[i] = 1;
    for(int i=0; i<sz; i++){
        for(int j=0; j<i; j++){
            if(a[i]>a[j])
            {
                lis_dp[i] = max(lis_dp[j]+1, lis_dp[i]);
            }
        }
        cout<<"lis["<<i<<"] = "<<lis_dp[i]<<" "<<a[i]<<endl;
    }
    memset(dp,0,sizeof(dp));
    for(int i=0; i<MAXN; i++){
        if(lis_dp[i]==1){
            dp[i] = 1;
        }
    }
    for(int i=0; i<sz; i++){
        int should_be = lis_dp[i]-1;
        for(int j=0; j<i; j++){
            if(lis_dp[j]==should_be && a[i]>a[j]){
                dp[i] += dp[j];
            }
        }
    }

    long long int sum = 0;
    for(int i=0; i<sz; i++){
        cout<<"dp["<<i<<"] = "<<dp[i]<<" "<<a[i];
        bool none_bigger = true;
        for(int j=i+1; j<sz; j++){
            if(a[j]>a[i]){
                none_bigger = false;
                break;
            }
        }
        if(none_bigger){
            sum+=dp[i];
            cout<<"-> "<<dp[i]<<endl;
        }else{
            cout<<endl;
        }
    }
    return sum;
}
double test0() {
    int t0[] = {1,3,2,6,4,5};
    vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
    IncreasingSubsequences * obj = new IncreasingSubsequences();
    clock_t start = clock();
    long long my_answer = obj->count(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    long long p1 = 4LL;
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
    int t0[] = {1000000000,100000000,10000000,1000000,100000,10000,1000,100,10,1};
    vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
    IncreasingSubsequences * obj = new IncreasingSubsequences();
    clock_t start = clock();
    long long my_answer = obj->count(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    long long p1 = 10LL;
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
    int t0[] = {1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
    vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
    IncreasingSubsequences * obj = new IncreasingSubsequences();
    clock_t start = clock();
    long long my_answer = obj->count(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    long long p1 = 1LL;
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
double test3() {
    int t0[] = {564,234,34,4365,424,2234,306,21,934,592,195,2395,2396,29345,13295423,23945,2};
    vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
    IncreasingSubsequences * obj = new IncreasingSubsequences();
    clock_t start = clock();
    long long my_answer = obj->count(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    long long p1 = 41LL;
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

    time = test3();
    if (time < 0)
        errors = true;

    if (!errors)
        cout <<"You're a stud (at least on the example cases)!" <<endl;
    else
        cout <<"Some of the test cases had errors." <<endl;
}

