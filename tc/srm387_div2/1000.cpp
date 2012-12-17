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

class MarblesRegroupingHard {
    public:
        int minMoves(vector <string>);
};

const int MAXN = 51;
const int MAX_STATE = 1<<15;
int dp[MAXN][1<<15];
const int INF = 999999999;
int sums[15];
int numbers[MAXN][16];

int MarblesRegroupingHard::minMoves(vector <string> boxes) {
    for(int i=0; i<MAXN; i++)for(int j=0; j<MAX_STATE; j++)dp[i][j] = INF;
    memset(sums, 0, sizeof(sums)); 
    int cnt = 0;
    for(int i=0; i<boxes.size(); i++){
        istringstream is(boxes[i]);
        cnt = 0;
        string t;
        while(is>>t){
            int num = atoi(t.c_str());
            sums[cnt] += num;
            numbers[i][cnt] = num;
            cnt++;
        }
    }
    
    //initial
    int sz = boxes.size();
    /*for(int i=0; i<cnt; i++){
        dp[0][(1<<i)] = sums[i] -numbers[0][i];
    }
    */
    dp[0][0] = 0;

    for(int i=0; i<sz; i++){
        for(int s=0; s<(1<<cnt); s++){
            if(dp[i][s]==INF)continue;
            //cout<<"dp["<<i<<"]["<<s<<"] = "<<dp[i][s]<<endl;
            for(int j=0; j<cnt; j++){
                if( ((s>>j)&1)==0 ){
                    int ns = (1<<j)|s;
                    //cout<<i<<" "<<j<<" "<<s<<" "<<ns<<" -> "<<sums[j]-numbers[i][j]<<endl;
                    //cout<<"now dp[i+1][ns]"<<dp[i+1][ns]<<endl;
                    dp[i+1][ns] = min(dp[i+1][ns], dp[i][s] + sums[j] - numbers[i][j]);
                    //cout<<"after update "<<dp[i+1][ns]<<endl;
                }
            }
            dp[i+1][s] = min(dp[i+1][s], dp[i][s]);
        }
    }

    int ans = INF;
    for(int i=0; i<=sz; i++){
        ans = min(ans, dp[i][(1<<cnt)-1]);
    }

   /* 
    for(int i=0; i<=sz; i++){
        for(int j=0; j<MAX_STATE; j++){
            if(dp[i][j]!=INF){
                cout<<"dp["<<i<<"]["<<(j)<<"] = "<<dp[i][j]<<endl;
            }
        }
    }*/
/*
    for(int i=0; i<sz; i++){
        cout<<"dp["<<i<<"]["<<((1<<cnt)-1)<<"] = "<<dp[i][(1<<cnt)-1]<<endl;
        ans = min(ans, dp[i][(1<<cnt)-1]);
    }
  */  return ans;
    
    /*
    for(int i=0; i<cnt; i++){
        cout<<sums[i]<<" ";
    }cout<<endl;
    */

}
double test0() {
    string t0[] = {"0"};
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    MarblesRegroupingHard * obj = new MarblesRegroupingHard();
    clock_t start = clock();
    int my_answer = obj->minMoves(p0);
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
double test1() {
    string t0[] = {"77 97","8 0"};
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    MarblesRegroupingHard * obj = new MarblesRegroupingHard();
    clock_t start = clock();
    int my_answer = obj->minMoves(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p1 = 77;
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
    string t0[] = {"6 97 7","73 45 0","67 45 63"};
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    MarblesRegroupingHard * obj = new MarblesRegroupingHard();
    clock_t start = clock();
    int my_answer = obj->minMoves(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p1 = 170;
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
    string t0[] = {"97 94 0 99","1 72 46 45","0 10 47 75","0 92 76 20","2 25 98 22"};
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    MarblesRegroupingHard * obj = new MarblesRegroupingHard();
    clock_t start = clock();
    int my_answer = obj->minMoves(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p1 = 559;
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
double test4() {
    string t0[] = {"38 0 0 45 77 61 0 0 8 87 65 53 0 2",
        "0 97 79 37 70 0 69 35 95 11 75 96 77 29",
        "39 32 0 24 63 22 91 71 0 63 92 59 12 0",
        "34 0 0 71 88 13 60 56 0 22 29 89 81 53",
        "69 95 65 0 94 98 84 37 0 87 16 0 58 18",
        "82 0 36 88 0 54 82 40 6 0 34 44 80 2",
        "33 58 7 95 83 87 0 0 79 35 0 51 22 84",
        "7 0 30 57 33 4 0 26 44 55 67 31 88 42",
        "62 58 62 93 91 0 1 0 44 23 95 0 55 57",
        "35 8 22 26 76 0 78 54 0 46 42 0 0 64",
        "93 54 58 0 89 89 0 0 57 0 98 3 24 0",
        "9 0 0 23 82 18 0 46 0 0 94 84 19 18",
        "78 12 6 45 0 80 16 69 59 76 35 0 66 0",
        "0 68 77 13 15 0 52 72 0 0 18 65 23 0",
        "0 0 73 53 0 95 91 44 27 96 85 0 99 85",
        "93 29 4 89 27 44 27 17 21 6 0 8 3 91",
        "0 46 73 94 60 59 15 50 18 75 74 88 46 93",
        "0 0 0 94 93 26 21 83 54 62 0 89 59 77",
        "32 98 0 44 34 38 56 20 0 61 29 94 52 57",
        "52 60 0 22 0 5 38 0 50 98 12 75 0 81",
        "23 0 41 18 36 87 49 32 62 43 22 74 0 97",
        "0 0 30 79 16 73 61 0 75 51 64 13 45 0",
        "11 0 14 2 0 1 2 16 84 37 95 45 48 33",
        "10 0 0 35 0 85 28 76 99 74 76 32 52 8",
        "60 0 96 0 95 26 59 13 0 0 44 42 97 48",
        "34 7 77 25 91 85 35 78 32 99 7 29 18 15",
        "61 50 43 22 42 63 64 50 9 94 42 22 21 33",
        "58 0 41 10 16 0 27 67 83 27 14 37 98 47",
        "37 60 60 76 71 2 84 32 27 39 82 84 0 94",
        "15 98 69 82 36 66 0 97 62 39 0 65 62 67",
        "0 41 0 43 0 0 94 0 0 58 0 0 27 33",
        "53 90 71 91 85 0 32 86 40 60 11 0 99 28",
        "79 62 0 0 79 0 14 62 87 76 35 0 70 0",
        "0 40 73 48 0 63 0 0 63 5 30 18 47 51",
        "75 6 58 69 33 57 66 0 12 0 46 0 65 10"};
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    MarblesRegroupingHard * obj = new MarblesRegroupingHard();
    clock_t start = clock();
    int my_answer = obj->minMoves(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p1 = 18618;
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

    time = test4();
    if (time < 0)
        errors = true;

    if (!errors)
        cout <<"You're a stud (at least on the example cases)!" <<endl;
    else
        cout <<"Some of the test cases had errors." <<endl;
}

