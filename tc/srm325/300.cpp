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

class FenceRepairing {
    public:
            double calculateCost(vector <string>);
};


/*
const int MAXN = 2501;
const double INF = 99999999;
double dp[MAXN][MAXN];
*/

const int MAXN = 2501;
const double INF = 99999999;
double dp[MAXN];
double FenceRepairing::calculateCost(vector <string> boards) {
    string board = "";
    for(int i=0; i<boards.size(); i++){
        board+=boards[i];
    }
    vector <int> b;
    for(int i=0; i<board.size(); i++){
        if(board[i]=='X'){
            b.push_back(i);
        }
    }
    /*
    for(int i=0; i<MAXN; i++)for(int j=0; j<MAXN; j++)dp[i][j]=INF;

    int sz = b.size();
    for(int i=0; i<sz; i++){
        dp[i][i] = 1;
    }

    for(int len=1; len<sz; len++){
        for(int i=0; i+len<sz; i++){
            for(int j=i; j+1<=i+len; j++){
                dp[i][i+len] = min(dp[i][i+len], dp[i][j]+dp[j+1][i+len]);
            }
            dp[i][i+len] = min(dp[i][i+len], sqrt(b[i+len]-b[i]+1));
        }
    }
    cout<<dp[0][sz-1]<<endl;
    return dp[0][sz-1];
    */
    int sz = b.size();
    for(int i=0; i<sz; i++){
        dp[i]=INF;
    }
    dp[0] = 1;
    for(int i=1; i<sz; i++){
        dp[i] = min(dp[i], sqrt(b[i]-b[0]+1));
        for(int j=1; j<=i; j++){
            double cost = sqrt(b[i]-b[j]+1)+dp[j-1];
            /*
            if(dp[i] > cost){
                cout<<"using "<<j<<" to update"<<endl;;
                cout<<"pre dp is "<<dp[j-1]<<" now new dis is "<<sqrt(b[i]-b[j]+1)<<endl;
            }
            */
            dp[i] = min(dp[i], cost);
        }
        //    cout<<"dp["<<i<<"] is "<<dp[i]<<endl;
    }
    return dp[sz-1];
}
double test0() {
	string t0[] = {"X.X...X.X"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	FenceRepairing * obj = new FenceRepairing();
	clock_t start = clock();
	double my_answer = obj->calculateCost(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p1 = 3.0;
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
	string t0[] = {"X.X.....X"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	FenceRepairing * obj = new FenceRepairing();
	clock_t start = clock();
	double my_answer = obj->calculateCost(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p1 = 2.732050807568877;
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
	string t0[] = {"X.......", "......XX", ".X......", ".X...X.."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	FenceRepairing * obj = new FenceRepairing();
	clock_t start = clock();
	double my_answer = obj->calculateCost(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p1 = 5.0;
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
	string t0[] = {".X.......X", "..........", "...X......", "...X..X...", "..........",
 "..........", "..X....XX.", ".........X", "XXX", ".XXX.....X"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	FenceRepairing * obj = new FenceRepairing();
	clock_t start = clock();
	double my_answer = obj->calculateCost(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p1 = 9.591663046625438;
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

