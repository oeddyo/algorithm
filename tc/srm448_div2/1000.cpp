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

class TheCardLineDivTwo {
    public:
        int count(vector <string>);
};

const int MAXN = 16;
const int MAXS = 1<<16;
long long int dp[2][MAXN][MAXS];
//int dp[MAXN][MAXS];
int g[MAXN][MAXN];
void build_graph(vector<string> cards){
    int sz = cards.size();
    memset(g,0,sizeof(g));
    for(int i=0; i<sz; i++){
        for(int j=0; j<sz; j++){
            if(i==j)continue;
            if(cards[i][0]==cards[j][0]){
                g[i][j] = 1;
            }
            if(cards[i][1]==cards[j][1]){
                g[i][j] = 1;
            }
        }
    }
}


int MOD = 1234567891;
int TheCardLineDivTwo::count(vector <string> cards) {
    for(int i=0; i<cards.size(); i++){
        if(cards[i][1]=='C'){
            cards[i][1] = 'S';
        }
        if(cards[i][1]=='H'){
            cards[i][1] = 'D';
        }
    }

    build_graph(cards);
    memset(dp,0,sizeof(dp));
    int sz = cards.size();
    for(int i=0; i<sz; i++){
        int ns = (1<<i);
        dp[0][i][ns] = 1;
        //dp[i][ns] = 1;
    }
    int ns;
    for(int i=1; i<sz; i++){
        for(int s=0; s<(1<<sz); s++){
            for(int u=0; u<sz; u++){
                if( ((1<<u)&s) == 0 )continue;
                for(int v=0; v<sz; v++){
                    if(g[u][v] == 0)continue;
                    if( u==v ||  ((1<<v)&s) != 0 )continue;
                    ns = (1<<v)|s;
                    dp[i&1][v][ns] += dp[(i-1)&1][u][s];
                    //dp[v][ns]+=dp[u][s];
                    if(dp[i&1][v][ns] > 200000000000LL){
                        dp[i&1][v][ns]%=MOD;
                    }
                    //dp[i&1][v][ns]%=MOD;
                    //dp[v][ns]%=MOD;
                    //cout<<"from "<<cards[u]<<" to "<<cards[v]<<" "<<i<<" "<<u<<" "<<v<<" "<<ns<<" "<<dp[i][v][ns]<<endl;
                }
            }
        }
    }
    long long int sum = 0;
    for(int i=0; i<sz; i++){
        //sum+= dp[i][(1<<sz)-1];
        sum += dp[(sz-1)&1][i][(1<<sz)-1];
        sum%= MOD;
    }
    return (int)sum;

}

double test0() {
    //string t0[] = {"KH", "QD", "KC"};
    string t0[] = {"TS", "5S", "TC", "7C", "6S", "2C", "9S", "JS", "QS", "KC", "7S", "2S", "8S", "AS", "AC", "4S"};
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    TheCardLineDivTwo * obj = new TheCardLineDivTwo();
    clock_t start = clock();
    int my_answer = obj->count(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p1 = 567839223;
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
    string t0[] = {"JS", "JC", "JD", "JH"};
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    TheCardLineDivTwo * obj = new TheCardLineDivTwo();
    clock_t start = clock();
    int my_answer = obj->count(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p1 = 24;
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
    string t0[] = {"2S", "3C", "4C", "5S", "6C", "7S", "8S", "9H"};
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    TheCardLineDivTwo * obj = new TheCardLineDivTwo();
    clock_t start = clock();
    int my_answer = obj->count(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p1 = 0;
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
    string t0[] = {"KD", "KC", "AD", "7C", "AH", "9C", "4H", "4S", "AS"};
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    TheCardLineDivTwo * obj = new TheCardLineDivTwo();
    clock_t start = clock();
    int my_answer = obj->count(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p1 = 2416;
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

