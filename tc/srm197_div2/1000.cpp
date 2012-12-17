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

class QuickSums {
    public:
        int minSums(string, int);
};

const int MAXN  = 11;
int sums[MAXN][MAXN];

int get_value(int i, int j, string numbers){
    int v = 0;
    for(int k=i; k<=j; k++){
        v = v*10+numbers[k]-'0';
    }
    return v;
}

int target;
int ans;
int num[MAXN], sz;
void dfs(int cur, int sum, int t_sum, int plus){
    if(cur==sz){
        //sum+=t_sum;
        cout<<"at "<<cur<<" and sum "<<sum<<" t_sum "<<t_sum<<endl;
        if(sum+t_sum==target){
            ans = min(plus, ans);
        }
        return ;
    }
    //plus
    dfs(cur+1, sum+t_sum, num[cur], plus+1);
    //no plus
    dfs(cur+1, sum, t_sum*10+num[cur], plus);
}
const int INF = 999999999;
int QuickSums::minSums(string numbers, int sum) {
    /*for(int i=0; i<numbers.size(); i++){
        for(int j=i; j<numbers.size(); j++){
            sums[i][j] = get_value(i,j,numbers);
        }
    }*/
    sz = numbers.size();
    for(int i=0; i<numbers.size(); i++){
        num[i] = numbers[i]-'0';
    }
    target = sum;
    ans = INF;
    dfs(1, 0, num[0], 0);
    if(ans==INF)return -1;
    return ans;
}
double test0() {
    string p0 = "99999";
    int p1 = 45;
    QuickSums * obj = new QuickSums();
    clock_t start = clock();
    int my_answer = obj->minSums(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p2 = 4;
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
    string p0 = "1110";
    int p1 = 3;
    QuickSums * obj = new QuickSums();
    clock_t start = clock();
    int my_answer = obj->minSums(p0, p1);
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
double test2() {
    string p0 = "0123456789";
    int p1 = 45;
    QuickSums * obj = new QuickSums();
    clock_t start = clock();
    int my_answer = obj->minSums(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p2 = 8;
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
    string p0 = "99999";
    int p1 = 100;
    QuickSums * obj = new QuickSums();
    clock_t start = clock();
    int my_answer = obj->minSums(p0, p1);
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
    string p0 = "382834";
    int p1 = 100;
    QuickSums * obj = new QuickSums();
    clock_t start = clock();
    int my_answer = obj->minSums(p0, p1);
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
double test5() {
    string p0 = "9230560001";
    int p1 = 71;
    QuickSums * obj = new QuickSums();
    clock_t start = clock();
    int my_answer = obj->minSums(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p2 = 4;
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

    if (!errors)
        cout <<"You're a stud (at least on the example cases)!" <<endl;
    else
        cout <<"Some of the test cases had errors." <<endl;
}

