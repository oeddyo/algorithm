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

class CrazyComponents {
    public:
        double expectedProfit(int, vector <string>, vector <int>, vector <int>);
};
typedef  vector<int> vi;
vector< vi > before;

const int MAXN = 51;
const int MAX_STATE = (1<<16);
double dp[MAXN][MAX_STATE];
int before_size[MAXN];
    
double eps = 1e-10;

bool f_equal(double a, double b){
    if( fabs(a-b)<=eps){
        return true;
    }
return false;
}

bool check(int next, int s){
    int t_sz = before_size[next];
    for(int i=0; i<t_sz; i++){
        if(((s>>before[next][i])&1)==0){
            return false;
        }
    }
    return true;
}

vector<double> g_dif;
int g_sz, g_k; 
double calc(int s){
    double t_sum = 0.0;
    int left = g_k;
    for(int i=0; i<g_sz; i++){
        if(((s>>i)&1)){
                t_sum += dp[g_k][s]*g_dif[i];
                left--;
        }
    }
    double mm = -999999999;
    for(int i=0; i<g_dif.size() && ((s>>i)&1); i++){
        mm = max(g_dif[i], mm);
    }
    if(mm>0.0){
        t_sum+= dp[g_k][s]*mm*left;
    }
    return t_sum;
}


double CrazyComponents::expectedProfit(int k, vector <string> components, vector <int> income, vector <int> expense) {
    g_k = k;
    g_dif.clear();
    before.clear();
    for(int i=0; i<income.size(); i++){
        g_dif.push_back(income[i]-expense[i]);
    }
    for(int i=0; i<components.size(); i++){
        istringstream is(components[i]);
        vi tmp_v;
        int t;
        while(is>>t){
            tmp_v.push_back(t);
        }
        before.push_back(tmp_v);
        before_size[i] = tmp_v.size();
    }
    int sz = components.size();
    g_sz = sz;
    for(int i=0; i<k; i++){
        for(int j=0; j<MAX_STATE; j++){
            dp[i][j] = 0.0;
        }
    }
    double pick_prob = 1/(double)sz;
    //dp[0][0] = 1;
    for(int i=0; i<k; i++){
        for(int s=0; s<(1<<sz); s++){
            for(int j=0; j<sz; j++){
                //pick component[j] this time
                if(check(j, s)){
                    cout<<"at state "<<s<<" add "<<j<<endl;
                    int ns = ((1<<j)|s);
                    //dp[i+1][ns] += dp[i][s]*pick_prob;
                    dp[i+1][ns] += (dp[i][s]+pick_prob*g_dif[j])*pick_prob;
                }else{
                    cout<<"could not install when "<<s<<" and want "<<j<<endl;
                }
            }
        }
    }

    double ans = -999999999;
    for(int i=0; i<(1<<sz); i++){
        //ans = max(ans, dp[k][i]);
        ans = max(ans,dp[k][i]);
    }
    return ans;
}
double test0() {
    int p0 = 1;
    string t1[] = { "", "" };
    vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
    int t2[] = { 1, 2 };
    vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
    int t3[] = { 0, 0 };
    vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
    CrazyComponents * obj = new CrazyComponents();
    clock_t start = clock();
    double my_answer = obj->expectedProfit(p0, p1, p2, p3);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    double p4 = 1.5;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p4 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p4 != my_answer) {
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
    string t1[] = { "1", "" };
    vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
    int t2[] = { 10, 0 };
    vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
    int t3[] = { 0, 2 };
    vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
    CrazyComponents * obj = new CrazyComponents();
    clock_t start = clock();
    double my_answer = obj->expectedProfit(p0, p1, p2, p3);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    double p4 = 1.5;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p4 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p4 != my_answer) {
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
    string t1[] = { "1 2", "", "" };
    vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
    int t2[] = { 100, 0, 0 };
    vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
    int t3[] = { 0, 0, 0 };
    vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
    CrazyComponents * obj = new CrazyComponents();
    clock_t start = clock();
    double my_answer = obj->expectedProfit(p0, p1, p2, p3);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    double p4 = 7.407407407407408;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p4 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p4 != my_answer) {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
double test3() {
    int p0 = 5;
    string t1[] = { "1", "2", "0", "" };
    vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
    int t2[] = { 4, 5, 6, 7 };
    vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
    int t3[] = { 0, 0, 0, 8 };
    vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
    CrazyComponents * obj = new CrazyComponents();
    clock_t start = clock();
    double my_answer = obj->expectedProfit(p0, p1, p2, p3);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    double p4 = 0.0;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p4 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p4 != my_answer) {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
double test4() {
    int p0 = 10;
    string t1[] = { "", "", "", "", "", "", "", "", "", "" };
    vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
    int t2[] = { 142352, 2342, 34534, 2344, 12346, 7589, 79872, 973453, 96233, 34567 };
    vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
    int t3[] = { 12432, 2345, 3678, 456, 345, 457, 56758, 4564, 774, 34567 };
    vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
    CrazyComponents * obj = new CrazyComponents();
    clock_t start = clock();
    double my_answer = obj->expectedProfit(p0, p1, p2, p3);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    double p4 = 1269258.9999999998;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p4 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p4 != my_answer) {
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
    return 0;

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

