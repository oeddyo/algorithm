/*
ID: xieke.b1
PROB: fracdec
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <stack>
#include <vector>
#include <string.h>

using namespace std;
ifstream fin("fracdec.in");
ofstream fout("fracdec.out");

const int INF = 999999999;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int MAXN = 102;
int A,B;

void work(){
    int int_part = A/B;
    string res = "";
    char tmp[50] ;
    sprintf(tmp, "%d", int_part);
    res+=tmp;
    res+=".";
    //cout<<tmp<<endl;

    //fout<<int_part<<".";
    
    int left = A%B;
    map<int, int> mymap;
    int pos = 0;
    string tmp_res;
    
    while(1){
        if( mymap.find(left) != mymap.end()){
            int pre_pos = mymap[left];
            for(int i=0; i<pre_pos; i++){
                //fout<<tmp_res[i];
                res+=tmp_res[i];
            }
            res+="(";
            //fout<<"(";
            for(int i=pre_pos; i<pos; i++){
                //fout<<tmp_res[i];
                res+=tmp_res[i];
            }
            //fout<<")"<<endl;
            res+=")";
            break;
        }
        //cout<<"left "<<left<<endl;
        mymap[left] = pos;
        left*=10;
        int add = left/B;
        tmp_res+=char('0'+add);
        left = left%B;
        pos++;
        if(left==0){
            for(int i=0; i<pos; i++){
                //fout<<tmp_res[i];
                res+=tmp_res[i];
            }
            //fout<<endl;
            break;
        }
    }
    int c_cnt = 0;
    for(int i=0; i<res.size(); i++){
        c_cnt+=1;
        if(c_cnt==76){
            c_cnt=0;
            fout<<res[i]<<endl;
        }else{
            fout<<res[i];
        }
    }
    if(c_cnt!=0){
        fout<<endl;
    }
}


int main(){
    fin>>A>>B; 
    work(); 
    
    return 0;
}

