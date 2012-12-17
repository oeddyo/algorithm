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

class MazeMaker {
    public:
            int longestPath(vector <string>, int, int, vector <int>, vector <int>);
};

const int MAXN = 51;
bool vis[MAXN][MAXN];
typedef struct n{
    int x,y,step;
}node;

int MazeMaker::longestPath(vector <string> maze, int startRow, int startCol, vector <int> moveRow, vector <int> moveCol) {
    memset(vis,0,sizeof(vis));
    vis[startRow][startCol] = true;
    node s;
    s.x= startRow, s.y=startCol, s.step=0;
    queue<node> Q;
    Q.push(s);
    int sz = moveRow.size();
    int row = maze.size();
    int col = maze[0].size();
    int ans = -1;
    node cur, next;
    while(!Q.empty()){
        cur = Q.front();
        Q.pop();
        ans = max(ans, cur.step);
        int x = cur.x, y = cur.y;
        for(int i=0; i<sz; i++){
            int nx = cur.x+moveRow[i];
            int ny = cur.y+moveCol[i];
            if(nx>=0&&nx<row && ny>=0 && ny<col && maze[nx][ny]!='X'&&vis[nx][ny]==false){
                next.x = nx, next.y = ny, next.step = cur.step+1;
                Q.push(next);
                vis[nx][ny]=true;
            }
        }
    }
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(maze[i][j]=='.' && vis[i][j]==false){
                return -1;
            }
        }

    }
    return ans;
}
double test0() {
	string t0[] = {"...",
 "...",
 "..."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 0;
	int p2 = 1;
	int t3[] = {1,0,-1,0};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	int t4[] = {0,1,0,-1};
	vector <int> p4(t4, t4+sizeof(t4)/sizeof(int));
	MazeMaker * obj = new MazeMaker();
	clock_t start = clock();
	int my_answer = obj->longestPath(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p5 = 3;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p5 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p5 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	string t0[] = {"...",
 "...",
 "..."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 0;
	int p2 = 1;
	int t3[] = {1, 0, -1, 0, 1, 1, -1, -1};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	int t4[] = {0, 1, 0, -1, 1, -1, 1, -1};
	vector <int> p4(t4, t4+sizeof(t4)/sizeof(int));
	MazeMaker * obj = new MazeMaker();
	clock_t start = clock();
	int my_answer = obj->longestPath(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p5 = 2;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p5 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p5 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	string t0[] = {"X.X",
 "...",
 "XXX",
 "X.X"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 0;
	int p2 = 1;
	int t3[] = {1, 0, -1, 0};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	int t4[] = {0, 1, 0, -1};
	vector <int> p4(t4, t4+sizeof(t4)/sizeof(int));
	MazeMaker * obj = new MazeMaker();
	clock_t start = clock();
	int my_answer = obj->longestPath(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p5 = -1;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p5 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p5 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	string t0[] = {".......",
 "X.X.X..",
 "XXX...X",
 "....X..",
 "X....X.",
 "......."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 5;
	int p2 = 0;
	int t3[] = {1, 0, -1, 0,-2, 1};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	int t4[] = {0, -1, 0, 1, 3, 0};
	vector <int> p4(t4, t4+sizeof(t4)/sizeof(int));
	MazeMaker * obj = new MazeMaker();
	clock_t start = clock();
	int my_answer = obj->longestPath(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p5 = 7;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p5 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p5 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	string t0[] = {"......."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 0;
	int p2 = 0;
	int t3[] = {1, 0, 1, 0, 1, 0};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	int t4[] = {0, 1, 0, 1, 0, 1};
	vector <int> p4(t4, t4+sizeof(t4)/sizeof(int));
	MazeMaker * obj = new MazeMaker();
	clock_t start = clock();
	int my_answer = obj->longestPath(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p5 = 6;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p5 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p5 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test5() {
	string t0[] = {"..X.X.X.X.X.X."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 0;
	int p2 = 0;
	int t3[] = {2,0,-2,0};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	int t4[] = {0,2,0,-2};
	vector <int> p4(t4, t4+sizeof(t4)/sizeof(int));
	MazeMaker * obj = new MazeMaker();
	clock_t start = clock();
	int my_answer = obj->longestPath(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p5 = -1;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p5 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p5 != my_answer) {
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

