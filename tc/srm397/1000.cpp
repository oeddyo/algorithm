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

class CollectingMarbles {
    public:
        int mostMarbles(vector <int>, int, int);
};

const int MAXN  = 13;
const int MAXW = 21;
int dp[MAXN][MAXW][1<<13];

int CollectingMarbles::mostMarbles(vector <int> marblesWeights, int bagCapacity, int numberOfBags) {
    memset(dp,0,sizeof(dp));
    int sz = marblesWeights.size();
    dp[0][0][0] = 1;
    for(int i=0; i<numberOfBags; i++){
        for(int w=0; w<=bagCapacity; w++){
            for(int s=0; s<(1<<sz); s++){
                for(int j=0; j<sz; j++){
                    if( (s&(1<<j)) == 0 ){
                        //adding the j-th marbles
                        if( dp[i][w][s] ){
                            dp[i+1][0][s] = 1;
                            int weight = marblesWeights[j];
                            if( w+weight<=bagCapacity){
                                int ns = (s|(1<<j));
                                cout<<"i, w, ns "<<i<<" "<<w<<" "<<ns<<endl;
                                dp[i][w+weight][ns] = 1;
                            }
                        }
                    }
                }
            }
        }
    }
    int ans = 0;

    for(int i=0; i<numberOfBags; i++){
        for(int j=0; j<=bagCapacity; j++){
            for(int k=0; k<(1<<sz); k++){
                if(dp[i][j][k]){
                    ans = max( ans, __builtin_popcount(k));
                }
            }
        }
    }
    return ans;
}

double test0() {
    int t0[] = { 2, 2, 2, 2, 2 };
    vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
    int p1 = 5;
    int p2 = 2;
    CollectingMarbles * obj = new CollectingMarbles();
    clock_t start = clock();
    int my_answer = obj->mostMarbles(p0, p1, p2);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p3 = 4;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p3 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p3 != my_answer) {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
double test1() {
    int t0[] = { 1, 3, 5, 2, 4 };
    vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
    int p1 = 5;
    int p2 = 2;
    CollectingMarbles * obj = new CollectingMarbles();
    clock_t start = clock();
    int my_answer = obj->mostMarbles(p0, p1, p2);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p3 = 4;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p3 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p3 != my_answer) {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
double test2() {
    int t0[] = { 7, 6, 6, 5 };
    vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
    int p1 = 12;
    int p2 = 2;
    CollectingMarbles * obj = new CollectingMarbles();
    clock_t start = clock();
    int my_answer = obj->mostMarbles(p0, p1, p2);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p3 = 4;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p3 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p3 != my_answer) {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
double test3() {
    int t0[] = { 2, 2, 2 };
    vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
    int p1 = 1;
    int p2 = 10;
    CollectingMarbles * obj = new CollectingMarbles();
    clock_t start = clock();
    int my_answer = obj->mostMarbles(p0, p1, p2);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p3 = 0;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p3 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p3 != my_answer) {
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

