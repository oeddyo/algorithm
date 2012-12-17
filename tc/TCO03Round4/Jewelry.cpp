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
const int MAXN=31*1000;
class Jewelry {
    public:
        int dp_left[MAXN], dp_right[MAXN];
        int n_Jewelry;
        long long howMany(vector <int>);
        int get_sum(int left, int right, vector <int> &values){
            int sum = 0;
            for(int i=left; i<=right; i++){
                sum+=values[i];
            }
            return sum;
        }

        void get_left(int left, int right, vector <int> &values){
            memset(dp_left,0,sizeof(dp_left));
            dp_left[values[right]] = 1;
            int sum = get_sum(left, right, values);
            for(int i=sum; i>=0; i--){
                for(int k=left; k<right; k++){
                    if(i-values[k] < 0)continue;
                    dp_left[i] += dp_left[i-values[k]];
                }
            }
        }

        void get_right(int left, int right, vector <int> &values){
            memset(dp_right,0,sizeof(dp_right));
            dp_right[0] = 1;
            int sum = get_sum(left, right, values);
            for(int i=sum; i>=0; i--){
                for(int k=left; k<=right; k++){
                    if(i-values[k]<0)continue;
                    dp_right[i] += dp_right[i-values[k]];
                }
            }
        }
};

long long Jewelry::howMany(vector <int> values) {
    n_Jewelry = values.size();
    sort(values.begin(), values.end());
    int sum = 0;
    for(int i=0; i<n_Jewelry; i++){
        sum+=values[i];
    }
    long long ans = 0;
    for(int i=0; i<n_Jewelry-1; i++){
        /*test code here*/
    //    cout<<"now i is "<<i<<endl;
        int left_sum = get_sum(0,i,values);
        int right_sum = get_sum(i+1, n_Jewelry-1, values);

        get_left(0,i,values);
      /*  cout<<"dp_left is "<<endl;
        for(int j=0; j<=left_sum; j++){
            cout<<dp_left[j]<<" ";
        }
        
        cout<<endl;
        */
        get_right(i+1, n_Jewelry-1,values);
        /*
        cout<<"dp_right is "<<endl;
        for(int j=0; j<=right_sum; j++){
            cout<<dp_right[j]<<" ";
        }
        cout<<"left -> "<<0<<","<<i<<endl;
        cout<<"right-> "<<i+1<<","<<n_Jewelry-1<<endl;
        cout<<endl;
        */
        for(int j=values[i]; j<=min(left_sum, right_sum); j++){
            if(dp_left[j]!=0 && dp_right[j]!=0){
                ans+=dp_left[j]*dp_right[j];
                cout<<"now that dp_left["<<j<<"] == dp_right["<<j<<"]"<<" adding "<<dp_left[j]*dp_right[j]<<endl;
            }
        }
    }
    return ans;
}
double test0() {
	int t0[] = {1,2,5,3,4,5};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	Jewelry * obj = new Jewelry();
	clock_t start = clock();
	long long my_answer = obj->howMany(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p1 = 9LL;
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
	int t0[] = {1000,1000,1000,1000,1000,
 1000,1000,1000,1000,1000,
 1000,1000,1000,1000,1000,
 1000,1000,1000,1000,1000,
 1000,1000,1000,1000,1000,
 1000,1000,1000,1000,1000};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	Jewelry * obj = new Jewelry();
	clock_t start = clock();
	long long my_answer = obj->howMany(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p1 = 18252025766940LL;
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
	int t0[] = {1,2,3,4,5};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	Jewelry * obj = new Jewelry();
	clock_t start = clock();
	long long my_answer = obj->howMany(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p1 = 4LL;
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
	int t0[] = {7,7,8,9,10,11,1,2,2,3,4,5,6};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	Jewelry * obj = new Jewelry();
	clock_t start = clock();
	long long my_answer = obj->howMany(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p1 = 607LL;
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
	int t0[] = {123,217,661,678,796,964,54,111,417,526,917,923};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	Jewelry * obj = new Jewelry();
	clock_t start = clock();
	long long my_answer = obj->howMany(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p1 = 0LL;
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

