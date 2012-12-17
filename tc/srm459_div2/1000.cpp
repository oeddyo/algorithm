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

class ParkAmusement {
    public:
        double getProbability(vector <string>, int, int);
};

const int MAXN = 51;
double dp[MAXN][MAXN];
int counts[MAXN];
double ParkAmusement::getProbability(vector <string> landings, int startLanding, int K) {
    for(int i=0; i<MAXN; i++)for(int j=0; j<MAXN; j++)dp[i][j] = 0.0;

    int sz = landings.size();
    for(int i=0; i<sz; i++){
        int cnt = 0;
        for(int j=0; j<sz; j++){
            if(landings[i][j]=='1')cnt++;
        }
        counts[i] = cnt;
        cout<<"count["<<i<<"]="<<counts[i]<<endl;
    }

    for(int i=0; i<sz; i++){
        bool ok = false;
        for(int j=0; j<sz; j++){
            if(landings[i][j]=='E')
                ok = true;
        }
        if(ok)
            dp[i][0] = 1.0;
    }
    
        
    for(int s = 1; s<=K; s++){
        for(int pre = 0; pre<sz; pre++){
            for(int cur = 0; cur<sz; cur++){
                if(landings[cur][pre]=='1'){
                    dp[cur][s] += dp[pre][s-1]* (1.0/counts[cur]);
                }
            }
        }
    }
    double ans = 0.0;
    for(int i=0; i<sz; i++){
        ans+=dp[i][K];
    }
    ans = 1.0*dp[startLanding][K]/ans;
    return ans;
}
double test0() {
    string t0[] = {"E000",
        "1000",
        "1000",
        "1000"};
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    int p1 = 1;
    int p2 = 1;
    ParkAmusement * obj = new ParkAmusement();
    clock_t start = clock();
    double my_answer = obj->getProbability(p0, p1, p2);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    double p3 = 0.3333333333333333;
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
    string t0[] = {"E000",
        "1000",
        "1001",
        "000P"};
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    int p1 = 1;
    int p2 = 1;
    ParkAmusement * obj = new ParkAmusement();
    clock_t start = clock();
    double my_answer = obj->getProbability(p0, p1, p2);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    double p3 = 0.6666666666666666;
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
    string t0[] = {"01000100",
        "00111000",
        "00001010",
        "000E0000",
        "0000E000",
        "00000P00",
        "000000P0",
        "01000000"};
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    int p1 = 1;
    int p2 = 2;
    ParkAmusement * obj = new ParkAmusement();
    clock_t start = clock();
    double my_answer = obj->getProbability(p0, p1, p2);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    double p3 = 0.14285714285714288;
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
    string t0[] = {"0100",
        "0010",
        "0001",
        "000E"};
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    int p1 = 0;
    int p2 = 2;
    ParkAmusement * obj = new ParkAmusement();
    clock_t start = clock();
    double my_answer = obj->getProbability(p0, p1, p2);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    double p3 = 0.0;
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
    string t0[] = {"E00",
        "0E0",
        "010"};
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    int p1 = 0;
    int p2 = 1;
    ParkAmusement * obj = new ParkAmusement();
    clock_t start = clock();
    double my_answer = obj->getProbability(p0, p1, p2);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    double p3 = 0.0;
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

