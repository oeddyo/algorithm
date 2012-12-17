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

class RandomSort {
    public:
            double getExpected(vector <int>);
};
typedef vector<int> VI;

map< VI, double> mymap;
int sz;
void print(VI v){
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }cout<<endl;
}

double dfs(VI v){
    if(mymap.count(v)==1){
        return mymap[v];
    }
    bool ok = true;
    for(int i=1; i<sz; i++){
        if(v[i]<v[i-1]){
            ok=false;
            break;
        }
    }
    if(ok){
        return 0;
    }
    double sum_expect = 0;
    int cnt = 0;
    for(int i=0; i<sz; i++){
        for(int j=i+1; j<sz; j++){
            if(v[i]>v[j]){
                swap(v[i],v[j]);
                double expect = dfs(v)+1;
                swap(v[i],v[j]);
                sum_expect += expect;
                cnt++;
            }
        }
    }
    double tt = sum_expect*1.0/(cnt);
    mymap[v] = tt;
    //print(v);
    //cout<<"expect is "<<tt<<endl;
    return tt;
}

double RandomSort::getExpected(vector <int> permutation) {
    sz = permutation.size();
    mymap = map<VI, double> ();
    double ans = dfs(permutation);
    return ans; 
}
double test0() {
	int t0[] = {2,3,1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	RandomSort * obj = new RandomSort();
	clock_t start = clock();
	double my_answer = obj->getExpected(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p1 = 2.0;
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
	int t0[] = {4,3,2,1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	RandomSort * obj = new RandomSort();
	clock_t start = clock();
	double my_answer = obj->getExpected(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p1 = 4.066666666666666;
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
	int t0[] = {1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	RandomSort * obj = new RandomSort();
	clock_t start = clock();
	double my_answer = obj->getExpected(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p1 = 0.0;
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
	int t0[] = {2,5,1,6,3,4};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	RandomSort * obj = new RandomSort();
	clock_t start = clock();
	double my_answer = obj->getExpected(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p1 = 5.666666666666666;
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

