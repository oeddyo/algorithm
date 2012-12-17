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

class CoinWeight {
    public:
            int possibleValues(int, vector <string>);
};

const int MAXN = 7*100*100;
//int c[MAXN];
//int w[MAXN];
int dp[8*31][101][400];;
int CoinWeight::possibleValues(int weight, vector <string> coins) {
    vector <int> c;
    vector <int> w;
    memset(dp,0,sizeof(dp));
    int v_sum = 0;
    for(int i=0; i<coins.size();i++){
        istringstream is(coins[i]);
        int v, t_max, t_min;
        is>>v>>t_min>>t_max;
        v_sum+=v;
        for(int j=t_min; j<=t_max; j++){
            c.push_back(v);
            w.push_back(j);
        }
    }
    dp[0][0][0] = 1;
    dp[0][w[0]][c[0]] = 1;
    cout<<weight<<" "<<v_sum<<" "<<c.size()<<endl;
    cout<<"size is "<<c.size()<<endl;
    int sz = c.size();
    for(int i=0; i<sz; i++){
        for(int j=0; j<=weight; j++){
            for(int k=0; k<=v_sum; k++){
                cout<<"i,j,k "<<i<<" "<<j<<" "<<k<<" "<<dp[i][j][k]<<endl;;
                int new_value = k + c[i];
                int new_weight = j+w[i];
                if(new_value<=v_sum && new_weight<=weight){
                    dp[i+1][new_weight][new_value]+=dp[i][j][k];
                    dp[i+1][j][k] += dp[i][j][k];
                }
            }
        }
    }
    int ans = 0;
    cout<<sz-1<<endl; 
    ans+=dp[sz-1][weight][v_sum];
    return ans;

}
double test0() {
	int p0 = 30;
	string t1[] = {"001 10 10"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	CoinWeight * obj = new CoinWeight();
	clock_t start = clock();
	int my_answer = obj->possibleValues(p0, p1);
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
	int p0 = 11;
	string t1[] = {"25 20 22"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	CoinWeight * obj = new CoinWeight();
	clock_t start = clock();
	int my_answer = obj->possibleValues(p0, p1);
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
double test2() {
	int p0 = 50;
	string t1[] = {"1 15 20", "3 30 30"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	CoinWeight * obj = new CoinWeight();
	clock_t start = clock();
	int my_answer = obj->possibleValues(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 2;
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
	int p0 = 50;
	string t1[] = {"1 15 20", "2 30 30"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	CoinWeight * obj = new CoinWeight();
	clock_t start = clock();
	int my_answer = obj->possibleValues(p0, p1);
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
double test4() {
	int p0 = 100;
	string t1[] = {"1 2 31","2 16 46","4 31 61","8 46 76","16 61 91","32 76 100","50 2 31"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	CoinWeight * obj = new CoinWeight();
	clock_t start = clock();
	int my_answer = obj->possibleValues(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 1316;
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
    return 0;	
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

