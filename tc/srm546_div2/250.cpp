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

class ContestWinner {
    public:
        int getWinner(vector <int>);
};

typedef pair<int, int> pii;
typedef vector< pii > vp;
typedef pair< int, pii> piii;

#define all(c) (c).begin(),(c).end() 


bool mycmp(const piii &a, const piii &b){
    if(a.second.first==b.second.first){
        return a.second.second < b.second.second;
    }else{
        return a.second.first>b.second.first;
    }

}

int ContestWinner::getWinner(vector <int> events) {
    int sz = events.size();
    map<int, pii > mymap;
    for(int i=0; i<sz; i++){
        int who = events[i];
        if(mymap.find(who)==mymap.end()){
            pii t(1,i);
            mymap[who] = t;
        }else{
            mymap[who].first+=1;
            mymap[who].second = i;
        }
    }
    vector< pair< int, pii> > V(all(mymap));
    sort(V.begin(), V.end(), mycmp);
 
    return V[0].first;
}

double test0() {
    int t0[] = {4,7,4,1};
    vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
    ContestWinner * obj = new ContestWinner();
    clock_t start = clock();
    int my_answer = obj->getWinner(p0);
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
double test1() {
    int t0[] = {10,20,30,40,50};
    vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
    ContestWinner * obj = new ContestWinner();
    clock_t start = clock();
    int my_answer = obj->getWinner(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p1 = 10;
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
    int t0[] = {123,123,456,456,456,123};
    vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
    ContestWinner * obj = new ContestWinner();
    clock_t start = clock();
    int my_answer = obj->getWinner(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p1 = 456;
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
    int t0[] = {1,2,2,3,3,3,4,4,4,4};
    vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
    ContestWinner * obj = new ContestWinner();
    clock_t start = clock();
    int my_answer = obj->getWinner(p0);
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


