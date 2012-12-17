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

class MonstersAndBunnies {
    public:
        double survivalProbability(int, int);
};

const int MAXN = 1001;;
double dp[MAXN][MAXN][2];
const double INF = 999999999;
double get_dp(int m, int b, int p){
    if(p==0){
        return 0.0;
    }
    if(p==1 && m==0){
        return 1.0;
    }
    if(dp[m][b][p]!=INF){
        return dp[m][b][p];
    }
    //monster meet
        
    double s = 0.0;
    double t;
    if(m>=2){
        t = 1.0*m*(m-1)/(1.0*(m+b+1)*(m+b));
        s += (t*get_dp(m-2,b,p));
        cout<<m<<" "<<b<<" "<<p<<" first t "<<t*get_dp(m-2,b,p)<<endl;
    }
    //monster meet bunny
    if(m>=1 && b>=1){
        t = 1.0*m*b/(1.0*(m+b+1)*(m+b));
        s += t*get_dp(m,b-1,p);
        cout<<"t is "<<t<<" and get_dp(m,b-1,p) is "<<get_dp(m,b-1,p)<<endl;
        cout<<m<<" "<<b<<" "<<p<<" second t "<<t*get_dp(m,b-1,p)<<endl;
    }
    if(b>=1&&p>=1){
        t = 1.0*m*b/(1.0*(m+b+1)*(m+b));
        s += t*get_dp(m,b-1,p);
        cout<<m<<" "<<b<<" "<<p<<" third t "<<t*get_dp(m,b-1,p)<<endl;
    }

    //monster meet people
    if(m>=1 && p>=1){
        t = 1.0*m/(1.0*(m+b+1)*(m+b));
        s += (t*get_dp(m,b,p-1));
        cout<<m<<" "<<b<<" "<<p<<" fourth t "<<t*get_dp(m,b,p-1)<<endl;
    }
    //people meet bunny
    /*
    if(p>=1 && b>=1){
        t = 1.0*b/(1.0*(m+b+1)*(m+b));
        s += (t*get_dp(m,b-1,p));
    }
    */
    dp[m][b][p] = s;
    return s;
}

double MonstersAndBunnies::survivalProbability(int M, int B) {
    for(int i=0; i<MAXN; i++)for(int j=0; j<MAXN; j++)for(int k=0; k<2; k++)dp[i][j][k]=INF;

    double ans = get_dp(M,B,1);
    return ans;

}
double test0() {
    int p0 = 4;
    int p1 = 1;
    MonstersAndBunnies * obj = new MonstersAndBunnies();
    clock_t start = clock();
    double my_answer = obj->survivalProbability(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    double p2 = 0.2;
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
    int p0 = 0;
    int p1 = 47;
    MonstersAndBunnies * obj = new MonstersAndBunnies();
    clock_t start = clock();
    double my_answer = obj->survivalProbability(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    double p2 = 1.0;
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
    int p0 = 1;
    int p1 = 0;
    MonstersAndBunnies * obj = new MonstersAndBunnies();
    clock_t start = clock();
    double my_answer = obj->survivalProbability(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    double p2 = 0.0;
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
    int p0 = 1;
    int p1 = 47;
    MonstersAndBunnies * obj = new MonstersAndBunnies();
    clock_t start = clock();
    double my_answer = obj->survivalProbability(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    double p2 = 0.0;
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
    int p0 = 2;
    int p1 = 0;
    MonstersAndBunnies * obj = new MonstersAndBunnies();
    clock_t start = clock();
    double my_answer = obj->survivalProbability(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    double p2 = 0.3333333333333333;
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

