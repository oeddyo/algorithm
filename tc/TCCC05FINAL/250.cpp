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

class BadSubstrings {
    public:
            long long howMany(int, string, string);
};

long long dp[40][3];
long long my_pow(int base, int t){
    long long a = 1;
    for(int i=0; i<t; i++){
        a*=base;
    }
    return a;
}

long long BadSubstrings::howMany(int N, string bad1, string bad2) {
    memset(dp,0,sizeof(dp));
    for(int i=0; i<3; i++){
        char t = (i+'A');
        string str1 = "";
        str1+=t;
        string str2 = "";
        str2+=t;
        if(bad1==str1 || bad2==str2){
            dp[0][i] = 0;
        }else{
            dp[0][i] = 1;
        }
    }
    int bad1_len = bad1.size();
    int bad2_len = bad2.size();
    for(int i=1; i<N; i++){
        for(int j=0; j<3; j++){
            for(int k=0; k<3; k++){
                dp[i][j]+=dp[i-1][k];
            }
            if(i>=bad1_len-1 && bad1[bad1_len-1]-'A'==j){
                dp[i][j] -= my_pow(3,(i-bad1_len+1));
            }
            if(i>=bad2_len-1 && bad2[bad2_len-1]-'A'==j){
                dp[i][j] -= my_pow(3,(i-bad2_len+1));
            }
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    long long sum = 0;
    for(int i=0; i<3; i++){
        sum+=dp[N-1][i];
    }
    return sum;

}
double test0() {
	int p0 = 3;
	string p1 = "AB";
	string p2 = "BA";
	BadSubstrings * obj = new BadSubstrings();
	clock_t start = clock();
	long long my_answer = obj->howMany(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p3 = 17LL;
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
	int p0 = 2;
	string p1 = "A";
	string p2 = "BB";
	BadSubstrings * obj = new BadSubstrings();
	clock_t start = clock();
	long long my_answer = obj->howMany(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p3 = 3LL;
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
	int p0 = 5;
	string p1 = "ABC";
	string p2 = "ABB";
	BadSubstrings * obj = new BadSubstrings();
	clock_t start = clock();
	long long my_answer = obj->howMany(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p3 = 189LL;
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
double test3() {
	int p0 = 39;
	string p1 = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA";
	string p2 = "ABCABCABCABCABCABCABCABCABCABCABCABCABC";
	BadSubstrings * obj = new BadSubstrings();
	clock_t start = clock();
	long long my_answer = obj->howMany(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p3 = 4052555153018976265LL;
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
	
	time = test3();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

