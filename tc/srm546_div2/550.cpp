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

class TwoRectangles {
    public:
        string describeIntersection(vector <int>, vector <int>);
};
const int MAXN = 1001;
int rec[MAXN][MAXN];
string TwoRectangles::describeIntersection(vector <int> A, vector <int> B) {
    memset(rec,0,sizeof(rec));
    for(int i=A[1]; i<=A[3]; i++){
        for(int j=A[0]; j<=A[2]; j++){
            rec[i][j]++;
            //cout<<"A "<<i<<" "<<j<<endl;
        }
    }
    for(int i=B[1]; i<=B[3]; i++){
        for(int j=B[0]; j<=B[2]; j++){
            rec[i][j]++;
            //cout<<"B "<<i<<" "<<j<<endl;
        }
    }
    bool first = false;
    int x_first, y_first, x_last, y_last;
    int lines;
    //int x_lines = 0;
    //int y_lines = 0;
    int all_count = 0;
    for(int i=0; i<MAXN; i++){
        int count = 0;
        for(int j=0; j<MAXN; j++){
            if(rec[i][j]==2){
                if(!first){
                    first = true;
                    x_first = i, y_first = j;
                }
                x_last = i, y_last = j;
                //cout<<"("<<i<<","<<j<<")"<<endl;
                count++;
                all_count++;
            }
        }
        if(count!=0){
            lines++;
        }
    }
    if(all_count==0){
        return "none";
    }
    if(all_count==1){
        return "point";
    }
    if(x_first==x_last || y_first==y_last){
        return "segment";
    }
    return "rectangle";
}
double test0() {
    int t0[] = {0,0,3,2};
    vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
    int t1[] = {1,1,5,3};
    vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
    TwoRectangles * obj = new TwoRectangles();
    clock_t start = clock();
    string my_answer = obj->describeIntersection(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    string p2 = "rectangle";
    cout <<"Desired answer: " <<endl;
    cout <<"\t\"" << p2 <<"\"" <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t\"" << my_answer<<"\"" <<endl;
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
    int t0[] = {0,0,5,3};
    vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
    int t1[] = {1,2,2,3};
    vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
    TwoRectangles * obj = new TwoRectangles();
    clock_t start = clock();
    string my_answer = obj->describeIntersection(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    string p2 = "rectangle";
    cout <<"Desired answer: " <<endl;
    cout <<"\t\"" << p2 <<"\"" <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t\"" << my_answer<<"\"" <<endl;
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
    int t0[] = {1,1,6,2};
    vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
    int t1[] = {3,2,5,4};
    vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
    TwoRectangles * obj = new TwoRectangles();
    clock_t start = clock();
    string my_answer = obj->describeIntersection(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    string p2 = "segment";
    cout <<"Desired answer: " <<endl;
    cout <<"\t\"" << p2 <<"\"" <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t\"" << my_answer<<"\"" <<endl;
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
    int t0[] = {0,1,2,3};
    vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
    int t1[] = {2,0,5,2};
    vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
    TwoRectangles * obj = new TwoRectangles();
    clock_t start = clock();
    string my_answer = obj->describeIntersection(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    string p2 = "segment";
    cout <<"Desired answer: " <<endl;
    cout <<"\t\"" << p2 <<"\"" <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t\"" << my_answer<<"\"" <<endl;
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
    int t0[] = {0,0,1,1};
    vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
    int t1[] = {1,1,5,2};
    vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
    TwoRectangles * obj = new TwoRectangles();
    clock_t start = clock();
    string my_answer = obj->describeIntersection(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    string p2 = "point";
    cout <<"Desired answer: " <<endl;
    cout <<"\t\"" << p2 <<"\"" <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t\"" << my_answer<<"\"" <<endl;
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
    int t0[] = {1,1,2,2};
    vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
    int t1[] = {3,1,4,2};
    vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
    TwoRectangles * obj = new TwoRectangles();
    clock_t start = clock();
    string my_answer = obj->describeIntersection(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    string p2 = "none";
    cout <<"Desired answer: " <<endl;
    cout <<"\t\"" << p2 <<"\"" <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t\"" << my_answer<<"\"" <<endl;
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

