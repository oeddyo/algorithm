/*
ID: xieke.b1
PROG: namenum
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;


const int MAXN = 50000;
int d_cnt = 0,digit = 0;
int ans_cnt = 0;
string N;


ofstream fout("namenum.out");
string num_2_letter[20] = {
    "","","ABC","DEF","GHI","JKL","MNO","PRS","TUV","WXY"
};

map <string, int> mymap;
void dfs(int cur, string t){
    if(cur==digit){
        //mymap[t] = 1;
        if(mymap.find(t)!=mymap.end()){
            fout<<t<<endl;
            ans_cnt++;
        }
        return ;
    }
    int cur_num = N[cur]-'0';
    for(int i=0; i<3; i++){
        dfs(cur+1, t+num_2_letter[cur_num][i]);
    }
}

void work(){
    dfs(0,"");
    if(ans_cnt==0){
        fout<<"NONE"<<endl;
    }
}

int main(){
    string t;
    
    ifstream fin ("namenum.in");
    fin>>N;
    digit = N.size();
   
    ifstream tin ("dict.txt");
    d_cnt=0;
    while(tin>>t){
        if(t.size()==digit){
            mymap[t] = 1;
        }
    }
    work();
    
    return 0;
}

