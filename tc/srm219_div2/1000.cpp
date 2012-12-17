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

class PayBill {
    public:
        vector <int> whoPaid(vector <int>, int);
};

const int MAXN = 500001;
bool dp[MAXN];
int pre[MAXN][2];
vector <int> PayBill::whoPaid(vector <int> meals, int totalMoney) {
    memset(dp,0,sizeof(dp));
    memset(pre,-1,sizeof(pre));
    dp[0] = true;
    for(int i=0; i<meals.size(); i++){
        for(int j=totalMoney; j>=0; j--){
            int p = j-meals[i];
            if(p>=0){
                if(dp[p]&&!dp[j]){
                    dp[j] = true;
                    pre[j][0] = p;
                    pre[j][1] = i;
                }
            }
        }
    }
    int cur = totalMoney; 
    vector<int> ans;
    while(pre[cur][0]!=-1){
        //cout<<"cur is "<<cur<<"-> "<<pre[cur]<<" dif is "<<cur-pre[cur]<<endl;
        ans.push_back(pre[cur][1]);
        cur = pre[cur][0];
    }
    reverse(ans.begin(), ans.end());
    cout<<endl;
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    return ans;
}

double test0() {
    int t0[] = { 1000, 1200, 1300 };
    vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
    int p1 = 2500;
    PayBill * obj = new PayBill();
    clock_t start = clock();
    vector <int> my_answer = obj->whoPaid(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int t2[] = { 1,  2 };
    vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
    cout <<"Desired answer: " <<endl;
    cout <<"\t{ ";
    if (p2.size() > 0) {
        cout <<p2[0];
        for (int i=1; i<p2.size(); i++)
            cout <<", " <<p2[i];
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
    if (my_answer != p2) {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
double test1() {
    int t0[] = { 100, 200, 350 };
    vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
    int p1 = 300;
    PayBill * obj = new PayBill();
    clock_t start = clock();
    vector <int> my_answer = obj->whoPaid(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int t2[] = { 0,  1 };
    vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
    cout <<"Desired answer: " <<endl;
    cout <<"\t{ ";
    if (p2.size() > 0) {
        cout <<p2[0];
        for (int i=1; i<p2.size(); i++)
            cout <<", " <<p2[i];
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
    if (my_answer != p2) {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
double test2() {
    int t0[] = { 150, 200, 350, 400 };
    vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
    int p1 = 900;
    PayBill * obj = new PayBill();
    clock_t start = clock();
    vector <int> my_answer = obj->whoPaid(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int t2[] = { 0,  2,  3 };
    vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
    cout <<"Desired answer: " <<endl;
    cout <<"\t{ ";
    if (p2.size() > 0) {
        cout <<p2[0];
        for (int i=1; i<p2.size(); i++)
            cout <<", " <<p2[i];
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
    if (my_answer != p2) {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
double test3() {
    int t0[] = {6584,6733,6018,5840,2723,4902,4260,
        5375,6745,1234,3000,8222,2472,
        4348,1716,9995,415,1234,2345,5679};
    vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
    int p1 = 70630;
    PayBill * obj = new PayBill();
    clock_t start = clock();
    vector <int> my_answer = obj->whoPaid(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int t2[] = { 0,  1,  3,  4,  5,  6,  8,  9,  11,  13,  14,  15,  16,  17,  19 };
    vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
    cout <<"Desired answer: " <<endl;
    cout <<"\t{ ";
    if (p2.size() > 0) {
        cout <<p2[0];
        for (int i=1; i<p2.size(); i++)
            cout <<", " <<p2[i];
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
    if (my_answer != p2) {
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

