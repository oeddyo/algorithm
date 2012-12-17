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

class TakeSubstringGame {
    public:
        int winningMove(int);
};

int g_len = 0;

int tens[] = {1,10,100,1000,10000,100000,1000000,1000000};
const int MAXN = 1000001;
int win[MAXN], ans;
int g_n;
bool get_win(int number){
    if(number<=0){
        return false;
    }
    if( win[number]!=-1){return win[number];}
    bool ok = false; 
    for(int i=0; i<g_len; i++){
        for(int j=i; j<g_len; j++){
            int t_sum = 0;
            int tmp = number/(tens[i]);
            for(int k=j; k>=i; k--){
                //t_sum = t_sum*10+tmp%10;
                t_sum = (number/tens[k])%10 + t_sum*10;
                //tmp/=10;
            }
            if(t_sum>0 && t_sum<number){
                    
                //cout<<"from "<<number<<" to "<<number-t_sum<<" "<<t_sum<<" "<<endl;
                if(!get_win(number - t_sum) ){
                    ok = true;
                    if(g_n==number && t_sum<ans){
                        ans = t_sum;
                    }
                }
            }
        }
    }
    if(ok){
        win[number] = true;
        return true;
    }
    win[number] = false;
    return false;
}



int TakeSubstringGame::winningMove(int n) {
    g_n = n;
    memset(win,-1,sizeof(win));
    int t_n = n;
    g_len = 0;
    while(t_n>0){
        t_n/=10;
        g_len++;
    }
    ans = 100000000;
    bool ok = get_win(n);
    if(ok){
        return ans;
    }else{
        return -1;
    }
}
double test0() {
    int p0 = 5;
    TakeSubstringGame * obj = new TakeSubstringGame();
    clock_t start = clock();
    int my_answer = obj->winningMove(p0);
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
double test1() {
    int p0 = 10;
    TakeSubstringGame * obj = new TakeSubstringGame();
    clock_t start = clock();
    int my_answer = obj->winningMove(p0);
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
    int p0 = 17;
    TakeSubstringGame * obj = new TakeSubstringGame();
    clock_t start = clock();
    int my_answer = obj->winningMove(p0);
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
double test3() {
    int p0 = 239;
    TakeSubstringGame * obj = new TakeSubstringGame();
    clock_t start = clock();
    int my_answer = obj->winningMove(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p1 = 9;
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
    int p0 = 566;
    TakeSubstringGame * obj = new TakeSubstringGame();
    clock_t start = clock();
    int my_answer = obj->winningMove(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p1 = 66;
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
double test5() {
    int p0 = 23900;
    TakeSubstringGame * obj = new TakeSubstringGame();
    clock_t start = clock();
    int my_answer = obj->winningMove(p0);
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

    if (!errors)
        cout <<"You're a stud (at least on the example cases)!" <<endl;
    else
        cout <<"Some of the test cases had errors." <<endl;
}

