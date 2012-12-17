/*
ID: xieke.b1
PROB: runround
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <vector>
#include <string.h>

using namespace std;
ifstream fin("runround.in");
ofstream fout("runround.out");

const int INF = 999999999;
typedef vector<int> vi;

vi num;
int len, N;
bool vis[10];
bool judge(vi & n){
    memset(vis,0,sizeof(vis));
    int t_len = len;
    int cur = 0;
    while(t_len--){
        int cur_num = n[cur];
        cur = (cur+n[cur])%len;
        if(vis[cur])return false;
        vis[cur] = true;
    }
    return true;
}

void print(vi &n){
    for(int i=0; i<len; i++){
        cout<<n[i];
    }cout<<endl;
}
void get_next(vi &n){
    bool ok = 0;
    for(int i=len-1; i>=0; i--){
        if(n[i]<9){
            //cout<<"i'm in "<<i<<endl;
            n[i]++;
            ok = 1;
            for(int j=i+1; j<=len-1; j++){
            //    cout<<"change "<<j<<endl;
                n[j] = 1;
            }
            //print(n);
            return ;
        }
    }
    
    vi t;
    t.push_back(1);
    for(int i=0; i<len; i++)t.push_back(1);
    len+=1;
    n = t;
}

void work(){
    int t_N = N;
    while(t_N){
        num.push_back(t_N%10);
        t_N/=10;
    }
    len = num.size();
    reverse(num.begin(), num.end());
    get_next(num);

    while(1){
        if(judge(num)){
            print(num);
            break;
        }else{
            get_next(num);
            print(num);
        }
    }
}

int main(){
    fin>>N;
    work();
     
    return 0;
}

