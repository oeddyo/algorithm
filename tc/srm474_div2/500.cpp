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
#include <queue>
using namespace std;

class TreesCount {
    public:
            int count(vector <string>);
};
const int MAXN = 51;
int g[MAXN][MAXN];
int dp[MAXN][MAXN];
const int INF = 99999999;
int d[MAXN];
int vis_edge[MAXN][MAXN];
int vis_node[MAXN];

int TreesCount::count(vector <string> graph) {
    for(int i=0; i<graph.size(); i++){
        for(int j=0; j<graph[i].size(); j++){
            g[i][j] = graph[i][j]-'0';
            cout<<g[i][j]<<" ";
            /*if(g[i][j]==0){
                g[i][j] = INF;
            }*/
            dp[i][j]=g[i][j];
        }cout<<endl;
    }
    //bellman here
    int sz = graph.size();

    for(int k=0; k<sz; k++){
        for(int i=0; i<sz; i++){
            for(int j=0; j<sz; j++){
                dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]);
            }
        }
    }

    for(int i=0; i<sz; i++){
        for(int j=0; j<sz; j++){
            cout<<dp[i][j]<<" ";
        }cout<<endl;
    }
    memset(vis_edge,0,sizeof(vis_edge));
    memset(vis_node,0,sizeof(vis_node));
    memset(d,0,sizeof(d));
    long long int ans=0;
    queue<int> Q;
    Q.push(0);
    d[0]=1;
    //vis_node[cur] = 1;
    while(!Q.empty()){
        int cur = Q.front();
        Q.pop();
        cout<<"at "<<cur<<endl;
        for(int i=0; i<sz; i++){
            cout<<"seeing "<<i<<" and g[cur][i] is "<<g[cur][i]<<", dp[0][cur] is "<<dp[0][cur]<<" dp[0][i] is "<<dp[0][i]<<endl;
            if(i!=cur&&vis_edge[cur][i]==0&&g[cur][i]!=INF&&dp[0][i]<INF&&dp[0][cur]<INF&&g[cur][i] + dp[0][cur] == dp[0][i]){
                cout<<"ok in"<<endl;
                //if(vis_node[i]==0){
                    d[i]+=d[cur];
                    d[i]%=1000000007LL;
                    Q.push(i);
                    vis_edge[cur][i] = 1;
                    vis_edge[i][cur] = 1;
                    //vis_node[i][cur] = 1;
                    cout<<"now d[i] is "<<d[i]<<endl;
               // }
            }
        }
    }
    for(int i=1; i<sz; i++){
        ans+=d[i];
        ans%=1000000007LL;
        cout<<i<<" "<<d[i]<<endl;
    }
    return ans;
}

double test0() {
	string t0[] = {"01",
 "10"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	TreesCount * obj = new TreesCount();
	clock_t start = clock();
	int my_answer = obj->count(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 1;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
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
	string t0[] = {"011",
 "101",
 "110"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	TreesCount * obj = new TreesCount();
	clock_t start = clock();
	int my_answer = obj->count(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 1;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
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
	string t0[] = {"021",
 "201",
 "110"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	TreesCount * obj = new TreesCount();
	clock_t start = clock();
	int my_answer = obj->count(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 2;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
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
	string t0[] = {"0123",
 "1012",
 "2101",
 "3210"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	TreesCount * obj = new TreesCount();
	clock_t start = clock();
	int my_answer = obj->count(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 6;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
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
	string t0[] = {"073542",
 "705141",
 "350721",
 "517031",
 "442304",
 "211140"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	TreesCount * obj = new TreesCount();
	clock_t start = clock();
	int my_answer = obj->count(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 2;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
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
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
