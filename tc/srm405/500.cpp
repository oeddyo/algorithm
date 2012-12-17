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

class RelativePath {
    public:
            string makeRelative(string, string);
};

int count_slash(string s, int pos){
    int sz = s.size();
    int sum =0;
    for(int i = pos; i<sz; i++){
        if(s[i]=='/'){
            sum++;
        }
    }
    return sum;
}

vector <string> get_split(string str){
    char *s = new char [str.size()+1];
    strcpy(s,str.c_str());
    char *p;
    p = strtok(s,"/");
    vector<string> res;
    while(p!=NULL){
        string t(p);
        res.push_back( t);
        p = strtok(NULL,"/");
    }
    return res;
}


string RelativePath::makeRelative(string path, string currentDir) {
    int ptr = 0;
    vector<string> my_path = get_split(path);
    vector<string> my_cur = get_split(currentDir);
    cout<<"vector are "<<endl;
    for(int i=0; i<my_path.size(); i++){
        cout<<my_path[i]<<" ";
    }cout<<endl;
    for(int i=0; i<my_cur.size(); i++){
        cout<<my_cur[i]<<" ";
    }cout<<endl;
    int sz_path = my_path.size();
    int sz_cur = my_cur.size();
    while(ptr<sz_path&&ptr<sz_cur){
        if(my_path[ptr]==my_cur[ptr]){
            ptr++;
        }else{
            break;
        }
    }
    string ans = "";
    if(ptr==sz_path){
        int n = sz_cur-sz_path;
        if(n==1){
            ans+="..";
        }else if(n==0){
            
        }else{
            ans+="..";
            for(int i=0; i<n-1; i++){
                ans+="/..";
            }
        }
    }else if(ptr==sz_cur){
        int n = sz_path - sz_cur;
        if(n==0){

        }else if(n==1){
            ans+=my_path[ptr];
        }else{
            ans+=my_path[ptr];
            for(int i=ptr+1; i<sz_path; i++){
                ans+="/";
                ans+=my_path[i];
            }
        }
    }else{
        ans+="..";
        for(int i=0; i<(sz_cur-ptr-1); i++)ans+="/..";
        for(int i=ptr; i<sz_path; i++){
            ans+="/";
            ans+=my_path[i];
        }
    }
    return ans;

}

double test0() {
	string p0 = "/home/top/data/file";
	string p1 = "/home/user/pictures";
	RelativePath * obj = new RelativePath();
	clock_t start = clock();
	string my_answer = obj->makeRelative(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "../../top/data/file";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	string p0 = "/home/user/movies/title";
	string p1 = "/home/user/pictures";
	RelativePath * obj = new RelativePath();
	clock_t start = clock();
	string my_answer = obj->makeRelative(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "../movies/title";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	string p0 = "/file";
	string p1 = "/";
	RelativePath * obj = new RelativePath();
	clock_t start = clock();
	string my_answer = obj->makeRelative(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "file";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	string p0 = "/a/b/a/b/a/b";
	string p1 = "/a/b/a/a/b/a/b";
	RelativePath * obj = new RelativePath();
	clock_t start = clock();
	string my_answer = obj->makeRelative(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "../../../../b/a/b";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	string p0 = "/root/root/root";
	string p1 = "/root";
	RelativePath * obj = new RelativePath();
	clock_t start = clock();
	string my_answer = obj->makeRelative(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "root/root";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
