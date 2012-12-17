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

class PlatypusPaternity {
    public:
            int maxFamily(vector <string>, vector <string>, vector <string>);
};

int PlatypusPaternity::maxFamily(vector <string> femaleCompatibility, vector <string> maleCompatibility, vector <string> siblingGroups) {
    
    int ans = 0;
    for(int i=0; i<femaleCompatibility.size(); i++){
        for(int j=0; j<maleCompatibility.size(); j++){
            for(int k=0; k<siblingGroups.size(); k++){
                int t_sum = 0;
                for(int p=0; p<siblingGroups[0].size(); p++){
                    if(femaleCompatibility[i][p]=='Y' && maleCompatibility[j][p]=='N' ){
                        if(siblingGroups[k][p]=='Y'){
                            t_sum = 0;
                            break;
                        }
                    }else if(femaleCompatibility[i][p]=='N' && maleCompatibility[j][p]=='Y'){
                        if(siblingGroups[k][p]=='Y'){
                            t_sum=0;break;
                        }
                    }else if(femaleCompatibility[i][p]=='N' && maleCompatibility[j][p]=='N'){
                        if(siblingGroups[k][p]=='Y'){
                            t_sum = 0;
                            break;
                        }
                    }else{
                        if(siblingGroups[k][p]=='Y'){
                            t_sum++;
                        }
                    }
                }
                if(t_sum > ans){
                    ans = t_sum;
                }
            }
        }
    }
    if(ans==0){
        return 0;
    }else{
        return ans+2;
    }
}

double test0() {
	string t0[] = {"YYYY", "YYYY"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"NNYN", "YYYN"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	string t2[] = {"YYYN", "NNNY"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	PlatypusPaternity * obj = new PlatypusPaternity();
	clock_t start = clock();
	int my_answer = obj->maxFamily(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 5;
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
	string t0[] = {"NNYYY"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"YYNNN"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	string t2[] = {"YYNNN", "NNYYY"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	PlatypusPaternity * obj = new PlatypusPaternity();
	clock_t start = clock();
	int my_answer = obj->maxFamily(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 0;
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
	string t0[] = {"YYYYYYYYN"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"YYYYYYYYY"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	string t2[] = {"YNYNYNYNY",
 "NNNYNYNNN",
 "NYNNNNNYN"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	PlatypusPaternity * obj = new PlatypusPaternity();
	clock_t start = clock();
	int my_answer = obj->maxFamily(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 4;
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
	string t0[] = {"YY"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"YY"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	string t2[] = {"YN", "NY"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	PlatypusPaternity * obj = new PlatypusPaternity();
	clock_t start = clock();
	int my_answer = obj->maxFamily(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 3;
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
double test4() {
	string t0[] = {"YYNNYYNNYYNN",
 "YNYNYNYNYNYN",
 "YYYNNNYYYNNN"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"NYYNNYYNNYYN",
 "YYNYYYNYYYNY",
 "NNNNNNYYYYYY"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	string t2[] = {"NYNNNYNNNNNN",
 "NNNNNNNNYNNN",
 "NNYNNNNNNNYN",
 "YNNNNNNYNNNN",
 "NNNNNNNNNYNY",
 "NNNYYNYNNNNN"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	PlatypusPaternity * obj = new PlatypusPaternity();
	clock_t start = clock();
	int my_answer = obj->maxFamily(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 4;
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
	
	time = test4();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

