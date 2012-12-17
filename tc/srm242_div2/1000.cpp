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

class NumberSplit {
    public:
        int longestSequence(int);
};

vector <int> to_vector(int s){
    vector<int> t;
    while(s){
        t.push_back(s%10);
        s/=10;
    }
    reverse(t.begin(), t.end());
    return t;
}

int to_int(vector<int> &t, int i, int j){
    int sum = 0;
    for(int k=i; k<=j; k++){
        sum = sum*10+t[k];
    }
    return sum;
}
const int MAXN = 100001;
const int INF = 999999999;
int dp[MAXN];

vector<int> tmp;
void generator(vector<int> &s, int all, int pos, int pre, int sz){
    if(sz==pos){
        tmp.push_back(all);
        return ;
    }
    int yes = pre*10+s[pos];
    int no = s[pos];
    generator(s, all ,pos+1, yes, sz);
    generator(s, all*pre, pos+1, no, sz);
}


int dfs(int s){
    if(s>=0 && s<10){
        return 1;
    }
    if(dp[s]!=-1){
        return dp[s];
    }
    vector<int> t = to_vector(s);
    int sz = t.size();
    int t_max = -INF;
    
    for(int i=0; i<sz-1; i++){
        int left = to_int(t, 0, i);
        int right = to_int(t, i+1, sz-1);
        int product = left*right;
        int len = dfs(product)+1;
        t_max = max(t_max, len);
    }
    dp[s] = t_max;
    return dp[s];
}

int NumberSplit::longestSequence(int start) {
    memset(dp,-1,sizeof(dp));
    //vector<int> s = to_vector(start);
    vector<int> tt = to_vector(start);
    generator(tt, tt[0] ,1, tt[0], tt.size());
    for(int i=0; i<tt.size(); i++){
        cout<<tt[i]<<" ";
    }cout<<endl;
    return 1;
    int ans = dfs(start);
    return ans;
}
double test0() {
    int p0 = 6;
    NumberSplit * obj = new NumberSplit();
    clock_t start = clock();
    int my_answer = obj->longestSequence(p0);
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
double test1() {
    int p0 = 97;
    NumberSplit * obj = new NumberSplit();
    clock_t start = clock();
    int my_answer = obj->longestSequence(p0);
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
    int p0 = 234;
    NumberSplit * obj = new NumberSplit();
    clock_t start = clock();
    int my_answer = obj->longestSequence(p0);
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
double test3() {
    int p0 = 876;
    NumberSplit * obj = new NumberSplit();
    clock_t start = clock();
    int my_answer = obj->longestSequence(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p1 = 7;
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
    int p0 = 99999;
    NumberSplit * obj = new NumberSplit();
    clock_t start = clock();
    int my_answer = obj->longestSequence(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p1 = 29;
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

