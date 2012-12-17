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

class PowerPlants {
    public:
        int minCost(vector <string>, string, int);
};

const int MAXN = 17;
const int MAXSTATE = 1<<17;
int dp[MAXN][1<<17];
const int INF = 999999999;

int PowerPlants::minCost(vector <string> connectionCost, string plantList, int numPlants) {
    for(int i=0; i<MAXN; i++){
        for(int j=0; j<MAXSTATE; j++){
            dp[i][j] = INF;
        }
    }

    int init_state = 0;
    int cnt_Y = 0;
    for(int i=0; i<plantList.size(); i++){
        if(plantList[i]=='Y'){
            cnt_Y ++;
            init_state =( init_state<<1) + 1;
        }else{
            init_state = init_state<<1;
        }
    }
    cout<<"INIT STATE IS "<<init_state<<endl;
    int sz = plantList.size();
    dp[0][init_state] = 0;
    if(numPlants-cnt_Y<=0){
        return 0;
    }
    for(int i=0; i<numPlants-cnt_Y; i++){
        for(int s=0; s<(1<<sz); s++){
            if(dp[i][s]!=INF){
                for(int k=0; k<sz; k++){
                    if(((s>>k)&1)==1){
                        for(int j=0; j<sz; j++){
                            if (((s>>j)&1)==0){
                                //open j
                                //from k
                                int n_s = s|(1<<j);
                                int cost;
                                
                                int from = sz-k-1;
                                int to = sz-j-1;

                                if(connectionCost[from][to]<='9'&&connectionCost[from][to]>='0'){
                                    cost = connectionCost[from][to]-'0';
                                }else{
                                    cost = connectionCost[from][to]-'A'+10;
                                }
                                /*
                                if(connectionCost[k][j]<='9'&&connectionCost[k][j]>='0'){
                                    cost = connectionCost[k][j]-'0';
                                }else{
                                    cost = connectionCost[k][j]-'A'+10;
                                }
                                */
                                //cout<<"now at "<<i<<"  "<<s<<" and turn from "<<k<<" to "<<j<<" with cost "<<cost<<" next is "<<n_s<<endl;
                                dp[i+1][n_s] = min(dp[i+1][n_s], dp[i][s] + cost);
                            }
                        }
                    }
                }
            }
        }
    }
    int ans = INF;
    for(int i=0; i<(1<<sz); i++){
        ans = min(ans, dp[numPlants-cnt_Y][i]);
    }
    return ans;
}
double test0() {
    string t0[] = {"024",
        "203",
        "430"};
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    string p1 = "YNN";
    int p2 = 3;
    PowerPlants * obj = new PowerPlants();
    clock_t start = clock();
    int my_answer = obj->minCost(p0, p1, p2);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p3 = 5;
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
    string t0[] = {"0AB",
        "A0C",
        "CD0"};
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    string p1 = "YNN";
    int p2 = 3;
    PowerPlants * obj = new PowerPlants();
    clock_t start = clock();
    int my_answer = obj->minCost(p0, p1, p2);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p3 = 21;
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
    string t0[] = {"1ABCD",
        "35HF8",
        "FDM31",
        "AME93",
        "01390"};
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    string p1 = "NYNNN";
    int p2 = 5;
    PowerPlants * obj = new PowerPlants();
    clock_t start = clock();
    int my_answer = obj->minCost(p0, p1, p2);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p3 = 14;
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
    string t0[] = {"012",
        "123",
        "234"};
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    string p1 = "NNY";
    int p2 = 2;
    PowerPlants * obj = new PowerPlants();
    clock_t start = clock();
    int my_answer = obj->minCost(p0, p1, p2);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p3 = 2;
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
    string t0[] = {"1309328",
        "DS2389U",
        "92EJFAN",
        "928FJNS",
        "FJS0DJF",
        "9FWJW0E",
        "23JFNFS"};
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    string p1 = "YYNYYNY";
    int p2 = 4;
    PowerPlants * obj = new PowerPlants();
    clock_t start = clock();
    int my_answer = obj->minCost(p0, p1, p2);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p3 = 0;
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
    string t0[] = {"01","20"};
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    string p1 = "YN";
    int p2 = 2;
    PowerPlants * obj = new PowerPlants();
    clock_t start = clock();
    int my_answer = obj->minCost(p0, p1, p2);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p3 = 1;
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

