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

class IdealString {
    public:
            string construct(int);
};


//int dp[101][101];
int dp[101];
int pre[101];
const int INF = 999999999;
string IdealString::construct(int length) {
    for(int i=0; i<101; i++){
        pre[i]=-1;
        dp[i]=-INF;
    }
    dp[0] = 0;
    int data[101];
    for(int i=1; i<=100; i++){
        data[i] = i;
    }
    for(int i=1; i<=100; i++){
        for(int j=length; j>=0; j--){
            if(j-data[i]<0)continue; 
            if(dp[j] <= dp[j-data[i]]+1){
                dp[j] = dp[j-data[i]]+1;
                pre[j] = j-data[i];
            }
        }
    }
    vector <int> tmp;
    vector <int> num;
    int t = length;
    while(pre[t]!=-1){
        cout<<t-pre[t]<<" ";
        tmp.push_back(t-pre[t]);
        t = pre[t];
    }
    sort(tmp.begin(), tmp.end());
    num = tmp;
    if(tmp.size()==0||tmp[0]!=1){
        return "";
    }
    string ans="#";
    for(int i=0; i<length; i++)ans+="*";
    int cnt = 0;
    for(int i=0; i<tmp.size(); i++){
        cout<<tmp[i]<<" ";
        ans[tmp[i]] = cnt+'A';
        cnt++;
        tmp[i]--;
    }cout<<endl;
    cout<<"after change "<<ans<<endl;
    for(int i=1; i<ans.size(); i++){
        if(ans[i]=='*'){
            for(int j=0; j<tmp.size(); j++){
                if(tmp[j]!=0){
                    if(num[j] > i)return "";
                    ans[i] = j+'A';
                    tmp[j]--;
                    break;
                }
            }
        }
    }
    string final_ans = ans.substr(1,ans.size()-1);
    return final_ans;

}
double test0() {
	int p0 = 13;
	IdealString * obj = new IdealString();
	clock_t start = clock();
	string my_answer = obj->construct(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "";
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
	int p0 = 3;
	IdealString * obj = new IdealString();
	clock_t start = clock();
	string my_answer = obj->construct(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "ABB";
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
	int p0 = 2;
	IdealString * obj = new IdealString();
	clock_t start = clock();
	string my_answer = obj->construct(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "";
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
double test3() {
	int p0 = 6;
	IdealString * obj = new IdealString();
	clock_t start = clock();
	string my_answer = obj->construct(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "ABCBCC";
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
double test4() {
	int p0 = 7;
	IdealString * obj = new IdealString();
	clock_t start = clock();
	string my_answer = obj->construct(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "ABBCCCC";
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
double test5() {
	int p0 = 5;
	IdealString * obj = new IdealString();
	clock_t start = clock();
	string my_answer = obj->construct(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "";
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
