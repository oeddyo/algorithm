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

class TableSeating {
    public:
        double getExpected(int, vector <int>);
};

const int MAXN = 13;
double dp[1<<MAXN];
const double INF = 99999999;

bool check(int start, int num, int s){
    int end = start-num+1;
    if(end<0)return false;

    for(int i=start; i>=end; i--){
        if(((1<<i)&s)!=0){
            return false;
        }
    }
    return true;
}
int _set(int start, int num, int s){
    int t = s;
    //t = ((1<<num)-1)<<(start-num+1);
    int end = start-num+1;
    for(int i=start; i>=end; i--){
        s |= (1<<i);
    }
    return s;
}

double TableSeating::getExpected(int numTables, vector <int> probs) {
    for(int i=0; i<(1<<MAXN); i++)dp[i]=-0;
    int sz = probs.size();

    double ans = 0;
    dp[0] = 1.0;
    for(int s=0; s<(1<<numTables); s++){
        for(int i=0; i<sz; i++){
            int cnt = 0;
            int num = i+1;
            for(int j=numTables-1; j-num+1>=0; j--){
                if(check(j,num,s)){
                    cnt++;
                }
            }
            for(int j=numTables-1; j-num+1>=0; j--){
                if(check(j,num,s)){
                    int ns = _set(j,num, s);
                    if(cnt!=0){
                        dp[ns] += (1.0/cnt)*dp[s]*(probs[i]/100.0);
                    }
                }
            }
        }
    }
    /*for(int i=0; i<(1<<MAXN); i++){
        ans += dp[i]*__builtin_popcount(i);
    }*/
    return dp[(1<<numTables) - 1];
}
double test0() {
    int p0 = 4;
    int t1[] = {100};
    vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
    TableSeating * obj = new TableSeating();
    clock_t start = clock();
    double my_answer = obj->getExpected(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    double p2 = 4.0;
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
    int p0 = 4;
    int t1[] = {0,100};
    vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
    TableSeating * obj = new TableSeating();
    clock_t start = clock();
    double my_answer = obj->getExpected(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    double p2 = 3.3333333333333335;
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
    int p0 = 5;
    int t1[] = {0,0,0,0,0,50,50};
    vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
    TableSeating * obj = new TableSeating();
    clock_t start = clock();
    double my_answer = obj->getExpected(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    double p2 = 0.0;
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
    int p0 = 12;
    int t1[] = {9,9,9,9,9,9,9,9,9,9,10};
    vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
    TableSeating * obj = new TableSeating();
    clock_t start = clock();
    double my_answer = obj->getExpected(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    double p2 = 7.871087929710551;
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

