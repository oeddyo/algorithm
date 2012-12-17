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

class OnTime {
    public:
        int minCost(int, int, vector <string>);
};

const int MAXN = 51;
const int MAXT = 10001;
int dp[MAXN][MAXT];
const int INF = 999999999;

//int g[MAXN][MAXN][3];

typedef struct n{
    int station,dep,time,cost;
}node;
vector <node> g[MAXN];

int OnTime::minCost(int N, int T, vector <string> buses) {
    for(int i=0; i<MAXN; i++)for(int j=0; j<MAXT; j++)dp[i][j] = INF;
    dp[0][0] = 0;
    for(int i=0; i<MAXN; i++)g[i].clear();
    //memset(g,-1,sizeof(g));
    node tmp_node; 
    for(int i=0; i<buses.size(); i++){
        istringstream is(buses[i]);
        int a,b,dep,time,cost;
        is>>a>>b>>dep>>time>>cost;
        /*g[a][b][0] = dep;
        g[a][b][1] = time;
        g[a][b][2] = cost;*/
        tmp_node.station = b;
        tmp_node.dep = dep;
        tmp_node.time = time;
        tmp_node.cost = cost;
        g[a].push_back(tmp_node);
    }

    //start [0][0]
    for(int i=0; i<g[0].size(); i++){
        int nt = g[0][i].dep+g[0][i].time;
        int c = g[0][i].cost;
        int ns = g[0][i].station;
        dp[ns][nt] = min(dp[ns][nt],dp[0][0]+c);
    }

    for(int cur_t=0; cur_t<=T; cur_t++){
        for(int i=0; i<N; i++){
            if(dp[i][cur_t] == INF)continue;
            //for(int next_s=0; next_s<N; next_s++){
            for(int j=0; j<g[i].size(); j++){
                if(cur_t < g[i][j].dep){
                //if(g[i][next_s][0]!=INF && (cur_t<g[i][next_s][0])){
                    int next_s = g[i][j].station;
                    int nt = g[i][j].dep + g[i][j].time;
                    //int nt = g[i][next_s][0] + g[i][next_s][1];
                    int cost = dp[i][cur_t] + g[i][j].cost;
                    //int cost = dp[i][cur_t]+g[i][next_s][2];
                    //
                    dp[next_s][nt] = min(dp[next_s][nt], cost);
                }
            }
        }
    }
    int ans = INF;
    for(int i=0; i<=T; i++){
        ans = min(ans, dp[N-1][i]);
        cout<<"dp["<<N-1<<"]["<<i<<"] = "<<dp[N-1][i]<<endl;
    }
    if(ans==INF)return -1;
    return ans;
}
double test0() {
    int p0 = 3;
    int p1 = 8;
    string t2[] = {"0 1 0 4 3", "1 2 5 3 4"};
    vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
    OnTime * obj = new OnTime();
    clock_t start = clock();
    int my_answer = obj->minCost(p0, p1, p2);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p3 = 7;
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
    int p0 = 3;
    int p1 = 8;
    string t2[] = {"0 1 0 4 3", "1 2 6 3 4"};
    vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
    OnTime * obj = new OnTime();
    clock_t start = clock();
    int my_answer = obj->minCost(p0, p1, p2);
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
    int p0 = 3;
    int p1 = 7;
    string t2[] = {"0 1 0 5 1", "1 2 6 1 40", "0 1 1 2 5", "1 2 4 2 5"};
    vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
    OnTime * obj = new OnTime();
    clock_t start = clock();
    int my_answer = obj->minCost(p0, p1, p2);
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
double test3() {
    int p0 = 3;
    int p1 = 8;
    string t2[] = {"0 1 0 5 3", "1 2 5 3 4"};
    vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
    OnTime * obj = new OnTime();
    clock_t start = clock();
    int my_answer = obj->minCost(p0, p1, p2);
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
double test4() {
    int p0 = 3;
    int p1 = 100;
    string t2[] = {"0 1 0 1 1"};
    vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
    OnTime * obj = new OnTime();
    clock_t start = clock();
    int my_answer = obj->minCost(p0, p1, p2);
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
double test5() {
    int p0 = 9;
    int p1 = 100;
    string t2[] = {"0 3 1 6 15", "0 6 0 23 20", "6 2 25 15 30", "6 1 30 15 40", "3 1 15 35 10", 
        "3 2 30 80 40", "1 5 55 25 25", "1 2 49 31 10", "2 8 85 10 10", "5 8 83 15 5"};
    vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
    OnTime * obj = new OnTime();
    clock_t start = clock();
    int my_answer = obj->minCost(p0, p1, p2);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p3 = 55;
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

    time = test5();
    if (time < 0)
        errors = true;

    if (!errors)
        cout <<"You're a stud (at least on the example cases)!" <<endl;
    else
        cout <<"Some of the test cases had errors." <<endl;
}

