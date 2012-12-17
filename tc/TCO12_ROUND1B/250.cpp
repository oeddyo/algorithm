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

class FoxAndKgram {
    public:
            int maxK(vector <int>);
};
const int MAXN = 51;
int FoxAndKgram::maxK(vector <int> len) {
    int sz = len.size();

    int ans = 0;
    for(int k=1; k<=sz; k++){
        //cout<<"k is "<<k<<endl;
        int ok[MAXN];
        for(int i=0; i<MAXN; i++)ok[i]=1;
        int cnt = 0;
        for(int i=0; i<sz; i++){
            if(len[i]==k){
                ok[i]=0;
                cnt++;
                //cout<<"choosing "<<len[i]<<endl;
            }
        }
        for(int i=0; i<sz; i++){
            for(int j=i+1; j<sz; j++){
                //cout<<"seeing ok["<<i<<"] and ok["<<j<<"] and they are "<<ok[i]<<" "<<ok[j]<<endl;
                if(ok[i] && ok[j]){
                    if(len[i]+len[j]==k-1){
                        ok[i]=0;
                        ok[j]=0;
                        cnt++;
                        //cout<<"choosing "<<len[i]<<" "<<len[j]<<endl;
                    }
                }
            }
        }
        if(cnt>=k){
            if(k>ans){
                ans = k;
            }
        }
    }
    return ans;

}
double test0() {
	int t0[] = {1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	FoxAndKgram * obj = new FoxAndKgram();
	clock_t start = clock();
	int my_answer = obj->maxK(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 1;
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
	int t0[] = {2,2,1,3,5,5,5};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	FoxAndKgram * obj = new FoxAndKgram();
	clock_t start = clock();
	int my_answer = obj->maxK(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 5;
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
	FoxAndKgram * obj = new FoxAndKgram();
	clock_t start = clock();
	int my_answer = obj->maxK(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 1;
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
	int t0[] = {2,2,2,2,2,2,2,2,2,2};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	FoxAndKgram * obj = new FoxAndKgram();
	clock_t start = clock();
	int my_answer = obj->maxK(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 5;
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
	int t0[] = {1,2,3,1,2,4,2,3,1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	FoxAndKgram * obj = new FoxAndKgram();
	clock_t start = clock();
	int my_answer = obj->maxK(p0);
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
double test5() {
	int t0[] = {2,3,5,7,11,13,17,19,23,29};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	FoxAndKgram * obj = new FoxAndKgram();
	clock_t start = clock();
	int my_answer = obj->maxK(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 0;
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
	
	time = test5();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}


