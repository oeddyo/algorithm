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

class PiecesMover {
    public:
            int getMinimumMoves(vector <string>);
};

//typedef pair< vector<string>, int > mypair;
typedef pair<int, int> mypair;


int vis[5][5];
int dir[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};
bool check(int i, int j, int s){
    if( ((s>>(i*5+j))&1)==1 ){
        return true;
    }else{
        return false;
    }
}
void dfs(int x,int y, int s){
    if(vis[x][y]==1)return ;
    int tx,ty;
    vis[x][y]=1;
    for(int i=0; i<4; i++){
        tx = dir[i][0]+x;
        ty = dir[i][1]+y;
        if(tx>=0&&tx<5&&ty>=0&&ty<5 && check(tx,ty,s)){
        //if(tx>=0&&tx<5 && ty>=0 && ty<5 && (s>>((tx*5+ty)>>1))==1){
            dfs(tx,ty,s);
        }
    }
}
bool judge(int s){
    memset(vis,0,sizeof(vis));
    bool should_break=false;
    for(int i=0; i<5; i++){
        if(should_break)break;
        for(int j=0; j<5; j++){
            if(check(i,j,s)){
            //if( (s>>(i*5+j)) == 1){
                dfs(i,j,s);
                should_break=true;
                break;
            }
        }
    }
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            if( check(i,j,s) && vis[i][j]==0){
                //if(board[i][j]=='*' && vis[i][j]==0){
                return false;
            }
        }
    }
    return true;
}
/*
void print(vector< string> &b){
    cout<<endl;
    for(int i=0; i<5; i++){
        cout<<b[i]<<endl;
    }
}
*/

int PiecesMover::getMinimumMoves(vector <string> board) {
    map <int, int> mymap;
   
    int s = 0;
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            if(board[i][j]=='*'){
                s|= (1<<(i*5)+j);
            }
        }
    }

    queue< mypair> Q;
    Q.push( mypair(s, 0));
    int cnt = 0;
    mymap[s] = cnt++; 
    mypair cur; 
    while(!Q.empty()){
        cur = Q.front();
        Q.pop();
        if(judge(cur.first)){
            return cur.second;
        }
        int tx,ty;
        int s=cur.first;
        for(int i=0; i<5; i++){
            for(int j=0; j<5; j++){
                if( check(i,j,s)){
                //if(qq[cur].first[i][j]=='*'){
                    for(int k=0; k<4; k++){
                        tx = dir[k][0] + i;
                        ty = dir[k][1] + j;
                        if(tx>=0 && tx<5 && ty>=0 && ty<5 && check(tx,ty,s)==false){
                        //if(tx>=0&&tx<5&&ty>=0&&ty<5  &&      && qq[cur].first[tx][ty]=='.'){
                            int next = (~(1<<(i*5+j)))&s;
                            next |= (1<<(tx*5+ty));

                            if(mymap.find(next)!=mymap.end()){
                                continue;
                            }else{
                                Q.push( mypair(next,cur.second+1));
                                mymap[next] = cnt++;
                            }
                            /*
                            if(mymap.find(qq[cur].first)!=mymap.end()){
                                continue;
                            }else{
                                qq[cnt].first = qq[cur].first;
                                qq[cnt].second = qq[cur].second+1;
                                Q.push(cnt);
                                mymap[qq[cur].first] = cnt++;
                                //Q.push( mypair(cur.first, cur.second+1));
                            }
                            */
                        }
                    }
                }
            }
        }
    }
}

double test0() {
/*
    string t0[] = {".....",
 "..**.",
 ".....",
 "...*.",
 "....."}
;*/
string t0[] = {"*...*", ".....", "..*..", ".....", "*...*"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	PiecesMover * obj = new PiecesMover();
	clock_t start = clock();
	int my_answer = obj->getMinimumMoves(p0);
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
double test1() {
	string t0[] = {".....",
 ".....",
 ".**..",
 ".*...",
 "**..."}
;
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	PiecesMover * obj = new PiecesMover();
	clock_t start = clock();
	int my_answer = obj->getMinimumMoves(p0);
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
double test2() {
	string t0[] = {"*...*",
 ".....",
 ".....",
 ".....",
 "*...*"}
;
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	PiecesMover * obj = new PiecesMover();
	clock_t start = clock();
	int my_answer = obj->getMinimumMoves(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 12;
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
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
