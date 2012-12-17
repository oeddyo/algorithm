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

class PolyMove {
    public:
            double addedArea(vector <int>, vector <int>);
};
const double eps = 1e-10;
bool eq(double a,double b){
    if( fabs(a-b)<=eps ){
        return true;
    }return false;
}

const int MAXN = 100;
long double dp[MAXN][2];
const double INF = 99999999;

long double dis(int x1, int y1, int x2, int y2){
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

void init(){
    for(int i=0; i<MAXN; i++){
        dp[i][0] = -INF;
        dp[i][1] = -INF;
    }
}

double PolyMove::addedArea(vector <int> x, vector <int> y) {
    init();
    int sz = x.size();
    cout<<"0 move!"<<endl;
    dp[0][0] = -INF;
    dp[0][1] = dis(x[1],y[1], x[sz-1], y[sz-1])/2; 
    cout<<0<<" "<<dp[0][1]<<endl; 
    for(int i=1; i<sz-1; i++){
        long double inc = dis(x[i-1],y[i-1], x[i+1],y[i+1])/2;
        cout<<i<<" "<<inc<<endl;
        dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
        if(!eq(dp[i-1][0], -INF)){
            dp[i][1] = max(dp[i][1], dp[i-1][0]+inc);
        }
    }
    dp[sz-1][0] = max(dp[sz-1-1][0], dp[sz-1-1][1]);
    
    long double ans1 = dp[sz-1][0]; 
    //cout<<dp[sz-1][0]<<endl;
    cout<<"0 not move!"<<endl;
    init();
    dp[0][0] = 0.0;
    dp[0][1] = -INF;
    for(int i=1; i<sz-1; i++){
        long double inc = dis(x[i-1],y[i-1], x[i+1],y[i+1])/2;
        cout<<i<<" "<<inc<<endl;
        dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
        if(!eq(dp[i-1][0], -INF)){
            dp[i][1] = max(dp[i][1], dp[i-1][0]+inc);
        }
    }
    long double inc = dis(x[sz-1-1],y[sz-1-1], x[0], y[0])/2;
    dp[sz-1][0] = max(dp[sz-1-1][0], dp[sz-1-1][1]);
    if(!eq(dp[sz-1-1][0], -INF)){
        dp[sz-1][1] = max(dp[sz-1][1], dp[sz-1-1][0]+inc);
    }
    ans1 = max(max(ans1, dp[sz-1][0]), dp[sz-1][1] );
    cout<<ans1<<endl;
    return (double)ans1;
}

double test0() {
	int t0[] = {0,2,19,30,29};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {0,300,300,1,0};
    vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	PolyMove * obj = new PolyMove();
	clock_t start = clock();
	double my_answer = obj->addedArea(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p2 = 300.7603622931292;
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
	int t0[] = {0,1,1,0};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {1,1,0,0};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	PolyMove * obj = new PolyMove();
	clock_t start = clock();
	double my_answer = obj->addedArea(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p2 = 1.4142135623730951;
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
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
