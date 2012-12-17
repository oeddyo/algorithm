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
const int MAXN = 100;
class EvenRoute {
    public:
            string isItPossible(vector <int>, vector <int>, int);
};

string EvenRoute::isItPossible(vector <int> x, vector <int> y, int wantedParity) {
       int dp[MAXN][MAXN];
       int g[MAXN][MAXN];
       for(int i=0; i<MAXN; i++)for(int j=0; j<MAXN; j++){
           dp[i][j]=0;
           g[i][j] = -1;
       }
       x.insert(x.begin(),0);
       y.insert(y.begin(),0);
       int N = x.size();

       for(int i=0; i<x.size(); i++){
           for(int j=0; j<x.size(); j++){
               if(abs((x[i]-x[j])+abs(y[i]-y[j]))%2==0){
                   g[i][j] = 0;
               }else{
                   g[i][j] = 1;
               }
           }
       }

        for(int t=0; t<=N-1; t++){
            memset(dp,0,sizeof(dp));
            for(int i=0; i<N; i++){
                for(int j=0; j<N; j++){
                    int tmp = 0;
                    for(int k=0; k<N; k++){
                        if((g[i][k]==0 && g[k][j]==0 )||(g[i][k]==1&&g[k][j]==1))
                        { 
                            dp[i][j] = 1;
                            break;
                        }
                    }
                }
            }
            for(int i=0; i<N;i++){
                for(int j=0; j<N; j++){
                    g[i][j]=dp[i][j];
                }
            }
        }
        for(int i=1; i<N; i++){
            if(wantedParity==0&&g[0][i]==0){
                return "CAN";
            }else if(wantedParity==1&&g[0][i]==1){
                return "CAN";
            }
        }
        return "CANNOT";
}
double test0() {
	int t0[] = {-1,-1,1,1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {-1,1,1,-1};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 0;
	EvenRoute * obj = new EvenRoute();
	clock_t start = clock();
	string my_answer = obj->isItPossible(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p3 = "CAN";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p3 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	int t0[] = {-5,-3,2};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {2,0,3};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 1;
	EvenRoute * obj = new EvenRoute();
	clock_t start = clock();
	string my_answer = obj->isItPossible(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p3 = "CAN";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p3 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	int t0[] = {1001, -4000};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {0,0};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 1;
	EvenRoute * obj = new EvenRoute();
	clock_t start = clock();
	string my_answer = obj->isItPossible(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p3 = "CAN";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p3 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	int t0[] = {11, 21, 0};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {-20, 42, 7};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 0;
	EvenRoute * obj = new EvenRoute();
	clock_t start = clock();
	string my_answer = obj->isItPossible(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p3 = "CANNOT";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p3 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	int t0[] = {0, 6};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {10, -20};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 1;
	EvenRoute * obj = new EvenRoute();
	clock_t start = clock();
	string my_answer = obj->isItPossible(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p3 = "CANNOT";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p3 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	
	time = test4();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
