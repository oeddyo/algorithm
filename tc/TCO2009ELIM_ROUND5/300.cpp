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

class PawnsAndKings {
    public:
        int minNumberOfMoves(vector <string>);
};

typedef pair<int, int> myp;
typedef pair< vector< myp >, int> state;

typedef struct n{
    vector< myp > pawn;
    vector< myp > king;
    int n_pawn, n_king;
    int step;
}node;

const int INF = 99999999;
int PawnsAndKings::minNumberOfMoves(vector <string> board) {
    node start;
    vector< myp > king;
    vector< myp > pawn;

    for(int i=0; i<board.size(); i++){
        for(int j=0; j<board.size(); j++){
            if(board[i][j]=='K'){
                king.push_back( myp(i,j));
            }else if(board[i][j]=='P'){
                pawn.push_back( myp(i,j));
            }
        }
    }

    start.pawn = pawn;
    start.king = king;
    start.step = 0;
    start.n_pawn = pawn.size();
    start.n_king = king.size();
    queue< node> Q;
    Q.push(start);
    node cur, next;
    int ans = INF;
    while(!Q.empty()){
        cur = Q.front();
        Q.pop();
        if(cur.n_pawn==0){
            ans = min(ans, cur.step);
            continue;
        }
        for(int i=0; i<cur.n_king; i++){
            for(int j=0; j<cur.n_pawn; j++){
                int dis = abs(cur.king[i].first-cur.pawn[j].first )+ abs(cur.king[i].second-cur.pawn[j].second);
                
                next.pawn = cur.pawn;
                next.king = cur.king;
               
                next.king[i].first = cur.pawn[j].first;
                next.king[i].second = cur.pawn[j].second;
                
                next.n_pawn = cur.n_pawn-1;
                next.n_king = cur.n_king;
                next.step = cur.step+dis;
                next.pawn.erase(next.pawn.begin()+j);
                Q.push(next);
            }
        }
    }
    return ans;
}

double test0() {
    string t0[] = {".PPPPKP.", 
        "........", 
        "........", 
        "........", 
        "........", 
        "........", 
        "........", 
        "........"};
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    PawnsAndKings * obj = new PawnsAndKings();
    clock_t start = clock();
    int my_answer = obj->minNumberOfMoves(p0);
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
double test1() {
    string t0[] = {"P......P", 
        "........", 
        "........",
        "........",
        "...KK...",
        "........",
        "........",
        "P......P"};
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    PawnsAndKings * obj = new PawnsAndKings();
    clock_t start = clock();
    int my_answer = obj->minNumberOfMoves(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p1 = 20;
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
    string t0[] = {".....P.P",
        "..K....P",
        "....K...",
        "..PP...P",
        "...K..KK",
        "........",
        "K.......",
        "KP.K...."};
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    PawnsAndKings * obj = new PawnsAndKings();
    clock_t start = clock();
    int my_answer = obj->minNumberOfMoves(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p1 = 9;
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
    string t0[] = {"PK...KPK",
        "......K.",
        "...K....",
        "..KPK...",
        "...K....",
        "........",
        "........",
        "K..P.K.P"};
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    PawnsAndKings * obj = new PawnsAndKings();
    clock_t start = clock();
    int my_answer = obj->minNumberOfMoves(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p1 = 8;
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
return 0;
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

