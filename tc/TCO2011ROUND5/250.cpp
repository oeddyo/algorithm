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

class SistersErasingLetters {
    public:
        string whoWins(string);
};

string g_word;
int sz;
map<string, bool> mymap;
bool dfs(string w, int p, int step){
    if(mymap.find(w)!=mymap.end()){
        return mymap[w];
    }
    int t_sz = w.size(); 
    if(p==t_sz-2){
        if(w>g_word){
            return true;
        }else{
            return false;
        }
    }
    bool ok = false;
    for(int i=p+1; i<t_sz; i++){
        string t="";
        for(int k=0; k<t_sz; k++){
            if(k==i){
                continue;
            }else{
                t+=w[k];
            }
        }
        ok|=dfs(t,i, step^1);
    }
    bool ans;
    if(step==0){
        if(ok){
            ans = true;
        }else{
            ans = false;
        }
    }else{
        if(ok){
            ans = false;
        }else{
            ans = true;
        }
    }
   
    cout<<"now is "<<w<<" step is "<<step<<" "<<ans<<endl;
    mymap[w] = ans;
    return ans;
}


string SistersErasingLetters::whoWins(string word) {
    mymap.clear();
    sz = word.size();
    g_word = word;
    bool ans = dfs(word, -1,0);
    if(ans){
        return "Camomile";
    }else{
        return "Romashka";
    }
}
double test0() {
    string p0 = "topcoder";
    SistersErasingLetters * obj = new SistersErasingLetters();
    clock_t start = clock();
    string my_answer = obj->whoWins(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    string p1 = "Camomile";
    cout <<"Desired answer: " <<endl;
    cout <<"\t\"" << p1 <<"\"" <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t\"" << my_answer<<"\"" <<endl;
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
    string p0 = "program";
    SistersErasingLetters * obj = new SistersErasingLetters();
    clock_t start = clock();
    string my_answer = obj->whoWins(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    string p1 = "Romashka";
    cout <<"Desired answer: " <<endl;
    cout <<"\t\"" << p1 <<"\"" <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t\"" << my_answer<<"\"" <<endl;
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
    string p0 = "abcd";
    SistersErasingLetters * obj = new SistersErasingLetters();
    clock_t start = clock();
    string my_answer = obj->whoWins(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    string p1 = "Camomile";
    cout <<"Desired answer: " <<endl;
    cout <<"\t\"" << p1 <<"\"" <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t\"" << my_answer<<"\"" <<endl;
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
    string p0 = "abc";
    SistersErasingLetters * obj = new SistersErasingLetters();
    clock_t start = clock();
    string my_answer = obj->whoWins(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    string p1 = "Romashka";
    cout <<"Desired answer: " <<endl;
    cout <<"\t\"" << p1 <<"\"" <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t\"" << my_answer<<"\"" <<endl;
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
    string p0 = "easyproblemroundfivetopcoderopentwothousandeleven";
    SistersErasingLetters * obj = new SistersErasingLetters();
    clock_t start = clock();
    string my_answer = obj->whoWins(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    string p1 = "Camomile";
    cout <<"Desired answer: " <<endl;
    cout <<"\t\"" << p1 <<"\"" <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t\"" << my_answer<<"\"" <<endl;
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
    /*
    time = test0();
    if (time < 0)
        errors = true;
    */
    
    time = test1();
    if (time < 0)
        errors = true;
    return 0;
    time = test2();
    if (time < 0)
        errors = true;
return 0;
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

