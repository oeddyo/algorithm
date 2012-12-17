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

class SRMSystemTestPhase {
    public:
        int countWays(vector <string>);
};

const int MAXN = 51;
//int dp[MAXN][3][3][3];
//yes, challenge
int dp[MAXN][3][3];
int count_Y(string s){
    int sum=0;
    for(int i=0; i<s.size(); i++){
        if(s[i]=='Y')sum++;
    }
    return sum;
}

int SRMSystemTestPhase::countWays(vector <string> description) {
    memset(dp,0,sizeof(dp));
    int y = count_Y(description[0]);
    for(int yes=0; yes<=y; yes++){
        int cha = y-yes;
        dp[0][yes][cha] = 1;
    }
    for(int i=0; i<description.size()-1; i++){
        int cnt_Y = count_Y(description[i]);
        for(int yes=0; yes<=cnt_Y; yes++){
            int cha = cnt_Y - yes;
            dp[i+1][yes][cha] += dp[i][yes][cha];
            if( yes >= 1){
                dp[i+1][yes-1][cha+1] += dp[i][yes][cha];
                dp[i+1][yes-1][cha] += dp[i][yes][cha];
            }
        }
    }
    
    int cnt_y = count_Y(description[ description.size()-1]);
    int sum = 0;
    for(int yes=0; yes<=cnt_y; yes++){
        int cha = cnt_y - yes;
        sum+=dp[description.size()-1][yes][cha];

    }
    return sum;
}
double test0() {
    string t0[] = {"YYY"};
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    SRMSystemTestPhase * obj = new SRMSystemTestPhase();
    clock_t start = clock();
    int my_answer = obj->countWays(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p1 = 27;
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
    string t0[] = {"YNN",
        "NYN"};
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    SRMSystemTestPhase * obj = new SRMSystemTestPhase();
    clock_t start = clock();
    int my_answer = obj->countWays(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p1 = 6;
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
    string t0[] = {"YNN",
        "NNN",
        "NNY"};
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    SRMSystemTestPhase * obj = new SRMSystemTestPhase();
    clock_t start = clock();
    int my_answer = obj->countWays(p0);
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
    string t0[] = {"NNN",
        "NNN"};
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    SRMSystemTestPhase * obj = new SRMSystemTestPhase();
    clock_t start = clock();
    int my_answer = obj->countWays(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p1 = 1;
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
double test4() {
    string t0[] = {"YYY",
        "YNY",
        "NYY",
        "YYN",
        "YYY",
        "YNN"};
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    SRMSystemTestPhase * obj = new SRMSystemTestPhase();
    clock_t start = clock();
    int my_answer = obj->countWays(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p1 = 15176;
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

    time = test4();
    if (time < 0)
        errors = true;

    if (!errors)
        cout <<"You're a stud (at least on the example cases)!" <<endl;
    else
        cout <<"Some of the test cases had errors." <<endl;
}

