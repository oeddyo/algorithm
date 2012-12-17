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

#define MAXN 103
using namespace std;

vector <string> mybad;

long long  dp[MAXN][MAXN];
class AvoidRoads {
    public:
            long long numWays(int, int, vector <string>);
};

int *num(string s){
    //cout<<s<<endl;
    s+=' ';
    int sz = s.size();
    int *p = (int* )malloc(5*sizeof(int));
    int cnt =0,sum=0;
    for(int i=0; i<sz; i++){
        if(s[i]==' '){
           *(p+cnt) = sum;
           cnt++;
           sum=0;
        }else{
            sum = sum*10+s[i]-'0';
        }
    }
    //*(p+cnt) = sum;
    return p;
}


bool ok_down(int w, int h){
    for(int i=0; i<mybad.size();i++){
        int *p = num(mybad[i]);
        if(p[0]==p[2] && p[0]==w){
            //down
            int t_max = max(p[3],p[1]);
            int t_min = min(p[3],p[1]);
            if( h<=t_max && h-1>= t_min ){
                return false;
            }
        }
    }
    return true;
}

bool ok_left(int w, int h){
    for(int i=0; i<mybad.size();i++){
        int *p = num(mybad[i]);
        if(p[1]==p[3] && p[1]==h){
            //left
            //cout<<" p are "<<p[0]<<" "<<p[1]<<" "<<p[2]<<" "<<p[3]<<endl;
            int t_max = max(p[0],p[2]);
            int t_min = min(p[0],p[2]);
            //cout<<"w and h are "<<w<<" "<<h<<endl;
            //cout<<"t_max and t_min "<<t_max<<" "<<t_min<<endl;
            //cout<<"w and w-1 are "<<w<<" "<<w-1<<endl;
            if( w<=t_max && w-1>= t_min ){
                //cout<<"can't travel left"<<endl;
                return false;
            }
        }
    }
    return true;
}

long long  get_dp(int w, int h){
    //cout<<" now at "<<w<<" "<<h<<endl;
    if(dp[w][h]!=-1){
        //cout<<"return "<<w<<" "<<h<<endl;
        return dp[w][h];
    }
    long long  left=0, down=0;
    if(w-1>=0){
        if(ok_left(w, h)){
        //cout<<"go left"<<endl;
            left = get_dp(w-1, h);
        }
    }
    if(h-1>=0){
        if(ok_down(w,h)){
            down = get_dp(w,h-1);
        }
    }
    dp[w][h] = left + down;
    return dp[w][h];
}


long long AvoidRoads::numWays(int width, int height, vector <string> bad) {
        memset(dp,-1,sizeof(dp));
        dp[0][0] = 1;
        mybad = bad;
        long long  ans = get_dp(width, height);
        return ans;
}
double test0() {
	int p0 = 6;
	int p1 = 6;
	string t2[] = {"0 0 0 1","6 6 5 6"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	AvoidRoads * obj = new AvoidRoads();
	clock_t start = clock();
	long long my_answer = obj->numWays(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p3 = 252LL;
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
	int p0 = 1;
	int p1 = 1;
	vector <string> p2;
	AvoidRoads * obj = new AvoidRoads();
	clock_t start = clock();
	long long my_answer = obj->numWays(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p3 = 2LL;
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
	int p0 = 35;
	int p1 = 31;
	vector <string> p2;
	AvoidRoads * obj = new AvoidRoads();
	clock_t start = clock();
	long long my_answer = obj->numWays(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p3 = 6406484391866534976LL;
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
double test3() {
	int p0 = 2;
	int p1 = 2;
	string t2[] = {"0 0 1 0", "1 2 2 2", "1 1 2 1"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	AvoidRoads * obj = new AvoidRoads();
	clock_t start = clock();
	long long my_answer = obj->numWays(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p3 = 0LL;
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
    //return 0;	
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

