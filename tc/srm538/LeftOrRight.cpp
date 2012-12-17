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
int dp[51][2];
const int INF = 999999999;
class LeftOrRight {
    public:
            int maxDistance(string);
};

int LeftOrRight::maxDistance(string program) {
    int sz = program.size();
    program = "#"+program;
    dp[0][0] = 0;
    dp[0][1] = 0;
    int ans = -INF;
    for(int k=1; k<=sz; k++){
        
        if(program[k]=='L'){
            dp[k][0] = min(dp[k-1][0]-1, dp[k-1][1]-1);
            dp[k][1] = max(dp[k-1][0]-1, dp[k-1][1]-1);
        }else if(program[k] == 'R'){
            dp[k][0] = min(dp[k-1][0]+1, dp[k-1][1]+1);
            dp[k][1] = max(dp[k-1][0]+1, dp[k-1][1]+1);;
        }else{
            dp[k][0] = min(dp[k-1][0], dp[k-1][1])-1;
            dp[k][1] = max(dp[k-1][0], dp[k-1][1])+1;
        }
        if(abs(dp[k][0])>ans){
            ans = abs(dp[k][0]);
        }
        if(abs(dp[k][1])>ans){
            ans = abs(dp[k][1]);
        }
    }
    return ans;
}

double test0() {
	string p0 = "LLLRLRRR";
	LeftOrRight * obj = new LeftOrRight();
	clock_t start = clock();
	int my_answer = obj->maxDistance(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 3;
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
	string p0 = "R???L";
	LeftOrRight * obj = new LeftOrRight();
	clock_t start = clock();
	int my_answer = obj->maxDistance(p0);
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
	string p0 = "??????";
	LeftOrRight * obj = new LeftOrRight();
	clock_t start = clock();
	int my_answer = obj->maxDistance(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 6;
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
	string p0 = "LL???RRRRRRR???";
	LeftOrRight * obj = new LeftOrRight();
	clock_t start = clock();
	int my_answer = obj->maxDistance(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 11;
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
	string p0 = "L?L?";
	LeftOrRight * obj = new LeftOrRight();
	clock_t start = clock();
	int my_answer = obj->maxDistance(p0);
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
	
	time = test4();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
