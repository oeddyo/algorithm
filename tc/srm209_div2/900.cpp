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

class LoadBalancing {
    public:
        int minTime(vector <int>);
};
const int MAXN = 51;
const int MMAX = 4097;
bool dp[MAXN][MMAX*50][2];

int LoadBalancing::minTime(vector <int> chunkSizes) {
    memset(dp,0,sizeof(dp));
    int sz = chunkSizes.size();
    if(sz==0)return 0;
    for(int i=0; i<sz; i++){
        chunkSizes[i]/=1024;
    }
    dp[0][chunkSizes[0]][0] = 1;
    dp[0][0][1] = 1;
    dp[0][chunkSizes[0]][1] = 1;
    dp[0][0][0] = 1;
    
    int all_sum = accumulate(chunkSizes.begin(), chunkSizes.end(), 0);
    for(int i=1; i<sz; i++){
        for(int k=0; k<=all_sum; k++){
            for(int j=0; j<2; j++){
                int cur_size = chunkSizes[i];
                if(k-cur_size>=0){
                    if(dp[i-1][k-cur_size][j]){
                        dp[i][k][j] = 1;
                        dp[i][k-cur_size][1-j] = 1;
                        /*
                        cout<<"dp["<<i<<"]["<<k<<"]["<<j<<"]=1"<<endl;
                        cout<<"dp["<<i<<"]["<<k-cur_size<<"]["<<1-j<<"]=1"<<endl;
                        */
                    }
                }
            }
        }
    }
    int ans = 2000000000;
    for(int i=0; i<=all_sum; i++){
        for(int j=0; j<2; j++){
        if(dp[sz-1][i][j]){
            if(all_sum-i>=0){
                if(dp[sz-1][all_sum-i][1-j]){
                    ans = min(ans, max(all_sum-i,i));
                }
            }
        }
        }
    }
    /*
    cout<<"all_sum is "<<all_sum<<endl;
    cout<<"first ans is "<<ans<<endl;
    */
    return ans*1024;
}
double test0() {
    int t0[] = {3072, 3072, 7168, 3072, 1024};
    vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
    LoadBalancing * obj = new LoadBalancing();
    clock_t start = clock();
    int my_answer = obj->minTime(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p1 = 9216;
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
    int t0[] = {2048};
    vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
    LoadBalancing * obj = new LoadBalancing();
    clock_t start = clock();
    int my_answer = obj->minTime(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p1 = 2048;
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
    int t0[] = {2048, 1024, 1024, 2048};
    vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
    LoadBalancing * obj = new LoadBalancing();
    clock_t start = clock();
    int my_answer = obj->minTime(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p1 = 3072;
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
    int t0[] = {4194304, 4194304, 4194304, 4194304, 4194304,
        4194304, 4194304, 4194304, 4194304, 4194304,
        4194304, 4194304, 4194304, 4194304, 4194304,
        4194304, 4194304, 4194304, 4194304, 4194304,
        4194304, 4194304, 4194304, 4194304, 4194304,
        4194304, 4194304, 4194304, 4194304, 4194304,
        4194304, 4194304, 4194304, 4194304, 4194304,
        4194304, 4194304, 4194304, 4194304, 4194304,
        4194304, 4194304, 4194304, 4194304, 4194304,
        4194304, 4194304, 4194304, 4194304, 4194304};
    vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
    LoadBalancing * obj = new LoadBalancing();
    clock_t start = clock();
    int my_answer = obj->minTime(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p1 = 104857600;
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

    if (!errors)
        cout <<"You're a stud (at least on the example cases)!" <<endl;
    else
        cout <<"Some of the test cases had errors." <<endl;
}

