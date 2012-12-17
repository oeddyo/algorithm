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

class ChangingSounds {
    public:
            int maxFinal(vector <int>, int, int);
};

int dp[101][1001];
int ChangingSounds::maxFinal(vector <int> changeIntervals, int beginLevel, int maxLevel) {
    memset(dp,0,sizeof(dp));
    

    int add = beginLevel+changeIntervals[0];
    int sub = beginLevel-changeIntervals[0];
    if(add>=0&&add<=maxLevel){
        dp[0][add]=1;
    }
    if(sub>=0&&sub<=maxLevel){
        dp[0][sub]=1;
    }
    int sz = changeIntervals.size();
    for(int i=1; i<sz; i++){
        int cur = changeIntervals[i];
        for(int j=0; j<=maxLevel; j++){
            if( j-cur>=0 && j-cur<=maxLevel&&dp[i-1][j-cur]==1   ){
                dp[i][j]=1;
            }
            if( j+cur>=0 && j+cur<=maxLevel&&dp[i-1][j+cur]==1){
                dp[i][j]=1;
            }
        }
    }
    int ans = -1;
    for(int i=0; i<=maxLevel; i++){
        if(dp[sz-1][i]==1){
            ans = i;
        }
    }
    return ans;
}
double test0() {
	int t0[] = {5, 3, 7};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 5;
	int p2 = 10;
	ChangingSounds * obj = new ChangingSounds();
	clock_t start = clock();
	int my_answer = obj->maxFinal(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 10;
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
	int t0[] = {15, 2, 9, 10};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 8;
	int p2 = 20;
	ChangingSounds * obj = new ChangingSounds();
	clock_t start = clock();
	int my_answer = obj->maxFinal(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = -1;
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
	int t0[] = {74,39,127,95,63,140,99,96,154,18,137,162,14,88};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 40;
	int p2 = 243;
	ChangingSounds * obj = new ChangingSounds();
	clock_t start = clock();
	int my_answer = obj->maxFinal(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 238;
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
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

