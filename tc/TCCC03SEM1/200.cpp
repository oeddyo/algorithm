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

class TCU {
    public:
            vector <int> majors(vector <string>, vector <int>, int);
};
const int MAXN = 50;
int data[MAXN][MAXN];
int n_row, n_col;
vector <int> TCU::majors(vector <string> percentages, vector <int> start, int years) {
    n_row = percentages.size();
    
    cout<<n_row<<" "<<n_col<<endl;
    for(int i=0; i<percentages.size(); i++){
        istringstream is(percentages[i]);
        int t;
        n_col = 0;
        while(is>>t){    
            data[i][n_col] = t;
            n_col++;
        }
    }
    int inter[MAXN];
    for(int y=0; y<years; y++){
        memset(inter, 0, sizeof(inter));
        for(int i=0; i<n_row; i++){
            int extra = 0;
            for(int j=0; j<n_col; j++){
                int trans = start[i]*data[i][j];
                extra += trans%100;
                //int trans = (start[i])*data[i][j]/100;
                inter[j]+= trans/100;
            }
            inter[i] += extra/100;
        }
        start.clear();
        cout<<"year "<<y<<endl;
        for(int i=0; i<n_col; i++){
            start.push_back(inter[i]);
            cout<<inter[i]<<" ";
        }cout<<endl;
    }

    cout<<"______"<<endl;
        
    for(int i=0; i<n_row; i++){
        for(int j=0; j<n_col;j++){
            cout<<data[i][j]<<" ";
        }cout<<endl;
    }
    cout<<"______"<<endl;
    return start;
}

double test0() {
	string t0[] = {"99 01","99   001"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int t1[] = {1000000,0};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 2;
	TCU * obj = new TCU();
	clock_t start = clock();
	vector <int> my_answer = obj->majors(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t3[] = { 990000,  10000 };
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p3.size() > 0) {
		cout <<p3[0];
		for (int i=1; i<p3.size(); i++)
			cout <<", " <<p3[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p3) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	string t0[] = {"80 1 5 14","2 76 19 3","1 3 45 51","30 32 26 12"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int t1[] = {1237,625,9618,13476};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 5;
	TCU * obj = new TCU();
	clock_t start = clock();
	vector <int> my_answer = obj->majors(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t3[] = { 7497,  7212,  5533,  4714 };
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p3.size() > 0) {
		cout <<p3[0];
		for (int i=1; i<p3.size(); i++)
			cout <<", " <<p3[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p3) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	string t0[] = {"80 1 5 14","2 76 19 3","1 3 45 51","30 32 26 12"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int t1[] = {1237,625,9618,134760};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 500;
	TCU * obj = new TCU();
	clock_t start = clock();
	vector <int> my_answer = obj->majors(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t3[] = { 46162,  41768,  31364,  26946 };
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p3.size() > 0) {
		cout <<p3[0];
		for (int i=1; i<p3.size(); i++)
			cout <<", " <<p3[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p3) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	string t0[] = {" 00 100 "," 100 0 "};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int t1[] = {23,37};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 999;
	TCU * obj = new TCU();
	clock_t start = clock();
	vector <int> my_answer = obj->majors(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t3[] = { 37,  23 };
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p3.size() > 0) {
		cout <<p3[0];
		for (int i=1; i<p3.size(); i++)
			cout <<", " <<p3[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p3) {
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
