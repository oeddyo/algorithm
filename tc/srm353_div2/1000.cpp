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

class PlatformJumper {
    public:
        int maxCoins(vector <string>, int, int);
};

typedef pair<int, int> pii;
const int MAXN = 51;
int dp[MAXN], g_sz , g_g, g_v;
vector<pair<int, pii > > P;


bool could_jump(int cur, int next){
    if(cur==next)return false;
    
    int cur_x = P[cur].second.first;
    int cur_y = P[cur].second.second;

    int next_x = P[next].second.first;
    int next_y = P[next].second.second;
    //cout<<cur_x<<" "<<cur_y<<" , "<<next_x<<" "<<next_y<<endl;
    if(next_y>=cur_y)return false;


    double t_down_sq = sqrt(2*(cur_y-next_y)/(g_g*1.0));
    double v_hor = abs(cur_x-next_x)/(t_down_sq);

    //cout<<"t_down "<<t_down_sq<<" v_hor "<<v_hor<<endl;

    if(g_v>= v_hor){
        return true;
    }
    return false;
}

int dfs(int cur){
    if(dp[cur]!=-1)return dp[cur];
    bool jumped = false;
    int ans = -1;
    for(int i=0; i<g_sz; i++){
        if( could_jump(cur, i)){
            jumped = true;
            //cout<<"from "<<cur<<" could to "<<i<<endl;
            ans = max(ans, P[cur].first+dfs(i));
        }
    }
    if(jumped==false){
        dp[cur] = P[cur].first;
        //cout<<"cur is "<<cur<<" return "<<P[cur].first<<endl;
        return P[cur].first;
    }else{
        dp[cur] = ans;
        //cout<<"cur is "<<cur<<" return "<<ans<<endl;
        return ans;
    }
}

int PlatformJumper::maxCoins(vector <string> platforms, int v, int g) {
    P.clear();
    g_g = g, g_v = v;
    for(int i=0; i<platforms.size(); i++){
       istringstream is(platforms[i]);
       int a,b,c;
       is>>a>>b>>c;
       P.push_back(pair<int, pii>(c, pii(a,b)));
    }
    memset(dp,-1,sizeof(dp));
    g_sz = platforms.size();
    int ans = -1;
    for(int i=0; i<platforms.size(); i++){
        memset(dp,-1,sizeof(dp));
        int t = dfs(i);
        if(t>ans){
            ans = t;
        }
    }
    return ans;
}

double test0() {
    string t0[] = {"3 10 7", "5 15 7", "8 9 12" };
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    int p1 = 2;
    int p2 = 10;
    PlatformJumper * obj = new PlatformJumper();
    clock_t start = clock();
    int my_answer = obj->maxCoins(p0, p1, p2);
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
double test1() {
    string t0[] = {"0 0 1", "2 4 1", "4 0 1"};
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    int p1 = 1;
    int p2 = 2;
    PlatformJumper * obj = new PlatformJumper();
    clock_t start = clock();
    int my_answer = obj->maxCoins(p0, p1, p2);
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
double test2() {
    string t0[] = {"0 0 1", "5000 5000 10"};
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    int p1 = 100;
    int p2 = 87;
    PlatformJumper * obj = new PlatformJumper();
    clock_t start = clock();
    int my_answer = obj->maxCoins(p0, p1, p2);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p3 = 10;
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

    if (!errors)
        cout <<"You're a stud (at least on the example cases)!" <<endl;
    else
        cout <<"Some of the test cases had errors." <<endl;
}

