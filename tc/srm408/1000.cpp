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

class MarblesInABag {
    public:
        double getProbability(int, int);
};

const int MAXN = 4001;
//double dp[MAXN][MAXN];
double dp[2][MAXN];
const double INF = 99999999.9;
void print(int r, int b){
    for(int i=0; i<2; i++){
        for(int j=0; j<=b; j++){
            cout<<dp[i][j]<<"\t";
        }cout<<endl;
    }
}


double run_dp(int r, int b){
    memset(dp,0,sizeof(dp));
    for(int i=1; i<MAXN; i++){
        //dp[i][0] = 0.0;
        dp[0][i] = 1.0;
    }
    dp[1][0] = 0.0;
    
    dp[0][0] = 0.0;
    
    //print(r,b);
    cout<<"!!! "<<dp[1][2]<<endl;
    for(int i=0; i<=r; i++){
        for(int j=0; j<=b; j++){
            if( (1&(i+j)) == 1 ){
                if((i-1)>=0 && j-1>=0){
                
                    dp[i%2][j] = dp[(i-1)%2][j]*(i*1.0/(i+j)) + dp[i%2][j-1]*(j*1.0/(i+j));
                    //cout<<"in a "<<i<<" "<<j<<endl;    
                    
                    //cout<<"dp["<<(i-1)%2<<"]["<<j<<"]="<<dp[(i-1)%2][j]<<" dp["<<i%2<<"]["<<j-1<<"]="<<dp[i%2][j-1]<<endl;
                    //print(r,b);
                }
            }else{
                if(j-1>=0){
                    //cout<<"in b "<<i<<" "<<j<<endl;
                    dp[i%2][j] = dp[i%2][j-1];
                    //cout<<i%2<<" "<<j<<" "<<dp[i%2][j]<<endl;
                    //print(r,b);
                }
            }
        }
    }
    return dp[r%2][b];
}

/*
float get_dp(int r, int b, bool turn){
    if(dp[r][b]!=INF){
        return dp[r][b];
    }
    if(b==0 && r==0){
        return 0.0;
    }else if(b==0){
        return 1.0;
    }
    double ans;
    if( turn == 0 ){
        ans = (r*1.0/(r+b))*get_dp(r-1, b, 1) + (b*1.0/(r+b))*get_dp(r,b-1,1);
        dp[r][b] = ans;
        return dp[r][b];
    }else{
        ans = get_dp(r, b-1, 0);
        return ans;
    }
}
*/


double MarblesInABag::getProbability(int redCount, int blueCount) {
    /*
    for(int i=0; i<MAXN; i++){
        for(int j=0; j<MAXN; j++){
            dp[i%2][j] = 0.0;
        }
    }
    */
    cout<<"ok"<<endl;
    return run_dp(redCount,blueCount);
    //return 1-get_dp(redCount, blueCount,0);

}


double test0() {
    int p0 = 1;
    int p1 = 2;
    MarblesInABag * obj = new MarblesInABag();
    clock_t start = clock();
    double my_answer = obj->getProbability(p0, p1);
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
double test1() {
    int p0 = 2;
    int p1 = 3;
    MarblesInABag * obj = new MarblesInABag();
    clock_t start = clock();
    double my_answer = obj->getProbability(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    double p2 = 0.13333333333333333;
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
    int p0 = 2;
    int p1 = 5;
    MarblesInABag * obj = new MarblesInABag();
    clock_t start = clock();
    double my_answer = obj->getProbability(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    double p2 = 0.22857142857142856;
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
    int p0 = 11;
    int p1 = 6;
    MarblesInABag * obj = new MarblesInABag();
    clock_t start = clock();
    double my_answer = obj->getProbability(p0, p1);
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
    int p0 = 4;
    int p1 = 11;
    MarblesInABag * obj = new MarblesInABag();
    clock_t start = clock();
    double my_answer = obj->getProbability(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    double p2 = 0.12183372183372182;
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

