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

class FactoVisors {
    public:
            int getNum(vector <int>, vector <int>);
};

long long gcd(long long a, long long b){
    return b==0?a:gcd(b,a%b);
}
const int MAXN = 32000;
int p[MAXN];
int a[MAXN];
int num = 0;
void prime(){
    num=0;
    memset(a,0,sizeof(a));
    for(int i=2; i<MAXN; i++){
        if(!a[i]){
            p[num++] = i;
            for(int j=i+i; j<MAXN; j+=i){
                a[j] = 1;
            }
        }
    }
}

int m_p[MAXN];
int g_p[MAXN];
int FactoVisors::getNum(vector <int> divisors, vector <int> multiples) {
    long long m = 0;
    long long g = divisors[0];
    
    m = divisors[0]; 
    for(int i=1; i<divisors.size(); i++){
        m = m*divisors[i]/gcd(divisors[i],m);
        //cout<<" now m "<<m<<endl;
    }
    
    g = multiples[0];
    for(int i=1; i<multiples.size(); i++){
        g = gcd(multiples[i],g);
    }

    //factor m and g seperately
    prime();
    memset(m_p,0,sizeof(m_p));
    memset(g_p,0,sizeof(g_p));
    for(int i=0; i<num && m>1; i++){
        while(m>1){
            if(m%p[i]==0){
                m/=p[i];
                m_p[p[i]]++;
                cout<<p[i]<<"*";
            }else{
                break;
            }
        }
    }
    cout<<endl;

    for(int i=0; i<num && g>1; i++){
        while(g>1){
            if(g%p[i]==0){
                g/=p[i];
                g_p[p[i]]++;
                cout<<p[i]<<"*";
            }else{
                break;
            }
        }
    }
    cout<<endl;
    int ans = 0;
    int tmp = -1;
    for(int i=0; i<num; i++){
        if(g_p[p[i]] < m_p[p[i]]){
            return 0;
        }else{
            if(g_p[p[i]]==m_p[p[i]] && g_p[p[i]]==0)continue;
            if(tmp==-1){
                tmp = g_p[p[i]]-m_p[p[i]];
            }else{
                tmp *= (g_p[p[i]]-m_p[p[i]]);
            }
            cout<<"seeing "<<p[i]<<" differ is "<<g_p[p[i]] - m_p[p[i]]<<endl;
            ans+=g_p[p[i]]-m_p[p[i]];
        }
    }
    ans+=tmp+1;
    return ans;
}

double test0() {
	int t0[] = {1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {100};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	FactoVisors * obj = new FactoVisors();
	clock_t start = clock();
	int my_answer = obj->getNum(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 9;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int t0[] = {6,9};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {18};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	FactoVisors * obj = new FactoVisors();
	clock_t start = clock();
	int my_answer = obj->getNum(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 1;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int t0[] = {6,9};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {96,180};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	FactoVisors * obj = new FactoVisors();
	clock_t start = clock();
	int my_answer = obj->getNum(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int t0[] = {2,4};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {256};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	FactoVisors * obj = new FactoVisors();
	clock_t start = clock();
	int my_answer = obj->getNum(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 7;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	int t0[] = {1000,10000,100000};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {1000000000};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	FactoVisors * obj = new FactoVisors();
	clock_t start = clock();
	int my_answer = obj->getNum(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 25;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
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
