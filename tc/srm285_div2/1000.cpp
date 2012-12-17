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

class OperationsArrangement {
    public:
        string arrange(string);
};
const int MAXN = 51;
int dp[MAXN][MAXN];
int mark[MAXN][MAXN];
long long int multi[MAXN][MAXN];
const int INF = 999999999;
string g_sequence;

string ans_seq = "";

void print(int s,int e){
    if(dp[s][e]==multi[s][e]){
        for(int i=s; i<e; i++){
            cout<<g_sequence[i]<<"*";
            ans_seq+=g_sequence[i];
            ans_seq+="*";
        }
        //ans_seq += g_sequence[e]+"0";
        //ans_seq += "&";
        cout<<g_sequence[e];
        ans_seq+=g_sequence[e];
        return ;
    }
    
    for(int mid = e-1; mid>=s; mid--){
        if(multi[s][mid] == dp[s][mid]){
            print(s,mid);
            ans_seq += "+";
            cout<<"+";
            print(mid+1,e);
            return ;
        }
    }
     
    int mid = mark[s][e];
    print(s,mid);
    cout<<"+";
    print(mid+1,e);
}

string OperationsArrangement::arrange(string sequence) {
    ans_seq = "";
    g_sequence = sequence;
    memset(mark,-1,sizeof(mark));
    int sz = sequence.size();
    for(int i=0; i<MAXN; i++)for(int j=0; j<MAXN; j++){
        dp[i][j] = INF;
    }

    for(int i=0; i<sz; i++){
        for(int j=i; j<sz; j++){
            long long int t=1;
            for(int k=i; k<=j; k++){
                t*=sequence[k]-'0';
                if( t>INF){
                    t = INF;
                    break;
                }
            }
            multi[i][j] = t;
            cout<<"multi "<<i<<" "<<j<<" = "<<multi[i][j]<<endl;
        }
    }

    for(int i=0; i<sz; i++){
        dp[i][i] = sequence[i]-'0';
    }


    for(int len=2; len<=sz; len++){
        for(int s=0; s<sz; s++){
            int e = s+len-1;
            if(e>sz)continue;
            int t = multi[s][e];
            mark[s][e] = -1;
            int add = INF;
            int pos = -1;
            for(int mid=s; mid<e; mid++){
                // [s,mid], [mid+1,e]
                if( add>dp[s][mid]+dp[mid+1][e]){
                    add = min(t,dp[s][mid]+dp[mid+1][e]);
                    //mark[s][e] = mid;
                    pos = mid;
                }
            }
            if( add < t ){
                t = add;
                mark[s][e] = pos;
            }

            dp[s][e] = t;
            cout<<"dp["<<s<<"]["<<e<<"] = "<<dp[s][e]<<endl;
        }
    }

    print(0,sz-1);
    cout<<endl;
    cout<<dp[0][sz-1]<<endl;
    return ans_seq;
    return "ha";
}


double test0() {
    string p0 = "99999999999999999999999999999999999999999999999999";
    OperationsArrangement * obj = new OperationsArrangement();
    clock_t start = clock();
    string my_answer = obj->arrange(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    string p1 = "9+9+9+9+9+9+9+9+9+9+9+9+9+9+9+9+9+9+9+9+9+9+9+9+9+9+9+9+9+9+9+9+9+9+9+9+9+9+9+9+9+9+9+9+9+9+9+9+9+9";
    cout <<"Desired answer: " <<endl;
    cout <<"\t\"" << p1 <<"\"" <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t\"" << my_answer<<"\"" <<endl;
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
    string p0 = "322";
    OperationsArrangement * obj = new OperationsArrangement();
    clock_t start = clock();
    string my_answer = obj->arrange(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    string p1 = "3+2*2";
    cout <<"Desired answer: " <<endl;
    cout <<"\t\"" << p1 <<"\"" <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t\"" << my_answer<<"\"" <<endl;
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
    string p0 = "307";
    OperationsArrangement * obj = new OperationsArrangement();
    clock_t start = clock();
    string my_answer = obj->arrange(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    string p1 = "3*0*7";
    cout <<"Desired answer: " <<endl;
    cout <<"\t\"" << p1 <<"\"" <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t\"" << my_answer<<"\"" <<endl;
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
    string p0 = "391118571";
    OperationsArrangement * obj = new OperationsArrangement();
    clock_t start = clock();
    string my_answer = obj->arrange(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    string p1 = "3+9*1*1*1+8+5+7*1";
    cout <<"Desired answer: " <<endl;
    cout <<"\t\"" << p1 <<"\"" <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t\"" << my_answer<<"\"" <<endl;
    if (p1 != my_answer) {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
double test4() {
    string p0 = "111221911212";
    OperationsArrangement * obj = new OperationsArrangement();
    clock_t start = clock();
    string my_answer = obj->arrange(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    string p1 = "1*1*1*2*2*1+9*1*1+2*1*2";
    cout <<"Desired answer: " <<endl;
    cout <<"\t\"" << p1 <<"\"" <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t\"" << my_answer<<"\"" <<endl;
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

