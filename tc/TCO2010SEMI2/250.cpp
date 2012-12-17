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

class YetAnotherRobotSimulation {
    public:
        double getMaximumProbability(int, vector <int>, vector <int>);
};
const int MAXN = 201;
double dp[MAXN][MAXN][52];
const double INF = 999999999;
int dir[5][2] = {{1,0},{-1,0},{0,1},{0,-1}}, magic = 100;
double YetAnotherRobotSimulation::getMaximumProbability(int L, vector <int> locationsX, vector <int> locationsY) {
    for(int i=0; i<MAXN;i++)for(int j=0; j<MAXN; j++)for(int k=0; k<52; k++)
            dp[i][j][k]=0.0;
        
    dp[magic+0][magic+0][0] = 1.0;
    for(int k=0; k<=L; k++){
        for(int i=0; i<MAXN; i++){
            for(int j=0; j<MAXN; j++){
                int cnt=0;
                for(int d=0; d<4; d++){
                    int nx = i+dir[d][0];
                    int ny = j+dir[d][1];
                    if(nx<0||nx>=MAXN||ny<0||ny>=MAXN){
                        continue;
                    }
                    cnt++;
                }
                for(int d=0; d<4; d++){
                    int nx = i+dir[d][0];
                    int ny = j+dir[d][1];
                    if(nx<0||nx>=MAXN||ny<0||ny>=MAXN){
                        continue;
                    }
                    dp[nx][ny][k+1] += dp[i][j][k]*(1.0/cnt)*0.5;
                }
                dp[i][j][k+1] += dp[i][j][k]*0.5;
            }
        }
    }
    double ans = -INF;
    for(int k=1; k<=L; k++){
        for(int i=0; i<MAXN; i++){
            for(int j=0; j<MAXN; j++){
                if(dp[i][j][k]!=0.0)
                    cout<<"dp["<<i-magic<<"]["<<j-magic<<"]["<<k<<"]="<<dp[i][j][k]<<endl;
                }
            }
        }
    double t = 0.0;
    for(int i=0; i<locationsX.size(); i++){
        int x = locationsX[i]+magic;
        int y = locationsY[i]+magic;
        t+=dp[x][y][L];
    }
    cout<<"now t is "<<t<<endl;
    return ans;
}
double test0() {
    int p0 = 3;
    int t1[] = {1,2,2};
    vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
    int t2[] = {1,1,0};
    vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
    YetAnotherRobotSimulation * obj = new YetAnotherRobotSimulation();
    clock_t start = clock();
    double my_answer = obj->getMaximumProbability(p0, p1, p2);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    double p3 = 0.5;
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
    int p0 = 5;
    int t1[] = {0,0,0,0};
    vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
    int t2[] = {0,1,2,3};
    vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
    YetAnotherRobotSimulation * obj = new YetAnotherRobotSimulation();
    clock_t start = clock();
    double my_answer = obj->getMaximumProbability(p0, p1, p2);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    double p3 = 0.9375;
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
    int p0 = 1;
    int t1[] = {0};
    vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
    int t2[] = {0};
    vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
    YetAnotherRobotSimulation * obj = new YetAnotherRobotSimulation();
    clock_t start = clock();
    double my_answer = obj->getMaximumProbability(p0, p1, p2);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    double p3 = 0.5;
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
    int p0 = 8;
    int t1[] = {2,3,3};
    vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
    int t2[] = {1,1,0};
    vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
    YetAnotherRobotSimulation * obj = new YetAnotherRobotSimulation();
    clock_t start = clock();
    double my_answer = obj->getMaximumProbability(p0, p1, p2);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    double p3 = 0.41015625;
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
    int p0 = 36;
    int t1[] = {6,7,12,-21,5,5,2,4};
    vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
    int t2[] = {4,5,-2,4,5,12,5,7} ;
    vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
    YetAnotherRobotSimulation * obj = new YetAnotherRobotSimulation();
    clock_t start = clock();
    double my_answer = obj->getMaximumProbability(p0, p1, p2);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    double p3 = 0.1323284485260956;
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
return 0;
    return 0;
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

