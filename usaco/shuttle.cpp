/*
ID: xieke.b1
PROB: shuttle
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <queue>
#include <map>
#include <stack>
#include <vector>
#include <string.h>

using namespace std;
ifstream fin("shuttle.in");
ofstream fout("shuttle.out");

const int INF = 999999999;
int N;

//map<string, int> mmap;
map< long long int, int> mmap;
typedef pair< string, pair<int, int> > psii;
typedef pair< int, int> pii;
int find_loc(string &s){
    for(int i=0; i<N+N+1; i++){
        if(s[i]==' '){
            return i;
        }
    }
}

const int MAXN = 2000000;
string states[MAXN];
int pre[MAXN];
int opers[MAXN];
long long int get_hash(string &s){
    long long int sum = 0;
    for(int i=0; i<2*N+1; i++){
        if(s[i]==' '){
            sum*=3;
        }else if(s[i]=='B'){
            sum = sum*3+1;
        }else if(s[i]=='W'){
            sum = sum*3+2;
        }
    }
    return sum;
}

void exchange(string &s, int a, int b){
    char tmp;
    tmp = s[a];
    s[a] = s[b];
    s[b] = tmp;
}


void work(){
    string t = "", final = "";
    for(int i=0; i<N; i++){t+='W';final+='B';}
    t+=" ";
    final+=' ';
    for(int i=0; i<N; i++){t+='B';final+='W';};
    
    int ptr = 0;
    states[ptr] = t;
    pre[ptr] = -1;
    ptr += 1;
    psii init(t, pii(N, 0) );

    queue<   psii > Q;
    Q.push(init);
    psii cur;
    int sz = N+N+1;
    char tmp_char;
    vector<int> ans;
    int sz_max = -1;
    while(!Q.empty()){
        cur = Q.front();Q.pop();
        //cout<<cur.first<<" "<<endl;
        int pos = cur.second.first;
        int cur_state = cur.second.second;
        if(cur.first==final){
            string state = cur.first;
            int state_idx = cur.second.second;
            while(pre[state_idx]!=-1){
                int oper = opers[state_idx];
                int loc = find_loc(state);
                //cout<<"state is "<<state<<" idx = "<<state_idx<<" op = "<<oper<<" cur_loc = "<<loc;
                if(oper==0){
                    ans.push_back(loc);
                }else if(oper==1){
                    ans.push_back(loc);
                }else if(oper==2){
                    ans.push_back(loc);
                }else if(oper==3){
                    ans.push_back(loc);
                }
                //cout<<" loc = "<<ans[ans.size()-1]<<endl;
                state_idx = pre[state_idx] ;
                state = states[state_idx];
                //cout<<"tracking "<<state<<endl;
            }
            break;
        }
        
        if(pos>=1){
            exchange(cur.first, pos, pos-1);
            long long int h_value = get_hash(cur.first);
            if(mmap.find(h_value) == mmap.end()){
                mmap[h_value] = 0;
                opers[ptr] = 0;
                states[ptr] = cur.first;
                pre[ptr] = cur_state;
                Q.push( psii(cur.first, pii(pos-1, ptr)));
                ptr++;
            }
            exchange(cur.first, pos, pos-1);
        }

        if(pos<sz-1){
            exchange(cur.first, pos, pos+1);
            long long int h_value = get_hash(cur.first);
            if(mmap.find(h_value) == mmap.end()){
                mmap[h_value] = 1;
                opers[ptr] = 1;
                states[ptr] = cur.first;
                pre[ptr] = cur_state;
                Q.push(psii(cur.first, pii(pos+1, ptr)));
                ptr++;
            }
            exchange(cur.first, pos, pos+1);
        }

        if(pos>1){
            exchange(cur.first, pos, pos-2);
            long long int h_value = get_hash(cur.first);
            if(mmap.find(h_value) == mmap.end()){
                mmap[h_value] = 2;
                opers[ptr] = 2;
                states[ptr] = cur.first;
                pre[ptr] = cur_state;
                Q.push(psii(cur.first, pii(pos-2, ptr)));
                ptr++;
            }
            exchange(cur.first, pos, pos-2);
        }

        if(pos<sz-2){
            exchange(cur.first, pos, pos+2);
            long long int h_value = get_hash(cur.first);
            if(mmap.find(h_value) == mmap.end()){
                mmap[h_value] = 3;
                opers[ptr] = 3;
                states[ptr] = cur.first;
                pre[ptr] = cur_state;
                Q.push(psii(cur.first, pii(pos+2, ptr)));
                ptr++;
            }
            exchange(cur.first, pos, pos+2);
        }
        
    }
    cout<<"max size is "<<sz_max<<endl;
    cout<<"states max is "<<mmap.size()<<endl;
    int cnt = 0;
    for(int i=ans.size()-1; i>=0; i--){
        cnt++;
        if(cnt==20){
            cout<<ans[i]+1<<endl;
            cnt = 0;
        }else{
            cout<<ans[i]+1<<" ";
        }
    }
    cout<<endl;
}


int main(){
    fin>>N;
    work();
    
    return 0;
}

