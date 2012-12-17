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

class RunLengthPlus {
    public:
            string compress(string);
};

const int MAXN = 51;
int dp[MAXN][MAXN], INF = 999999999;

int combine(int i, int j, int k, string &s){
    if(k-i+1<=2){
        return k-i+1;
    }
    int cnt = 0;
    if(j-i > (k-j-1) ){
        //right is shorter
        int p = j+1;
        for(int a = i; a<=j; a++){
            if(s[a]==s[p]){
                p++;
                if(p==k+1){
                    p=j+1;
                    cnt++;
                }
            }else{
                return INF;
            }
        }
    }
    return cnt;
}

string RunLengthPlus::compress(string s) {
    int sz = s.size();
    for(int i=0; i<MAXN; i++){
        for(int j=0; j<MAXN; j++){
            dp[i][j] = INF;
        }
    }

        
    for(int len=1; len<sz; len++){
        for(int i=0; len+i<sz; i++){
            for(int j=i; j+1<=i+len; j++){
                // [i, j], [j+1,len];
                int left = dp[i][j];
                int right = dp[j+1][i+len];
                int com = combine(i,j,i+len, s);
                dp[i][i+len] = min(com,left+right);
            }
        }
    }
    for(int i=0; i<sz; i++){
        for(int j=i+1; j<sz; j++){
            cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
        }
    }

    //cout<<dp[0][sz-1]<<endl;
    return "";
}

double test0() {
	string p0 = "AAABBCDDDDDDDDDD";
	RunLengthPlus * obj = new RunLengthPlus();
	clock_t start = clock();
	string my_answer = obj->compress(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "3A2BC10D";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	string p0 = "XAABCBCBCAABCBCBCX";
	RunLengthPlus * obj = new RunLengthPlus();
	clock_t start = clock();
	string my_answer = obj->compress(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "X2(2A3(BC))X";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	string p0 = "ABCBACBABCBABCABACACBCBABACBCBBABACBACBCACBBAC";
	RunLengthPlus * obj = new RunLengthPlus();
	clock_t start = clock();
	string my_answer = obj->compress(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "ABCBA2(CBAB)CABACACBCBABACBC2BA2(BAC)BCAC2BAC";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
return 0;	
	time = test1();
	if (time < 0)
		errors = true;
	
	time = test2();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
