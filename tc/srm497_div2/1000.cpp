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

class MakeSquare {
    public:
        int minChanges(string);
};
const int MAXN = 51;
int dp[MAXN][MAXN];
int sz;
const int INF = 999999999;
string g_S;

void init(){
    for(int i=0; i<MAXN; i++)for(int j=0; j<MAXN; j++)dp[i][j] = INF;
}


int edit_dis(string s1, string s2){
    init();
    s1 = " "+s1;
    s2 = " "+s2;
    cout<<"s1 s2 "<<endl;
    cout<<s1<<endl;
    cout<<s2<<endl;
    for(int i=0; i<MAXN; i++){
        dp[0][i] = dp[i][0] = i;
    }
    dp[0][0] = 0;
    int sz1 = s1.size();
    int sz2 = s2.size();
    for(int i=1; i<=sz1; i++){
        for(int j=1; j<=sz2; j++){
            if(s1[i]==s2[j]){
                dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
            }else{
                int t = dp[i-1][j]+1;
                t = min(t, dp[i][j-1]+1);
                t = min(t, dp[i-1][j-1]+1);
                dp[i][j] = t;
            }
        }
    }
    return dp[s1.size()-1][s2.size()-1];
}

int MakeSquare::minChanges(string S) {
    int sz = S.size(), ans;
    ans = INF;
    for(int i=0; i<sz; i++){
        ans = min(edit_dis( S.substr(0, i), S.substr(i, (sz-i))), ans);
    }
    return ans;
}
double test0() {
    string p0 = "qetuoadgjlzcbmqwertyuiopasdfghjklzxcvbnm";
    MakeSquare * obj = new MakeSquare();
    clock_t start = clock();
    int my_answer = obj->minChanges(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p1 = 12;
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
    string p0 = "abcdeabce";
    MakeSquare * obj = new MakeSquare();
    clock_t start = clock();
    int my_answer = obj->minChanges(p0);
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
double test2() {
    string p0 = "abcdeabxde";
    MakeSquare * obj = new MakeSquare();
    clock_t start = clock();
    int my_answer = obj->minChanges(p0);
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
double test3() {
    string p0 = "aabcaabc";
    MakeSquare * obj = new MakeSquare();
    clock_t start = clock();
    int my_answer = obj->minChanges(p0);
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
double test4() {
    string p0 = "aaaaabaaaaabaaaaa";
    MakeSquare * obj = new MakeSquare();
    clock_t start = clock();
    int my_answer = obj->minChanges(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p1 = 2;
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

