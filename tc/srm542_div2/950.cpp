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

class StrangeDictionary {
    public:
        vector <double> getExpectedPositions(vector <string>);
};


typedef pair<string, string> pss;
const int MAXN = 51;
double prob[MAXN][MAXN];
vector <double> StrangeDictionary::getExpectedPositions(vector <string> words) {
    int sz = words.size();
    int len = words[0].size();
    map<string, int> mymap;
    int t_cnt = 0;
    for(int i=0; i<sz; i++){
        mymap[words[i]] = t_cnt++;
    }
    for(int i=0; i<len i++){
        vector< pss > vt;
        for(int j=0; j<sz; j++){
            vt.push_back( pss(words[j][i], words[j]));
        }
        sort(vt.begin(), vt.end());

        for(int j=0; j<sz; j++){
            for(int k=0; k<sz; k++){
                if(vt[j].first==vt[k].first){
                    continue;
                }else{
                    int cnt = k-j;
                    for(int q = j; q<k; q++){
                        prob[mymap[vt[q].second]][q] = (1/(double)sz) * (1.0/(double)cnt);
                    }
                    j = k-1;
                    break;
                }
            }
        }
    }
    vector<double> ans;
    for(int i=0; i<len; j++){
        double t=0;
        for(int j=0; j<sz; j++){
            
        }
    }

}
double test0() {
    string t0[] = {"hardesttestever"};
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    StrangeDictionary * obj = new StrangeDictionary();
    clock_t start = clock();
    vector <double> my_answer = obj->getExpectedPositions(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    double t1[] = {0.0 };
    vector <double> p1(t1, t1+sizeof(t1)/sizeof(double));
    cout <<"Desired answer: " <<endl;
    cout <<"\t{ ";
    if (p1.size() > 0) {
        cout <<p1[0];
        for (int i=1; i<p1.size(); i++)
            cout <<", " <<p1[i];
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
    if (my_answer != p1) {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
double test1() {
    string t0[] = {"ab", "ba"};
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    StrangeDictionary * obj = new StrangeDictionary();
    clock_t start = clock();
    vector <double> my_answer = obj->getExpectedPositions(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    double t1[] = {0.5, 0.5 };
    vector <double> p1(t1, t1+sizeof(t1)/sizeof(double));
    cout <<"Desired answer: " <<endl;
    cout <<"\t{ ";
    if (p1.size() > 0) {
        cout <<p1[0];
        for (int i=1; i<p1.size(); i++)
            cout <<", " <<p1[i];
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
    if (my_answer != p1) {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
double test2() {
    string t0[] = {"aza", "aab", "bba"};
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    StrangeDictionary * obj = new StrangeDictionary();
    clock_t start = clock();
    vector <double> my_answer = obj->getExpectedPositions(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    double t1[] = {1.0, 0.8333333333333333, 1.1666666666666665 };
    vector <double> p1(t1, t1+sizeof(t1)/sizeof(double));
    cout <<"Desired answer: " <<endl;
    cout <<"\t{ ";
    if (p1.size() > 0) {
        cout <<p1[0];
        for (int i=1; i<p1.size(); i++)
            cout <<", " <<p1[i];
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
    if (my_answer != p1) {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
double test3() {
    string t0[] = {"abababab", "babababa", "acacacac", "cacacaca", "bcbcbcbc", "cbcbcbcb"};
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    StrangeDictionary * obj = new StrangeDictionary();
    clock_t start = clock();
    vector <double> my_answer = obj->getExpectedPositions(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    double t1[] = {1.0, 1.0, 2.5, 2.5, 4.0, 4.0 };
    vector <double> p1(t1, t1+sizeof(t1)/sizeof(double));
    cout <<"Desired answer: " <<endl;
    cout <<"\t{ ";
    if (p1.size() > 0) {
        cout <<p1[0];
        for (int i=1; i<p1.size(); i++)
            cout <<", " <<p1[i];
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
    if (my_answer != p1) {
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

