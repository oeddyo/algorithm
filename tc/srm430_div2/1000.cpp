#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <stack>
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

class ImageTraders {
    public:
        int maxOwners(vector <string>);
};

vector <string> g_price;
const int INF = 999999999;
int g_sz;
//int dp[1<<17];
int dp[1<<16][16][10];
int get_len(int cur, int price, int state){
    if(dp[state][cur][price]!=-1){
        return dp[state][cur][price];
    }
    cout<<"at "<<cur<<endl;
    cout<<"cur state is "<<state<<endl;
    int tmp = -INF;

    for(int i=0; i<g_sz; i++){
        if( (state&(1<<i)) == 0 && g_price[cur][i]-'0' >= price){
            int ns = (1<<i)|state;
            tmp = max(tmp, get_len(i, g_price[cur][i]-'0', ns));
        }
    }
    if(tmp==-INF){
        return 1;
    }else{
        dp[state][cur][price] = tmp+1;
        return dp[state][cur][price];
    }
}


int ImageTraders::maxOwners(vector <string> price) {
    memset(dp,-1,sizeof(dp));
    
    g_sz = price[0].size();
    g_price = price;
    int ans = get_len(0, 0, 1);
    


    /*
    memset(dp,0,sizeof(dp));
    for(int i=0; i<(1<<16); i++)for(int j=0; j<16; j++)for(int k=0; k<10; k++)
        dp[i][j][k] = INF;

    
    int g_sz = price[0].size();
    for(int s = 0; s<(1<<g_sz); s++){
        for(int lp=0; lp<10; lp++){
            for(int cur; int cur<g_sz; cur++){
                if(dp[s][cur][lp] == INF)continue;

                if( ((1<<cur)&s) == 0)continue;
                for(int next; next<g_sz; next++){
                    if( ((1<<next)&s) != 0) continue;
                    int np = 


                }
            }
        }
    }

        
        
        
        
        
        
        for(int last = 0; last<g_sz; last++){
            if( s&(1<<last)==0)continue;
            if(dp[s][last]!= INF){
                for(int next=0; next<g_sz; next++){
                    if( 1&(next>>j) )continue;
                    int ns = (1<<next)|s;
                    int np = price[last][next];
                    

                }
            }

        }
    }
*/

    return ans;
}
double test0() {
    string t0[] = {
        "01",
        "10"
    };
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    ImageTraders * obj = new ImageTraders();
    clock_t start = clock();
    int my_answer = obj->maxOwners(p0);
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
    string t0[] = {
        "022",
        "101",
        "110"
    }
    ;
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    ImageTraders * obj = new ImageTraders();
    clock_t start = clock();
    int my_answer = obj->maxOwners(p0);
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
double test2() {
    string t0[] = {
        "01231",
        "00231",
        "00031",
        "00002",
        "00000"
    };
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    ImageTraders * obj = new ImageTraders();
    clock_t start = clock();
    int my_answer = obj->maxOwners(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p1 = 4;
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
    string t0[] = {
        "15555",
        "11111",
        "15111",
        "11111",
        "11111"
    };
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    ImageTraders * obj = new ImageTraders();
    clock_t start = clock();
    int my_answer = obj->maxOwners(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p1 = 3;
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
    string t0[] = {
        "0100000000",
        "0020000000",
        "0003000000",
        "0000400000",
        "0000050000",
        "0000006000",
        "0000000700",
        "0000000080",
        "0000000009",
        "1111111111"
    };
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    ImageTraders * obj = new ImageTraders();
    clock_t start = clock();
    int my_answer = obj->maxOwners(p0);
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

