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

class RevealTriangle {
    public:
            vector <string> calcTriangle(vector <string>);
};
int sz;
bool find_mark(vector <string> &s){
    for(int i=0; i<sz; i++){
        if(s[i].find("?")!=string::npos){
            return true;
        }
    }
    return false;
}


vector <string> RevealTriangle::calcTriangle(vector <string> questionMarkTriangle) {
    sz = questionMarkTriangle.size();
    vector <string> q = questionMarkTriangle;
    while(1){
        for(int i=0; i<sz;i++){
            cout<<q[i]<<endl;
        }
        if(!find_mark(q)){
            break;
        }


        for(int i=0; i<sz; i++){
            int len = q[i].size();
            for(int j=0; j<len; j++){
                if(q[i][j]=='?'){
                    int a,b,c,ok=0;
                    if(i-1>=0 && j+1<len && q[i-1][j]!='?' && q[i-1][j+1]!='?'){
                        a = q[i-1][j]-'0';
                        b = q[i-1][j+1]-'0';
                        c = (a+b>10)?(a+b-10):(a+b);
                        ok=1;
                    }else if(j+1<len && i+1<sz && q[i][j+1]!='?' && q[i+1][j]!='?'){
                        a = q[i][j+1]-'0';
                        b = q[i+1][j]-'0';
                        c = (b-a)>=0?(b-a):(b-a+10);
                        ok=1;
                    }else if(j-1>=0 && i+1<sz && q[i][j-1]!='?' && q[i+1][j-1]!='?'){
                        a = q[i][j-1]-'0';
                        b = q[i+1][j-1]-'0';
                        c = (b-a)>=0?(b-a):(b-a+10);
                        ok=1;
                    }
                    if(ok==1){
                        q[i][j] = c+'0';
                    }
                }
            }
        }
    }
    return q;
}
double test0() {
	string t0[] = {"4??", 
 "?2", 
 "1"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	RevealTriangle * obj = new RevealTriangle();
	clock_t start = clock();
	vector <string> my_answer = obj->calcTriangle(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string t1[] = {"457", "92", "1" };
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p1.size() > 0) {
		cout <<"\""<<p1[0]<<"\"";
		for (int i=1; i<p1.size(); i++)
			cout <<", \"" <<p1[i]<<"\"";
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<"\""<<my_answer[0]<<"\"";
		for (int i=1; i<my_answer.size(); i++)
			cout <<", \"" <<my_answer[i]<<"\"";
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p1) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	string t0[] = {"1"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	RevealTriangle * obj = new RevealTriangle();
	clock_t start = clock();
	vector <string> my_answer = obj->calcTriangle(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string t1[] = {"1" };
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p1.size() > 0) {
		cout <<"\""<<p1[0]<<"\"";
		for (int i=1; i<p1.size(); i++)
			cout <<", \"" <<p1[i]<<"\"";
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<"\""<<my_answer[0]<<"\"";
		for (int i=1; i<my_answer.size(); i++)
			cout <<", \"" <<my_answer[i]<<"\"";
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p1) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	string t0[] = {"???2", "??2", "?2", "2"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	RevealTriangle * obj = new RevealTriangle();
	clock_t start = clock();
	vector <string> my_answer = obj->calcTriangle(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string t1[] = {"0002", "002", "02", "2" };
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p1.size() > 0) {
		cout <<"\""<<p1[0]<<"\"";
		for (int i=1; i<p1.size(); i++)
			cout <<", \"" <<p1[i]<<"\"";
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<"\""<<my_answer[0]<<"\"";
		for (int i=1; i<my_answer.size(); i++)
			cout <<", \"" <<my_answer[i]<<"\"";
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p1) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	string t0[] = {"??5?", "??9", "?4", "6"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	RevealTriangle * obj = new RevealTriangle();
	clock_t start = clock();
	vector <string> my_answer = obj->calcTriangle(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string t1[] = {"7054", "759", "24", "6" };
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p1.size() > 0) {
		cout <<"\""<<p1[0]<<"\"";
		for (int i=1; i<p1.size(); i++)
			cout <<", \"" <<p1[i]<<"\"";
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<"\""<<my_answer[0]<<"\"";
		for (int i=1; i<my_answer.size(); i++)
			cout <<", \"" <<my_answer[i]<<"\"";
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p1) {
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
