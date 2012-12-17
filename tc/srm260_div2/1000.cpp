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
#include <queue>
using namespace std;

class RollingBlock {
    public:
        int minMoves(int, int, vector <int>, vector <int>);
};

typedef struct n{
    int x,y;
    int stand;
    int north;
    int step;
}node;

const int MAXN = 101;
bool vis[MAXN][MAXN][2][2];
int g_row, g_col;
int dir_stand[4][2] = {{0,2},{0,-2},{2,0},{-2,0}};

int dir_north[4][2] = {{2,0},{-2,0},{0,1},{0,-1}};
int dir_none_north[4][2] = {{0,2},{0,-2},{1,0},{-1,0}};
int should_stand[4] = {1,1,0,0};
int norths[4] = {0,0,1,1};


bool check(int x, int y){
    if(x>=0&&x<g_row && y>=0&&y<g_col){
        return true;
    }return false;
}
bool stand_check(int x, int y, int i){
    if(i==0){
        if(check(x, y+1))return true;
        return false;
    }else if(i==1){
        if(check(x,y-1))return true;
        return false;
    }else if(i==2){
        if(check(x+1,y))return true;
        return false;
    }else{
        if(check(x-1,y))return true;
        return false;
    }
}
void print(node &s){
    cout<<"At ("<<s.x<<","<<s.y<<") and stand : "<<s.stand<<" north: "<<s.north<<endl;
}

int RollingBlock::minMoves(int rows, int cols, vector <int> start, vector <int> target) {
    g_row = rows, g_col = cols;
    node s_start;
    int e_x, e_y;
    e_x = target[0], e_y = target[1];
    memset(vis,0,sizeof(vis));
    s_start.x = start[0], s_start.y = start[1], s_start.stand = 1, s_start.step = 0, s_start.north=0;
   
    queue<node> Q;
    vis[s_start.x][s_start.y][1][0] = true;
    Q.push(s_start);
    node cur, next;
    while(!Q.empty()){
        cur = Q.front();
        //print(cur);
        Q.pop();
        if(cur.x==e_x && cur.y==e_y&&cur.stand==1){
            return cur.step;
        }
        int nx, ny;
        if(cur.stand==1){
            next.stand = 0;
            for(int i=0; i<4; i++){
                nx = dir_stand[i][0]+cur.x;
                ny = dir_stand[i][1]+cur.y;
                if(stand_check(nx,ny,i)){
                    next.north = norths[i];
                    next.x = nx, next.y = ny;
                    next.step = cur.step+1;
                    if(vis[next.x][next.y][next.stand][next.north]==false){
                       // cout<<"expand to -> ";
                        //print(next);
                        Q.push(next);
                        vis[next.x][next.y][next.stand][next.north]=true;
                    }
                }
            }
        }else{
            for(int i=0; i<4; i++){
                if(cur.north==1){
                    nx = cur.x+dir_north[i][0];
                    ny = cur.y+dir_north[i][1];
                }else{
                    nx = cur.x+dir_none_north[i][0];
                    ny = cur.y+dir_none_north[i][1];
                }
                if(check(nx,ny)){
                    next.north = cur.north;
                    next.stand = should_stand[i];
                    next.x = nx, next.y = ny;
                    next.step = cur.step+1;
                        if(vis[next.x][next.y][next.stand][next.north]==false){
                            Q.push(next);
                            //cout<<"expand to -> ";
                            //print(next);
                            vis[next.x][next.y][next.stand][next.north]=true;
                        }
                }
            }
        }
    }
    return -1;
}

double test0() {
    int p0 = 4;
    int p1 = 5;
    int t2[] = {3, 0};
    vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
    int t3[] = {2, 4};
    vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
    RollingBlock * obj = new RollingBlock();
    clock_t start = clock();
    int my_answer = obj->minMoves(p0, p1, p2, p3);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p4 = 3;
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
    int p0 = 5;
    int p1 = 5;
    int t2[] = {2, 2};
    vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
    int t3[] = {4, 0};
    vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
    RollingBlock * obj = new RollingBlock();
    clock_t start = clock();
    int my_answer = obj->minMoves(p0, p1, p2, p3);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p4 = -1;
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
    int p0 = 4;
    int p1 = 4;
    int t2[] = {3, 0};
    vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
    int t3[] = {3, 3};
    vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
    RollingBlock * obj = new RollingBlock();
    clock_t start = clock();
    int my_answer = obj->minMoves(p0, p1, p2, p3);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p4 = 5;
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
    int p0 = 4;
    int p1 = 4;
    int t2[] = {3, 0};
    vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
    int t3[] = {0, 3};
    vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
    RollingBlock * obj = new RollingBlock();
    clock_t start = clock();
    int my_answer = obj->minMoves(p0, p1, p2, p3);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p4 = 10;
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
    int p0 = 100;
    int p1 = 100;
    int t2[] = {4, 5};
    vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
    int t3[] = {5, 97};
    vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
    RollingBlock * obj = new RollingBlock();
    clock_t start = clock();
    int my_answer = obj->minMoves(p0, p1, p2, p3);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p4 = 47;
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
double test5() {
    int p0 = 20;
    int p1 = 20;
    int t2[] = {7, 9};
    vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
    int t3[] = {7, 9};
    vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
    RollingBlock * obj = new RollingBlock();
    clock_t start = clock();
    int my_answer = obj->minMoves(p0, p1, p2, p3);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p4 = 0;
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

