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

class CompanyMessages {
    public:
        vector <int> getRank(vector <string>);
};

const int MAXN = 16;
int dp[1<<MAXN];
int trace[1<<MAXN];
int tr[1<<MAXN];
const int INF = 99999999;
vector <int> ans;
void print_trace(int p){
    if(trace[p]==-1){
        return ;
    }
    print_trace(trace[p]);
    //cout<<tr[p]<<" ";
    ans.push_back(tr[p]);
}
vector <int> CompanyMessages::getRank(vector <string> messages) {
    ans.clear();
    for(int i=0; i<(1<<MAXN); i++){dp[i] = INF;trace[i]=-1;}
    int sz = messages.size();
    dp[0] = 0;
    for(int s=0; s<((1<<sz)); s++){
        //if(dp[s]==INF)continue;
        for(int i=0; i<sz; i++){
            if( ((s>>i)&1) == 1){
                //int ns = (1<<i)|s;
                int add = 0;
                for(int j=0; j<sz; j++){
                    if( ((s>>j)&1)==1){
                        add += messages[j][i]-'0';
                    }
                }
                //int ps = (~(1<<i))&s;
                int ps = (s ^ (1<<i));
                if(dp[s] > dp[ps]+add){
                    dp[s] = dp[ps]+add;
                    trace[s] = i;
                }
                /*
                if(dp[ns]>dp[s]+add){
                    dp[ns] = dp[s]+add;
                    trace[ns] = i;
                }
                */
                //dp[ns] = min(dp[ns], dp[s]+add);
                //cout<<"dp["<<ns<<"]="<<dp[ns]<<endl;
            }
        }
    }
    int p = (1<<sz)-1;
    while(trace[p]!=-1){
        ans.push_back(trace[p]);
        p = p ^(1<<trace[p]);
    }
    cout<<dp[(1<<sz)-1]<<endl;
    //print_trace( (1<<sz)-1);
    vector <int> pp;
    return ans;
}

double test0() {
/*	string t0[] = {"000",
 "000",
 "000"};
  */  string t0[] = {"044454", "404434", "140444", "443044", "244404", "443440"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	CompanyMessages * obj = new CompanyMessages();
	clock_t start = clock();
	vector <int> my_answer = obj->getRank(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t1[] = {0,2,3,4,1,5 };
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p1.size() > 0) {
		cout <<p1[0];
		for (int i=1; i<p1.size(); i++)
			cout <<", " <<p1[i];
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
	string t0[] = {"000",
 "100",
 "010"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	CompanyMessages * obj = new CompanyMessages();
	clock_t start = clock();
	vector <int> my_answer = obj->getRank(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t1[] = {2, 1, 0 };
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p1.size() > 0) {
		cout <<p1[0];
		for (int i=1; i<p1.size(); i++)
			cout <<", " <<p1[i];
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
	string t0[] = {"012105","601745","830479","043086","349904","649810"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	CompanyMessages * obj = new CompanyMessages();
	clock_t start = clock();
	vector <int> my_answer = obj->getRank(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t1[] = {4, 2, 1, 5, 0, 3 };
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p1.size() > 0) {
		cout <<p1[0];
		for (int i=1; i<p1.size(); i++)
			cout <<", " <<p1[i];
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
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
