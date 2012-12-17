/*
ID: xieke.b1
PROG: ariprog
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

ofstream fout("ariprog.out");
ifstream fin ("ariprog.in");

vector<int> bis;
const int MMAX = 125001;
int is_bi[MMAX];
int t_ok[MMAX];
int N,M;
vector< pair<int,int> > ans;
typedef pair<int, int> pii;

void work(){
    int b_sz = bis.size();
    for(int i=0; i<b_sz; i++){
        //cout<<"pos "<<i<<endl;
        int start = bis[i];
        //cout<<"start is "<<start<<endl;
        for(int pro=1; pro<=M*M; pro++){
            bool ok=true;
            bool should_break = false;
            for(int j=N-1; j>=1; j--){
                int t= start+pro*j;
                if(t>=MMAX){
                    should_break=true;
                    ok=false;break;
                }
                if(is_bi[t]==0){
                    ok = false;
                    break;
                }
            }
            if(ok){
                ans.push_back( pii(pro, start) );
            }
            if(should_break)break;
        }
    }
    if(ans.size()==0){
        fout<<"NONE"<<endl;
        return ;
    }
    sort(ans.begin(), ans.end());
    for(int i=0; i<ans.size(); i++){
        fout<<ans[i].second<<" "<<ans[i].first<<endl;
    }
}

int main(){
    fin>>N>>M; 
    memset(t_ok,0,sizeof(t_ok));
    for(int i=0; i<=M; i++){
        for(int j=0; j<=M; j++){
            t_ok[i*i+j*j]=1;
        }
    }
    memset(is_bi,0,sizeof(is_bi));
    for(int i=0; i<MMAX; i++){
        if(t_ok[i]){
            bis.push_back(i);
            is_bi[i] = 1;
        }
    }
    work();
    return 0;
}

