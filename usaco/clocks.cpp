/*
ID: xieke.b1
PROG: clocks
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <string.h>

using namespace std;

ofstream fout("clocks.out");
ifstream fin ("clocks.in");

//int s[9];
vector<int> start;
vector<int> final;

string for_test = "112224";

const int MAXN = 1200000;

string dir[10]={
    "",
    "ABDE",
    "ABC",
    "BCEF",
    "ADG",
    "BDEFH",
    "CFI",
    "DEGH",
    "GHI",
    "EFHI"
};

int szs[10] = {
    0,
    4,3,4,3,5,3,4,3,4};


bool should_return;

//char path[50];

int compute(vector<int> &s){
    int res = 0;
    for(int i=0; i<9; i++){
        res = res*4+s[i];
    }
    return res;
}

//void dfs(vector<int> s, int depth, int p_path){
void print(vector<int> s){
    for(int i=0; i<s.size(); i++){
        cout<<s[i]<<" ";
    }
    cout<<endl;
}

void dfs(vector<int> s, int depth, string path){
    if(should_return){
        return ;
    }
    int t = compute(s);
    cout<<path<<endl;
    //cout<<"now path is "<<path<<endl;

    if(s==final){
        cout<<"in !!!"<<endl;
        //for(int i=0; i<p_path-1; i++)fout<<path[i]<<" ";
        //fout<<path[p_path-1]<<endl;
        fout<<path<<endl;
        should_return = true;
        return ;
    }
    if(path==for_test){
        cout<<"i could go here"<<endl;
    }
    if(depth<=0){
        return ;
    }
    //cout<<"depth = "<<depth<<endl;
    /*
    cout<<"now state is ";
    for(int i=0; i<s.size(); i++){
        cout<<s[i];
    }cout<<endl;
    */

    for(int i=1; i<=9; i++){
        int sz = szs[i];
        vector<int> ns=s;
        for(int j=0; j<sz; j++){
            int pos = dir[i][j]-'A';
            ns[pos]+=1;
            if(ns[pos]==4)ns[pos]=0;
            //ns[pos]%=12;
        }
        if(path==for_test){
            cout<<"after change state is "<<endl;
            print(ns);   
        }
        //path[p_path] = char('0'+i);
        //string np = path+char('0'+i);
        //dfs(ns, depth-1, p_path+1);
        dfs(ns, depth-1, path+char('0'+i));
    }
}

void work(){
    should_return = false;
    for(int depth=10; depth<=20; depth++){
        cout<<"depth is "<<depth<<endl;
        dfs(start, depth, "");

        if(should_return){
            return ;
        }

    }
}


int main(){
    for(int i=0; i<9; i++){
        int t;
        fin>>t;
        start.push_back((t/3)%4);
        final.push_back(0);
        //fin>>s[i];
    }
    work(); 
    return 0;
}

