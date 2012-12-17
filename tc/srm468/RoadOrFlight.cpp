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
const int MAXN = 400001;
const long long INF = 400000*100001;
class RoadOrFlightHard {
    public:
            long long minTime(int, int, int, int, int, int, int, int, int, int);
            long long ft[MAXN], rt[MAXN];
            long long dp[41][MAXN];
};

long long RoadOrFlightHard::minTime(int N, int roadFirst, int roadProd, int roadAdd, int roadMod, int flightFirst, int flightProd, int flightAdd, int flightMod, int K) {
    rt[0] = roadFirst%roadMod;
    ft[0] = flightFirst%flightMod;
    for(int i=1; i<N; i++){
        rt[i] = (rt[i-1]*roadProd + roadAdd) % roadMod;
        ft[i] = (ft[i-1]*flightProd + flightAdd) % flightMod;
    }
    for(int i=0; i<N; i++){
        cout<<rt[i]<<" ";
    }cout<<endl;
    for(int i=0; i<N; i++){
        cout<<ft[i]<<" ";
    }cout<<endl;
    return 1;
    //aggre
    for(int i=1; i<N; i++){
        ft[i]+=ft[i-1];
    }
    for(int i=0; i<K; i++){
        for(int j=0; j<N; j++){
            dp[i][j]=INF;
        }
    }

}

double test0() {
	int p0 = 3;
	int p1 = 14;
	int p2 = 1;
	int p3 = 2;
	int p4 = 10;
	int p5 = 18;
	int p6 = 1;
	int p7 = 10;
	int p8 = 17;
	int p9 = 1;
	RoadOrFlightHard * obj = new RoadOrFlightHard();
	clock_t start = clock();
	long long my_answer = obj->minTime(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p10 = 14LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p10 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p10 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int p0 = 3;
	int p1 = 4;
	int p2 = 1;
	int p3 = 2;
	int p4 = 10;
	int p5 = 1;
	int p6 = 1;
	int p7 = 10;
	int p8 = 17;
	int p9 = 2;
	RoadOrFlightHard * obj = new RoadOrFlightHard();
	clock_t start = clock();
	long long my_answer = obj->minTime(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p10 = 11LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p10 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p10 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int p0 = 3;
	int p1 = 4;
	int p2 = 1;
	int p3 = 2;
	int p4 = 10;
	int p5 = 1;
	int p6 = 1;
	int p7 = 6;
	int p8 = 9;
	int p9 = 1;
	RoadOrFlightHard * obj = new RoadOrFlightHard();
	clock_t start = clock();
	long long my_answer = obj->minTime(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p10 = 12LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p10 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p10 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int p0 = 5;
	int p1 = 85739;
	int p2 = 94847;
	int p3 = 93893;
	int p4 = 98392;
	int p5 = 92840;
	int p6 = 93802;
	int p7 = 93830;
	int p8 = 92790;
	int p9 = 3;
	RoadOrFlightHard * obj = new RoadOrFlightHard();
	clock_t start = clock();
	long long my_answer = obj->minTime(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p10 = 122365LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p10 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p10 != my_answer) {
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

