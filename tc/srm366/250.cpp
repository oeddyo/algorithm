/*====================================================
#
# Author: XieKe,from BUAA. oeddyo@gmail.com
#
# blog : www.oeddyo.com
#
# Last modified: 2010-04-03 13:33
#
# Filename: SRM366_1.cpp
#
===================================================*/


#include <iostream>
#include <algorithm>
#include <queue>
#include <iomanip>

using namespace std;

class ChangingSounds{
    public:
        int dp[100][1001];
        int maxFinal(vector <int> changeIntervals, int beginLevel, int maxLevel){
            memset(dp,0,sizeof(dp));
            int sz=changeIntervals.size();
            dp[0][beginLevel]=1;
            for(int i=1;i<=sz;i++){
                for(int j=0;j<=1000;j++){
                    if(j-changeIntervals[i-1]>=0){
                        if(dp[i-1][j-changeIntervals[i-1]]==1){
                            dp[i][j]=1;
                        }
                    }
                    if(j+changeIntervals[i-1]<=maxLevel){
                        if(dp[i-1][j+changeIntervals[i-1]]==1){
                            dp[i][j]=1;
                        }
                    }
                }
            }
           /* 
            for(int i=0;i<10;i++){
                for(int j=0;j<=10;j++){
                    cout<<dp[i][j]<<" ";
                }cout<<endl;
            }
            */
            int ans=-1;
            for(int i=0;i<=maxLevel;i++){
                if(dp[sz][i]){
                    ans=i;
                }
            }
		return ans;
        }
    private:

};
<%:start-tests%>
double test0() {
	int t0[] = {5, 3, 7};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 5;
	int p2 = 10;
	ChangingSounds * obj = new ChangingSounds();
	clock_t start = clock();
	int my_answer = obj->maxFinal(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 10;
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
	int t0[] = {15, 2, 9, 10};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 8;
	int p2 = 20;
	ChangingSounds * obj = new ChangingSounds();
	clock_t start = clock();
	int my_answer = obj->maxFinal(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = -1;
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
	int t0[] = {74,39,127,95,63,140,99,96,154,18,137,162,14,88};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 40;
	int p2 = 243;
	ChangingSounds * obj = new ChangingSounds();
	clock_t start = clock();
	int my_answer = obj->maxFinal(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 238;
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
<%:end-tests%>
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
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
