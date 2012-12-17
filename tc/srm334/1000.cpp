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

class ExtendedHappyNumbers {
    public:
        long long calcTheSum(int, int, int);
};

#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i!= (c).end(); i++)

const int MAXN = 1000001;
int dp[MAXN];

int get_next(int num, int k){
    int sum = 0;
    while(num){
        int digit = num%10;
        int tmp = 1;
        for(int t=0; t<k; t++){
            tmp*=digit;
        }
        sum+=tmp;
        num/=10;
    }
    return sum;
}

long long ExtendedHappyNumbers::calcTheSum(int A, int B, int K) {
    memset(dp,-1,sizeof(dp));
    long long int ans = 0;
    int just_add = 0;
    for(int i=A; i<=B; i++){
        set<int> tmp_set;
        int t_min = i;
        cout<<"seeing "<<i<<endl;
        int next = i;
        tmp_set.insert(next);
        while(1){
            next = get_next(next,K);
            cout<<"next is "<<next<<endl;
            t_min = min(next, t_min);
            if(tmp_set.find(next)!=tmp_set.end()){
                tr(tmp_set, it){
                    if(*it<MAXN)
                        dp[*it] = t_min;
                }
                ans+=t_min;
                just_add = t_min;
                break;
            }else if(dp[next]!=-1){
                tr(tmp_set, it){
                    if(*it<MAXN)
                        dp[*it] = min(t_min, dp[next]);
                }
                ans+=min(dp[next], t_min);
                cout<<"!!!! dp!!!"<<endl;
                cout<<"add "<<min(dp[next],t_min)<<endl;
                just_add = min(dp[next],t_min);
                break;
            }else{
                tmp_set.insert(next);
            }
        }
        cout<<"for "<<i<<" we get "<<t_min<<endl;
    }
    return ans;
    //return -1;
}
double test0() {
    int p0 = 13;
    int p1 = 13;
    int p2 = 2;
    ExtendedHappyNumbers * obj = new ExtendedHappyNumbers();
    clock_t start = clock();
    long long my_answer = obj->calcTheSum(p0, p1, p2);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    long long p3 = 1LL;
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
    int p1 = 5;
    int p2 = 2;
    ExtendedHappyNumbers * obj = new ExtendedHappyNumbers();
    clock_t start = clock();
    long long my_answer = obj->calcTheSum(p0, p1, p2);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    long long p3 = 14LL;
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
    int p0 = 10;
    int p1 = 99;
    int p2 = 1;
    ExtendedHappyNumbers * obj = new ExtendedHappyNumbers();
    clock_t start = clock();
    long long my_answer = obj->calcTheSum(p0, p1, p2);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    long long p3 = 450LL;
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
    int p0 = 535;
    int p1 = 538;
    int p2 = 3;
    ExtendedHappyNumbers * obj = new ExtendedHappyNumbers();
    clock_t start = clock();
    long long my_answer = obj->calcTheSum(p0, p1, p2);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    long long p3 = 820LL;
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
double test4() {
    int p0 = 100000;
    int p1 = 400000;
    int p2 = 6;
    ExtendedHappyNumbers * obj = new ExtendedHappyNumbers();
    clock_t start = clock();
    long long my_answer = obj->calcTheSum(p0, p1, p2);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    long long p3 = 5169721292LL;
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
    return 0;
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

