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

class ParallelProgramming {
    public:
        int minTime(vector <int>, vector <string>);
};


const int MAXN = 51;
int N;
int visited[MAXN];
bool ok = true;
vector <string> g;
int ans;
vector<int> numbers;
int num[MAXN];
int dp[MAXN];

const int INF = 999999999;

bool loop(int cur){
    visited[cur] = 1;
    bool t_ok = true;
    for(int i=0; i<N; i++){
        if(g[cur][i]=='Y' ){
            if(visited[i]==1){
                return false;
            }else if(visited[i]==0){
                 if(!loop(i)){
                     t_ok = false;
                 }
            }
        }
    }
    visited[cur] = 2;
    return t_ok;
}


int dfs(int cur){
    cout<<"at "<<cur<<endl;
    if(dp[cur]!=-1){
        return dp[cur];
    }
    int t_max = -INF;
    for(int i=0; i<N; i++){
        if(g[cur][i]=='Y' ){
            t_max = max(t_max, dfs(i));
        }
    }
    if(t_max==-INF){
        return numbers[cur];
    }
    dp[cur] = t_max+numbers[cur];
    return dp[cur];
}



int ParallelProgramming::minTime(vector <int> time, vector <string> prec) {
    N = time.size();
    g = prec;
    numbers = time;
    ans = -INF;
    ok = true;
    
    for(int i=0; i<N; i++){
        memset(visited,0,sizeof(visited));
        if(loop(i)==false){
            return -1;
        }
    }
    cout<<"ok"<<endl;
    for(int i=0; i<N; i++){
        memset(dp,-1,sizeof(dp));
        cout<<"start at "<<i<<" res is "<<dfs(i)<<endl;
        ans =max(ans, dfs(i));
    }
    return ans;
}
double test0() {
    //int t0[] = {150,200,250};
    int t0[] = {24, 117, 992, 911, 128, 952, 940, 13, 198, 254, 774, 459, 179, 155, 847, 686, 2, 237};
    string t1[] = {"NNNNNNYNNNNNNNNNYN", "NNNNNNYNNNNYNYNNNN", "NNNNNNNNNNNNNNNNYY", "YNNNNNYNYYYNNNNNYN", "NNNNNNNNYNNNNNNNNN", "NNNNNNNNYNNNNNNNNN", "NNNNYNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNN", "NNYNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNYNNN", "NNNNNNNNNNNNNNNNNY", "NNNNNNNYNNNNNYNNYY", "NNNNNNNNNNNNNNNNYN", "NNNYNNNYNYNYYNNNNY", "NNNNYNNNNNNYNNNNYN", "NNNNNNNNNNYNNNNNNN", "NNNNNNNNNNNNNNNNNN"};
    vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
    //string t1[] = {"NNN",
    //    "NNN",
    //    "NNN"};
    vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
    ParallelProgramming * obj = new ParallelProgramming();
    clock_t start = clock();
    int my_answer = obj->minTime(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p2 = -1;
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
    int t0[] = {150,200,250};
    vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
    string t1[] = {"NNN",
        "YNN",
        "NNN"};
    vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
    ParallelProgramming * obj = new ParallelProgramming();
    clock_t start = clock();
    int my_answer = obj->minTime(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p2 = 350;
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
    int t0[] = {150,200,250};
    vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
    string t1[] = {"NYN",
        "NNY",
        "NNN"};
    vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
    ParallelProgramming * obj = new ParallelProgramming();
    clock_t start = clock();
    int my_answer = obj->minTime(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p2 = 600;
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
    int t0[] = {150,200,250};
    vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
    string t1[] = {"NYN",
        "NNY",
        "YNN"};
    vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
    ParallelProgramming * obj = new ParallelProgramming();
    clock_t start = clock();
    int my_answer = obj->minTime(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p2 = -1;
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
double test4() {
    int t0[] = {345,335,325,350,321,620};
    vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
    string t1[] = {"NNNNNN",
        "NNYYYY",
        "YNNNNN",
        "NNYNYN",
        "NNNNNN",
        "NNNNNN"};
    vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
    ParallelProgramming * obj = new ParallelProgramming();
    clock_t start = clock();
    int my_answer = obj->minTime(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p2 = 1355;
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
    time = test4();
    if (time < 0)
        errors = true;

    if (!errors)
        cout <<"You're a stud (at least on the example cases)!" <<endl;
    else
        cout <<"Some of the test cases had errors." <<endl;
}

