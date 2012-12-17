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
string my_dic[MAXN];
int d_cnt = 0,digit = 0;
string N;

string num_2_letter[20] = {
    "","","ABC","DEF","GHI","JKL","MNO","PRS","TUV","WXY"
};

map <string, int> mymap;
void dfs(int cur, string t){
    if(cur==digit){
        mymap[t] = 1;
        if(N=="463373633623")
            cout<<t<<endl;
        return ;
    }
    int cur_num = N[cur]-'0';
    for(int i=0; i<3; i++){
        dfs(cur+1, t+num_2_letter[cur_num][i]);
    }
}

void work(){
    ofstream fout("namenum.out");
    //reverse(num.begin(), num.end());
    digit = N.size(); 
    dfs(0,"");
    int ans_cnt = 0;
    for(int i=0; i<d_cnt; i++){
        if( mymap.find(my_dic[i])!=mymap.end()){
            fout<<my_dic[i]<<endl;
            ans_cnt++;
        }
    }
    if(ans_cnt==0){
        fout<<"NONE"<<endl;
    }
}

void init(){
    ifstream tin ("dict.txt");
    d_cnt=0;
    while(tin>>my_dic[d_cnt++]){
    }
}

int main(){
    string t;
    
    fin>>N;
    digit = N.size();


    init();
    ifstream fin ("namenum.in");
    while(fin>>N){
        cout<<"N is "<<N<<endl;
        init();
        work();
    }
    return 0;
}

