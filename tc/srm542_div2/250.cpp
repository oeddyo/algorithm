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

class WorkingRabbits {
    public:
        double getEfficiency(vector <string>);
};

double WorkingRabbits::getEfficiency(vector <string> profit) {
    int sz = profit.size();
    int sum = 0;
    int pair = sz*(sz-1);
    for(int i=0; i<sz; i++){
        for(int j=0; j<sz;j ++){
            sum+=profit[i][j]-'0';
        }
    }
    double ans;
    if(pair==0){
        ans = 0.0;
    }else{
        ans = (double)sum/(double)pair;
    }
    return ans;
}

double test0() {
    string t0[] = { "071", 
        "702", 
        "120" }
    ;
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    WorkingRabbits * obj = new WorkingRabbits();
    clock_t start = clock();
    double my_answer = obj->getEfficiency(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    double p1 = 3.3333333333333335;
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
    string t0[] = { "00", 
        "00" }
    ;
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    WorkingRabbits * obj = new WorkingRabbits();
    clock_t start = clock();
    double my_answer = obj->getEfficiency(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    double p1 = 0.0;
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
    string t0[] = { "0999", 
        "9099", 
        "9909", 
        "9990" }
    ;
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    WorkingRabbits * obj = new WorkingRabbits();
    clock_t start = clock();
    double my_answer = obj->getEfficiency(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    double p1 = 9.0;
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
    string t0[] = { "013040", 
        "100010", 
        "300060", 
        "000008", 
        "416000", 
        "000800" }
    ;
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    WorkingRabbits * obj = new WorkingRabbits();
    clock_t start = clock();
    double my_answer = obj->getEfficiency(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    double p1 = 1.5333333333333334;
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
    string t0[] = { "06390061", 
        "60960062", 
        "39090270", 
        "96900262", 
        "00000212", 
        "00222026", 
        "66761201", 
        "12022610" }
    ;
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    WorkingRabbits * obj = new WorkingRabbits();
    clock_t start = clock();
    double my_answer = obj->getEfficiency(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    double p1 = 3.2142857142857144;
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

