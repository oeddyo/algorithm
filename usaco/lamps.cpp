/*
ID: xieke.b1
PROB: lamps
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <vector>
#include <string.h>

using namespace std;
ifstream fin("lamps.in");
ofstream fout("lamps.out");

const int INF = 999999999;
typedef vector<int> vi;

int N,C;
vi off,on;
const int MAXN = 101;
vi lamps(101,1);
int state;

void flip_all(vi &lamp){
    for(int i=1; i<=N; i++){
        lamp[i] = lamp[i]^1;
    }
}

void flip_even(vi &lamp){
    for(int i=2; i<=N; i+=2){
        lamp[i]^=1;
    }
}
void flip_odd(vi &lamp){
    for(int i=1; i<=N; i+=2){
        lamp[i]^=1;
    }
}
void flip_3(vi &lamp){
    for(int i=1; i<=N;i+=3){
        lamp[i]^=1;
    }
}

bool judge(vi &num){
    for(int i=0; i<on.size(); i++){
        if(num[on[i]] !=1){
            return false;
        }
    }
    for(int i=0; i<off.size(); i++){
        if(num[ off[i] ] != 0){
            return false;
        }
    }
    return true;
}

void print(vi &num){
    for(int i=1; i<num.size(); i++){
        fout<<num[i];
    }
    fout<<endl;
}
bool mycmp(const vi &a, const vi &b){
    for(int i=1; i<a.size(); i++){
        if(a[i]==b[i])continue;
        return a[i]<b[i];
    }
    return true;
}

void work(){
    lamps = vi(N+1, 1);
    for(int i=0; i<N+1; i++)lamps[i] = 1;
   
    state = 0;
    vector< vi > ans;
    for(int i=0; i<16; i++){
        state = i;
        int count = __builtin_popcount(state);
        vi tmp_lamps = lamps;
        for(int j=0; j<4; j++){
            if( ((1<<j) & state) != 0){
                if(j==0){
                    flip_all(tmp_lamps);
                }else if(j==1){
                    flip_odd(tmp_lamps);
                }else if(j==2){
                    flip_even(tmp_lamps);
                }else if(j==3){
                    flip_3(tmp_lamps);
                }
            }
        }
        if( judge(tmp_lamps) ){
            
            cout<<"now ok , and now tmp and state are "<<state<<endl;
            //print(tmp_lamps);
            cout<<endl;
            if( state==0){
                if(C==count){
                    ans.push_back(tmp_lamps);
                }
            }else if( state==9){
                if(count<=C && C%2==0){
                    ans.push_back(tmp_lamps);
                }
            }
            else if (state == 8 ){
                if(count<=C && C%3==0){
                    ans.push_back(tmp_lamps);
                }
            }else{
                if(C>=count){
                    cout<<"now adding, C and count are "<<C<<" "<<count<<endl;

                    ans.push_back(tmp_lamps);
                }
            }
        }
    }
    cout<<"results :"<<endl;
    if(ans.size()==0){
        fout<<"IMPOSSIBLE"<<endl;
        return ;
    }
    sort(ans.begin(), ans.end(), mycmp);
    vi pre(N+1, -1);
    for(int i=0; i<ans.size(); i++){
       if(ans[i]!=pre){
            print(ans[i]);
            pre = ans[i];
        }
    }
}


int main(){
    fin>>N;
    fin>>C;
    int tmp;
    while(1){
        fin>>tmp;
        if(tmp==-1)break;
        on.push_back(tmp);
    }

    while(1){
        fin>>tmp;
        if(tmp==-1)break;
        off.push_back(tmp);
    }
    work();    

    return 0;
}

