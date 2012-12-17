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

class WordParts {
    public:
        int partCount(string, string);
};
const int MAXN = 100;
int dp[MAXN][MAXN];
const int INF = 999999999;

void init(){
    for(int i=0; i<MAXN; i++){
        for(int j=0; j<MAXN; j++){
            dp[i][j] = INF;
        }
    }
}

bool is_pre(string s, string p){
    int sz = p.size();
    if(sz>s.size())return false;

    for(int i=0; i<sz; i++){
        if(p[i]==s[i])continue;
        return false;
    }
    return true;
}
bool is_sfx(string s, string e){
    int sz = e.size();
    int ptr = s.size()-1;
    int ptr_e = sz-1;
    
    if(sz>s.size()){
        return false;
    }

    while( s[ptr]==e[ptr_e]){
        ptr--, ptr_e--;
    }
    if(ptr_e<0){
        return true;
    }else{
        return false;
    }
}

int WordParts::partCount(string original, string compound) {
    init();
    int sz = compound.size();
    for(int i=0; i<sz; i++){
        for(int j=1; j<=sz; j++){
            if(i+j-1>=sz)continue;
            string t = compound.substr(i, j);
            //check compound[i,i+j-1] is pre or end
            
            size_t found = original.find(t);
            if(is_pre(original, t) || is_sfx(original, t) ){
                //cout<<"sub "<<i<<" "<<j<<" is "<<t<<" and this is a pre or suf"<<endl;;
                dp[i][i+j-1] = 1;
                //cout<<"dp["<<i<<"]["<<i+j-1<<"] = 1"<<endl;
            }
        }
    }

    for(int len = 1; len<=sz; len++){
        for(int i=0; i<sz; i++){
            if(i+len>=sz)continue;
            for(int k=i; k+1<=i+len; k++){
                //cout<<"checking ["<<i<<"]["<<k<<"]  ["<<k+1<<"]["<<i+len<<"]"<<endl;
                dp[i][i+len] = min(dp[i][k]+dp[k+1][i+len], dp[i][i+len]);
            }
        }
    }
    if(dp[0][sz-1]==INF){
        return -1;
    }
    return dp[0][sz-1];
}
double test0() {
    string p0 = "ANTIDISESTABLISHMENTARIANISM";
    string p1 = "ANTIDISIANISMISM";
    WordParts * obj = new WordParts();
    clock_t start = clock();
    int my_answer = obj->partCount(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p2 = 3;
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
    string p0 = "ANTIDISESTABLISHMENTARIANISM";
    string p1 = "ESTABLISHMENT";
    WordParts * obj = new WordParts();
    clock_t start = clock();
    int my_answer = obj->partCount(p0, p1);
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
double test2() {
    string p0 = "TOPCODERDOTCOM";
    string p1 = "TOMTMODERDOTCOM";
    WordParts * obj = new WordParts();
    clock_t start = clock();
    int my_answer = obj->partCount(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p2 = 5;
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
    string p0 = "HELLO";
    string p1 = "HELLOHEHELLOLOHELLO";
    WordParts * obj = new WordParts();
    clock_t start = clock();
    int my_answer = obj->partCount(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p2 = 5;
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
    string p0 = "DONTFORGETTHEEMPTYCASE";
    string p1 = "";
    WordParts * obj = new WordParts();
    clock_t start = clock();
    int my_answer = obj->partCount(p0, p1);
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
double test5() {
    string p0 = "BAAABA";
    string p1 = "BAAABAAA";
    WordParts * obj = new WordParts();
    clock_t start = clock();
    int my_answer = obj->partCount(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p2 = 2;
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
double test6() {
    string p0 = "ABBBAABABBBAABBABBABABBABAABBAABBBBBABBABABBABAABB";
    string p1 = "BBBAABABBBAABBABBABABBABAABBAABBBBBABBABABBABAABAA";
    WordParts * obj = new WordParts();
    clock_t start = clock();
    int my_answer = obj->partCount(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p2 = 17;
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

    time = test5();
    if (time < 0)
        errors = true;

    time = test6();
    if (time < 0)
        errors = true;

    if (!errors)
        cout <<"You're a stud (at least on the example cases)!" <<endl;
    else
        cout <<"Some of the test cases had errors." <<endl;
}

