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

ofstream fout("namenum.out");
ifstream fin ("namenum.in");
ifstream din ("dict.txt");

const int MAXN = 5000;
string dic[MAXN];
int d_cnt = 0;
long long int N;
int digit = 0;
vector<int> num;
//int num[15];


string num_2_letter[10] = {
    "","","ABC","DEF","GHI","JKL","MNO","PRS","TUV","WXY"
};
map <string, int> mmap;
int ans_cnt = 0;

void dfs(int cur, string t){
    if(cur==digit){
        mmap[t] = 1;
        //cout<<t<<endl;
        if( mmap.find(t)!=mmap.end()){
            fout<<t<<endl;
            ans_cnt++;
        }
        return ;
    }
    int cur_num = num[cur];
    for(int i=0; i<3; i++){
        dfs(cur+1, t+num_2_letter[cur_num][i]);
    }
}

void work(){
    while(N){
        num.push_back(N%10);
        N/=10;
        digit++;
    }
    reverse(num.begin(), num.end());
    dfs(0,"");
    /* 
    for(int i=0; i<d_cnt; i++){
        if( mmap.find(dic[i])!=mmap.end()){
            fout<<dic[i]<<endl;
            ans_cnt++;
        }
    }*/
    if(ans_cnt==0){
        fout<<"NONE"<<endl;
    }
}


int main(){
    string t;
    while(din>>t){
        mmap[t] = 1;
        //dic[d_cnt++]=t;
    }
    fin>>N;
    din.close();
    fin.close();
    //cout<<"!! N "<<N<<endl;
    work();
    return 0;
}

