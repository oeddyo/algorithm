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

class SentenceDecomposition {
    public:
            int decompose(string, vector <string>);
};

const int MAXN = 51;
int my_count[MAXN][27];
int dp[MAXN][MAXN];
const int INF = 99999999;
vector<string> g_validWords;
string g_sentence;

int check(int i, int j, int k){
    int c[26];
    memset(c,0,sizeof(c));
    for(int p=i; p<=j; p++){
        c[g_sentence[p]-'a']++;
    }
    for(int p=0; p<26; p++){
        if(my_count[k][p]==c[p]){
            continue;
        }else{
            return INF;
        }
    }
    int sum = 0;
    for(int p_a=0, p_b=i; p_b<=j; p_b++, p_a++){
        if(g_validWords[k][p_a]!=g_sentence[p_b]){
            sum++;
        }
    }
    return sum;
}

int SentenceDecomposition::decompose(string sentence, vector <string> validWords) {
    for(int i=0; i<MAXN; i++)for(int j=0; j<MAXN; j++)dp[i][j] = INF;
    memset(my_count,0,sizeof(my_count));
    for(int i=0; i<validWords.size(); i++){
        for(int j=0; j<validWords[i].size(); j++){
            my_count[i][validWords[i][j]-'a']++;
        }
    }
    g_validWords = validWords;
    g_sentence = sentence;
    //base here
    int sz = sentence.size();
    for(int i=0; i<sz; i++){
        for(int j=i; j<sz; j++){
            for(int k=0; k<validWords.size(); k++){
                int t = check(i,j,k);
                if(t<dp[i][j]){
                    cout<<i<<"-"<<j<<" "<<t<<endl;
                }
                dp[i][j] = min(t,dp[i][j]);
            }
        }
    }
    for(int i=0; i<sz; i++){
        for(int len=1; i+len<sz; len++){
            for(int j=i; j<=i+len; j++){
                if(dp[i][j] == INF || dp[j+1][i+len]==INF){
                    continue;
                }else{
                    dp[i][i+len] = min(dp[i][i+len], dp[i][j]+dp[j+1][i+len]);
                }
            }
        }
    }
    if(dp[0][sz-1]==INF){
        return -1;
    }else{
        return dp[0][sz-1];
    }
}
double test0() {
	string p0 = "neotowheret";
	string t1[] = {"one", "two", "three", "there"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	SentenceDecomposition * obj = new SentenceDecomposition();
	clock_t start = clock();
	int my_answer = obj->decompose(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 8;
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
	string p0 = "abba";
	string t1[] = {"ab", "ac", "ad"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	SentenceDecomposition * obj = new SentenceDecomposition();
	clock_t start = clock();
	int my_answer = obj->decompose(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 2;
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
	string p0 = "thisismeaningless";
	string t1[] = {"this", "is", "meaningful"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	SentenceDecomposition * obj = new SentenceDecomposition();
	clock_t start = clock();
	int my_answer = obj->decompose(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = -1;
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
	string p0 = "ommwreehisymkiml";
	string t1[] = {"we", "were", "here", "my", "is", "mom", "here", "si", "milk", "where", "si"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	SentenceDecomposition * obj = new SentenceDecomposition();
	clock_t start = clock();
	int my_answer = obj->decompose(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 10;
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
	string p0 = "ogodtsneeencs";
	string t1[] = {"go", "good", "do", "sentences", "tense", "scen"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	SentenceDecomposition * obj = new SentenceDecomposition();
	clock_t start = clock();
	int my_answer = obj->decompose(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 8;
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
double test5() {
	string p0 = "sepawaterords";
	string t1[] = {"separate","words"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	SentenceDecomposition * obj = new SentenceDecomposition();
	clock_t start = clock();
	int my_answer = obj->decompose(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = -1;
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
	
	time = test5();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

