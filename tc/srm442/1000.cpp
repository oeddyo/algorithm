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

class EqualTowers {
    public:
        int height(vector <int>);
};
const int MAXN = 500001;
bool dp[MAXN];

int EqualTowers::height(vector <int> bricks) {
    memset(dp,0,sizeof(dp));
    dp[0] = 1;
    int sum = 0;
    for(int i=0; i<bricks.size(); i++)sum+=bricks[i];

    for(int i=0; i<bricks.size(); i++){
        for(int j=sum; j>=0; j--){
            if( j-bricks[i]>=0){
                if( dp[j-bricks[i]] == 1){
                    if(j==140){
                        cout<<"j = 140 bricks[i] = "<<bricks[i]<<" dp[j-bricks[i]= "<<dp[j-bricks[i]]   <<endl;
                    }
                    dp[j] = 1;
                }
            }
        }
    }
    int ans = -1;
    int sz = bricks.size();
    for(int i=1; i<=sum; i++){
        if(i%2==0 && dp[i]==1 && dp[i/2]==1){
        cout<<"dp["<<i<<"] = "<<dp[i]<<endl;
            ans = i;
        }
    }
    if(ans==-1)return -1;
    return ans/2;
}
double test0() {
    int t0[] = { 2, 3, 5 };
    vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
    EqualTowers * obj = new EqualTowers();
    clock_t start = clock();
    int my_answer = obj->height(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p1 = 5;
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
    int t0[] = { 10, 9, 2 };
    vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
    EqualTowers * obj = new EqualTowers();
    clock_t start = clock();
    int my_answer = obj->height(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p1 = -1;
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
    int t0[] = { 11, 11 };
    vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
    EqualTowers * obj = new EqualTowers();
    clock_t start = clock();
    int my_answer = obj->height(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p1 = 11;
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
    int t0[] = { 14, 3, 20, 15, 15, 14, 24, 23, 15 };
    vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
    EqualTowers * obj = new EqualTowers();
    clock_t start = clock();
    int my_answer = obj->height(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p1 = 64;
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

