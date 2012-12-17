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

typedef pair<int, int> mypair;
vector < mypair > my_vec;
vector <int> g_lower;
vector <int> g_upper;
int sz = 0;
class Over9000Rocks {
    public:
            int countPossibilities(vector <int>, vector <int>);
};

void dfs(int p, int low, int high){
    if(p==sz){
        return ;
    }
    //choose
    if(low+g_lower[p]>9000 || high+g_upper[p] > 9000){
       my_vec.push_back( mypair(low+g_lower[p], high+g_upper[p]));
        
    }
    dfs(p+1, low+g_lower[p], high+g_upper[p]);
    dfs(p+1, low, high);
}


int Over9000Rocks::countPossibilities(vector <int> lowerBound, vector <int> upperBound) {
    sz = lowerBound.size();
    cout<<sz<<endl;
    g_upper=upperBound;
    g_lower=lowerBound;
    my_vec.clear();
    dfs(0,0,0);
    sort(my_vec.begin(), my_vec.end());
    sz = my_vec.size();
    if(sz==0)return 0;

    cout<<" size is "<<sz<<endl;
    for(int i=0; i<sz; i++){
        cout<<my_vec[i].first<<" "<<my_vec[i].second<<endl;
    }
    int ans = 0;
    int pre = my_vec[0].first;
    for(int i=1; i<sz; i++){
        if(my_vec[i].first > my_vec[i-1].second){
            if(pre <= 9000){
                ans += (my_vec[i-1].second - 9001 +1);
            }else{
                ans+= (my_vec[i-1].second - pre + 1);
            }
            pre = my_vec[i].first;
        }
    }
            
    if(pre <= 9000){
        ans += (my_vec[sz-1].second - 9001 +1);
    }else{
        ans+= (my_vec[sz-1].second - pre + 1);
    }
    
    //cout<<ans<<endl;
    return ans;
}

double test0() {
	int t0[] = {9000};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {9001};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	Over9000Rocks * obj = new Over9000Rocks();
	clock_t start = clock();
	int my_answer = obj->countPossibilities(p0, p1);
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
double test1() {
	int t0[] = {9000, 1, 10};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {9000, 2, 20};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	Over9000Rocks * obj = new Over9000Rocks();
	clock_t start = clock();
	int my_answer = obj->countPossibilities(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 15;
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
	int t0[] = {1001, 2001, 3001, 3001};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {1003, 2003, 3003, 3003};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	Over9000Rocks * obj = new Over9000Rocks();
	clock_t start = clock();
	int my_answer = obj->countPossibilities(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 9;
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
	int t0[] = {9000,90000,1,10};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {9000,90000,3,15};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	Over9000Rocks * obj = new Over9000Rocks();
	clock_t start = clock();
	int my_answer = obj->countPossibilities(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 38;
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
	int t0[] = {1,1,1,1,1,1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {3,4,5,6,7,8};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	Over9000Rocks * obj = new Over9000Rocks();
	clock_t start = clock();
	int my_answer = obj->countPossibilities(p0, p1);
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
