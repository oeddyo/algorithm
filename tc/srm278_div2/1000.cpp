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

class IntegerSequence {
    public:
        int maxSubsequence(vector <int>);
};

const int MAXN = 51;
int dp_des[MAXN];
int dp_asc[MAXN];

int IntegerSequence::maxSubsequence(vector <int> numbers) {
    int sz = numbers.size();
    for(int i=0; i<MAXN; i++){
        dp_des[i] = dp_asc[i] = 1;
    }

    for(int i=0; i<sz; i++){
        for(int j=0; j<i; j++){
            if(numbers[i]>numbers[j]){
                dp_asc[i] = max(dp_asc[i], dp_asc[j]+1);
            }
        }
    }

    for(int i=sz-1;i>=0; i--){
        for(int j=sz-1; j>i; j--){
            if(numbers[i]>numbers[j]){
                dp_des[i] = max(dp_des[i], dp_des[j]+1);
            }
        }
    }

    int ans = -1;
    for(int i=0; i<sz; i++){
        cout<<"dp_asc["<<i<<"] = "<<dp_asc[i]<<endl;
        cout<<"dp_des["<<i<<"] = "<<dp_des[i]<<endl;
        ans = max(ans, dp_asc[i] + dp_des[i]-1);
    }
    return sz - ans;
}
double test0() {
    int t0[] = {1, 4, 6, 5, 2, 1};
    vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
    IntegerSequence * obj = new IntegerSequence();
    clock_t start = clock();
    int my_answer = obj->maxSubsequence(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p1 = 0;
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
    int t0[] = {1, 2, 1, 2, 3, 2, 1, 2, 1};
    vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
    IntegerSequence * obj = new IntegerSequence();
    clock_t start = clock();
    int my_answer = obj->maxSubsequence(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p1 = 4;
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
    int t0[] = {2, 2, 2, 2, 2};
    vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
    IntegerSequence * obj = new IntegerSequence();
    clock_t start = clock();
    int my_answer = obj->maxSubsequence(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p1 = 4;
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
    int t0[] = {4,5,65,34,786,45678,987,543,2,6,98,580,4326,754,54,2,1,3,5,6,8,765,43,3,54};
    vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
    IntegerSequence * obj = new IntegerSequence();
    clock_t start = clock();
    int my_answer = obj->maxSubsequence(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p1 = 14;
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

