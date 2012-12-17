/*
ID: xieke.b1
PROB: beads
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <map>

using namespace std;

string b;
int N;
const int INF = 999999999;

ofstream fout("beads.out");
ifstream fin("beads.in");
void work(){
    int sz = b.size();
    string t = b;
    b+= t;
    int ans = -INF;
    for(int i=0; i+sz<2*sz; i++){
        int e = i+sz-1;
        int cnt_left = 0;
        char color = b[i];
        int end_left;
        for(int s=i; s<i+sz; s++){
            if(color=='w' && b[s]!='w'){
                color = b[s];
                cnt_left++;
                continue;
            }
            if(b[s]==color || b[s]=='w'){
                cnt_left++;
                end_left = s;
            }else{
                break;
            }
        }

        if(cnt_left == sz){
            fout<<cnt_left<<endl;
            return ;
        }
        

        int cnt_right = 0;
        color = b[i+sz-1];
        int end_right;
        for(int s=i+sz-1; s>=i; s--){
            if(color=='w' && b[s]!='w'){
                color = b[s];
                cnt_right++;
                continue;
            }
            if(b[s]==color || b[s]=='w'){
                cnt_right++;
                end_right = s;
            }else{
                break;
            }
        }
    cout<<"pos "<<i<<" left right "<<cnt_left<<" "<<cnt_right<<endl;
        if(end_left>=end_right){
            ans = max(cnt_left, cnt_right);
        }else{
            ans = max(ans, cnt_left+cnt_right);
        }
    }
    fout<<ans<<endl;
}

int main(){

    while(fin>>N){
        fin>>b;
        work();
    }

    return 0;
}


