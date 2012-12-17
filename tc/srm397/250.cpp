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
#include <queue>
using namespace std;

class SortingGame {
    public:
        int fewestMoves(vector <int>, int);
};

typedef pair< vector<int>, int > mypair;
int sz ;
bool check(vector<int> &t){
    for(int i=1; i<sz; i++){
        if(t[i]<t[i-1]){
            return false;
        }
    }
    return true;
}

void print(vector<int> q){
    for(int i=0; i<q.size(); i++){
        cout<<q[i]<<" ";
    }
    cout<<endl;
}

int SortingGame::fewestMoves(vector <int> board, int k) {
    sz = board.size();
    queue<mypair> Q;
    Q.push(mypair(board,0));
    map< vector<int>, int > mymap;
    int cnt = 0;
    mymap[board] = cnt++;

    mypair cur;
    while(!Q.empty()){
        cur = Q.front();
        Q.pop();
        //print(cur.first);
        if(check(cur.first)){
            return cur.second;
        }
        for(int i=0; i<sz&&i+k<=sz; i++){
            reverse(cur.first.begin()+i, cur.first.begin()+i+k);
            //reverse(cur.first.begin()+i, cur.first.begin()+j);
            if(mymap.find(cur.first)==mymap.end()){
                mymap[cur.first] = cnt++;
                Q.push( mypair(cur.first, cur.second+1));
            }
            reverse(cur.first.begin()+i, cur.first.begin()+i+k);
            //reverse(cur.first.begin()+i, cur.first.begin()+j);
        }
    }
    return -1;
}
double test0() {
    int t0[] = {1,2,3};
    vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
    int p1 = 3;
    SortingGame * obj = new SortingGame();
    clock_t start = clock();
    int my_answer = obj->fewestMoves(p0, p1);
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
double test1() {
    int t0[] = {3,2,1};
    vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
    int p1 = 3;
    SortingGame * obj = new SortingGame();
    clock_t start = clock();
    int my_answer = obj->fewestMoves(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p2 = 1;
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
    int t0[] = {5,4,3,2,1};
    vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
    int p1 = 2;
    SortingGame * obj = new SortingGame();
    clock_t start = clock();
    int my_answer = obj->fewestMoves(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p2 = 10;
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
    int t0[] = {3,2,4,1,5};
    vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
    int p1 = 4;
    SortingGame * obj = new SortingGame();
    clock_t start = clock();
    int my_answer = obj->fewestMoves(p0, p1);
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
    int t0[] = {7,2,1,6,8,4,3,5};
    vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
    int p1 = 4;
    SortingGame * obj = new SortingGame();
    clock_t start = clock();
    int my_answer = obj->fewestMoves(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p2 = 7;
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

