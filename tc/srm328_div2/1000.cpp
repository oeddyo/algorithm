#include <vector>
#include <list>
#include <map>
#include <set>
#include <sstream>
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
#include <queue>

using namespace std;

class ScoreDifference {
    public:
        int maximize(vector <string>);
};

const int INF = 999999999;
const int MAX_STATE = (1<<16);
typedef pair<int, int> pii;
pii cur, next;
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
bool vis[4][4];
int dp[MAX_STATE];

int numbers[17];

bool judge(int s, int x,int y){
    memset(vis,0,sizeof(vis));
    vis[x][y] = 1;
    queue< pii >Q;
    Q.push(pii(x,y));
    while(!Q.empty()){
        cur = Q.front();
        Q.pop();
        if(cur.first == 0 || cur.first==3 || cur.second==0|| cur.second==3){
            return true;
        }
        for(int i=0; i<4; i++){
            int nx = cur.first+dir[i][0];
            int ny = cur.second+dir[i][1];
            if(nx>=0&&nx<4&&ny>=0&&ny<4&& ((s>>(nx*4+ny))&1)==0 &&  vis[nx][ny]==0){
                vis[nx][ny] = 1;
                Q.push(pii(nx,ny));
            }
        }
    }
    return false;
}

int get_dp(int s, int step){
    //cout<<"seeing "<<s<<endl;
    if(dp[s]!=-INF){
        return dp[s];
    }
    int add;
    int t_max = - INF;

    for(int x=0; x<4; x++){
        for(int y=0; y<4; y++){
            int p = x*4+y;
            if( ((s>>p)&1)==0 ) continue;
            if(judge(s, x, y)){
                int ns = ((~(1<<p))&s);
                if(step&1){
                    add = numbers[p];
                }else{
                    add = -numbers[p];
                }
                t_max = max(t_max, get_dp(ns, step-1)+add);
            }
        }
    }
    /*
    for(int i=0; i<16; i++){
        if( ((s>>i)&1)==0)continue;
        if(judge(s,i)){
           int ns = ((~(1<<i)) & s);
           //cout<<s<<"->"<<ns<<endl;
        }
    }*/
    dp[s] = t_max;
    return t_max;
}




int ScoreDifference::maximize(vector <string> board) {
    for(int i=0; i<4; i++){
        istringstream is(board[i]);
        for(int j=0; j<4; j++){
            string t;
            is>>t;
            numbers[i*4+j] = atoi(t.c_str());
            cout<<numbers[i*4+j]<<" ";
        }
    }
    
    for(int i=0; i<MAX_STATE; i++){
        dp[i] = -INF;
    }
    for(int i=0; i<16; i++){
        dp[(1<<i)] = -1*numbers[i];
    }
    cout<<"see this-> "<<endl;
    cout<<dp[(1<<16)-1]<<endl;    
    int ans = get_dp( (1<<16)-1, 16);
    return ans;
}
double test0() {
    string t0[] = {"12 4 5 13", 
        "3 14 16 9",
        "11 6 15 8",
        "2 1 7 10"};
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    ScoreDifference * obj = new ScoreDifference();
    clock_t start = clock();
    int my_answer = obj->maximize(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p1 = 2;
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
    string t0[] = {"15 16 11 12",
        "10 13 4 7",
        "1 2 8 6",
        "9 5 3 14"};
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    ScoreDifference * obj = new ScoreDifference();
    clock_t start = clock();
    int my_answer = obj->maximize(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p1 = 6;
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
    string t0[] = {"6 8 1 16",
        "10 15 9 3",
        "2 5 7 14",
        "13 12 11 4"};
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    ScoreDifference * obj = new ScoreDifference();
    clock_t start = clock();
    int my_answer = obj->maximize(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p1 = 10;
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
    string t0[] = {"9 8 3 1",
        "10 6 15 5",
        "12 7 4 11",
        "14 13 16 2"};
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    ScoreDifference * obj = new ScoreDifference();
    clock_t start = clock();
    int my_answer = obj->maximize(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p1 = 16;
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

    if (!errors)
        cout <<"You're a stud (at least on the example cases)!" <<endl;
    else
        cout <<"Some of the test cases had errors." <<endl;
}

