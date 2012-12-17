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

class MakeUnique {
    public:
            string eliminated(string);
};

const int MAXN = 51;
int dp[MAXN];
int pre[MAXN];
const int INF = 999999999;
string MakeUnique::eliminated(string original) {
    vector <char> t;
    for(int i=0; i<original.size(); i++){
        t.push_back(original[i]);
    }
    sort(t.begin(), t.end());
    char firstLetter = t[0];
    char lastLetter = t[original.size()-1];
    int cnt = 0;
    char pre_letter = '@';
    for(int i=0; i<original.size();i++){
        if(pre_letter!=t[i]){
            pre_letter = t[i];
            cnt++;
        }
        pre[i] = -1;
        if(original[i]==firstLetter){
            dp[i] = 1;
        }else{
            dp[i] = -INF;
        }
    }
    cout<<"there are "<<cnt<<" different letters"<<endl;
    for(int i=0; i<original.size(); i++){
        cout<<dp[i]<<" ";
    }cout<<endl;
    cout<<"here we are"<<endl;

    int max_val = 1;
    for(int i=1; i<original.size(); i++){
        for(int j=0; j<i; j++){
            if(original[i] > original[j]){
                if(dp[j]!=-INF && dp[i] <= dp[j]+1){
                    dp[i] = dp[j]+1;
                    max_val = max(max_val, dp[i]);
                    pre[i] = j;
                }
            }
        }
    }
    for(int i=0; i<original.size(); i++){
        cout<<dp[i]<<" ";
    }cout<<endl;
    
    int tmp = INF;
    int pos = -1;
    cout<<"max_val and cnt are "<<max_val<<" "<<cnt<<endl;
    for(int i=0; i<original.size(); i++){
        if(original[i]==lastLetter&&dp[i]==max_val && dp[i] == cnt){
            int t_p = i;
            while(pre[t_p]!=-1){
                t_p = pre[t_p];
            }
            int len =  (i - t_p)+1;
            if(len <= tmp){
                tmp = len;
                pos = i;
            }
        }
    }
    
    cout<<"should start at "<<pos<<endl;
    int t_p = pos;
    if(pos==-1){
        return "";
    }else{
        string should_return = original;
        for(int i=0; i<should_return.size(); i++)should_return[i]='.';
        while(pre[t_p]!=-1){
            should_return[t_p] = original[t_p];
            t_p = pre[t_p];
        }
        should_return[t_p] = original[t_p]; 
        return should_return;
    }
    
    return "";
}
double test0() {
	string p0 = "ABBBXCXABCX";
	MakeUnique * obj = new MakeUnique();
	clock_t start = clock();
	string my_answer = obj->eliminated(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = ".......ABCX";
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
	string p0 = "ABBBXCXABCB";
	MakeUnique * obj = new MakeUnique();
	clock_t start = clock();
	string my_answer = obj->eliminated(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "A..B.CX....";
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
	string p0 = "ABBBXCABCB";
	MakeUnique * obj = new MakeUnique();
	clock_t start = clock();
	string my_answer = obj->eliminated(p0);
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
	string p0 = "AABACBXABX";
	MakeUnique * obj = new MakeUnique();
	clock_t start = clock();
	string my_answer = obj->eliminated(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = ".AB.C.X...";
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
	string p0 = "CABDEAFDEGSDABCDEADFGSEFBGS";
	MakeUnique * obj = new MakeUnique();
	clock_t start = clock();
	string my_answer = obj->eliminated(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "............ABCDE..FGS.....";
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
	string p0 = "AAAAAA";
	MakeUnique * obj = new MakeUnique();
	clock_t start = clock();
	string my_answer = obj->eliminated(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = ".....A";
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
