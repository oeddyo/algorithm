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

class NewAlbum {
    public:
            int leastAmountOfCDs(int, int, int);
};

int NewAlbum::leastAmountOfCDs(int nSongs, int length, int cdCapacity) {
    int cd_number = 1;
    int cap_left  = cdCapacity-length;
    int songsInAlbum = 1;
    nSongs--;
    while(nSongs>0){
        int l = length+1;
        if(cap_left >= l){
            cap_left-=l;
            nSongs--;
            songsInAlbum++;
        }else{
            if(songsInAlbum%13==0){
                cap_left += length;
                nSongs++;
                songsInAlbum-=1;
            }
            cap_left = cdCapacity;
            cap_left-= length;
            nSongs--;
            cd_number+=1;
            songsInAlbum = 1;
        }
        cout<<nSongs<<" songs with "<<cap_left<<" capacity left and "<<songsInAlbum<<" in album"<<endl;
        if(songsInAlbum%13==0 && nSongs==0){
                cap_left = cdCapacity;
                cap_left -= length;
                nSongs = 1;
                cd_number+=1;
                songsInAlbum = 1;
        }
    }
    return cd_number;
}

double test0() {
	int p0 = 31;
	int p1 = 25;
	int p2 = 483;
	NewAlbum * obj = new NewAlbum();
	clock_t start = clock();
	int my_answer = obj->leastAmountOfCDs(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 2;
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
	int p0 = 20;
	int p1 = 1;
	int p2 = 100;
	NewAlbum * obj = new NewAlbum();
	clock_t start = clock();
	int my_answer = obj->leastAmountOfCDs(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 1;
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
	int p0 = 26;
	int p1 = 1;
	int p2 = 100;
	NewAlbum * obj = new NewAlbum();
	clock_t start = clock();
	int my_answer = obj->leastAmountOfCDs(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 2;
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
	int p0 = 26;
	int p1 = 3;
	int p2 = 51;
	NewAlbum * obj = new NewAlbum();
	clock_t start = clock();
	int my_answer = obj->leastAmountOfCDs(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 3;
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
	int p0 = 67;
	int p1 = 271;
	int p2 = 1000;
	NewAlbum * obj = new NewAlbum();
	clock_t start = clock();
	int my_answer = obj->leastAmountOfCDs(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 23;
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
double test5() {
	int p0 = 27;
	int p1 = 1;
	int p2 = 27;
	NewAlbum * obj = new NewAlbum();
	clock_t start = clock();
	int my_answer = obj->leastAmountOfCDs(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 3;
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
