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

class Circuits {
    public:
            int howLong(vector <string>, vector <string>);
};

const int MAXN = 51;
//bool vis[MAXN];
int vis[MAXN];
int t_max;
const int INF = 99999999;
int g[MAXN][MAXN];
int sz;
/*void dfs(int cur, int dep){
    if(vis[cur]){
        return ;
    }
    if(dep>t_max){
        t_max = dep;
    }
    vis[cur] = true;
    int tt_max = -INF;
    for(int i=0; i<sz; i++){
        if(g[cur][i]!=-INF){
            dfs(i,dep+g[cur][i]);
        }    
    }
    vis[cur] = false;
}
*/
int dfs(int cur){
    if(vis[cur]!=-1)return vis[cur];
    cout<<"cur at "<<cur<<endl;
    int t_max = -INF;
    for(int i=0; i<sz; i++){
        if(g[cur][i]!=-INF){
            t_max = max(t_max, dfs(i)+g[cur][i]);
        }
    }
    cout<<"now t_max is "<<t_max<<endl;
    if(t_max==-INF){
        vis[cur] = 0;
        return 0;
    }else{
        vis[cur] = t_max;
        return t_max;
    }
}


int Circuits::howLong(vector <string> connects, vector <string> costs) {
    for(int i=0; i<MAXN; i++)for(int j=0; j<MAXN; j++)g[i][j]=-INF;

    sz = connects.size();
    for(int i=0; i<sz; i++){
        istringstream is(connects[i]);
        istringstream is2(costs[i]);
        int a,t;
        while(is>>a){
            is2>>t;
            g[i][a] = t;
        }
    }

    t_max = -INF;
    for(int i=0; i<sz; i++){
        //memset(vis,-1,sizeof(vis));
        for(int j=0; j<MAXN; j++)vis[j]=-1;
        //dfs(i,0);
        //dfs(i,0);
        t_max = max(t_max, dfs(i));
    }

    if(t_max==-INF)return -1;

    return t_max;
}
double test0() {
	string t0[] = {"1 2",
 "2",
 ""};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"5 3",
 "7",
 ""};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	Circuits * obj = new Circuits();
	clock_t start = clock();
	int my_answer = obj->howLong(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 12;
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
	string t0[] = {"1 2 3 4 5","2 3 4 5","3 4 5","4 5","5",""};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"2 2 2 2 2","2 2 2 2","2 2 2","2 2","2",""};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	Circuits * obj = new Circuits();
	clock_t start = clock();
	int my_answer = obj->howLong(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 10;
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
	string t0[] = {"1","2","3","","5","6","7",""};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"2","2","2","","3","3","3",""};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	Circuits * obj = new Circuits();
	clock_t start = clock();
	int my_answer = obj->howLong(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 9;
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
	string t0[] = {"","2 3 5","4 5","5 6","7","7 8","8 9","10",
 "10 11 12","11","12","12",""};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"","3 2 9","2 4","6 9","3","1 2","1 2","5",
 "5 6 9","2","5","3",""};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	Circuits * obj = new Circuits();
	clock_t start = clock();
	int my_answer = obj->howLong(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 22;
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
	string t0[] = {"","2 3","3 4 5","4 6","5 6","7","5 7",""};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"","30 50","19 6 40","12 10","35 23","8","11 20",""};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	Circuits * obj = new Circuits();
	clock_t start = clock();
	int my_answer = obj->howLong(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 105;
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

