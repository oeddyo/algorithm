/*
ID: xieke.b1
PROB: msquare
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <string.h>
#include <cmath>

using namespace std;

ifstream fin("msquare.in");
ofstream fout("msquare.out");

typedef pair<int, int> pii;
const int MAXN = 200000;
const int PRIME = 100003;
const int INF = 2100000000;
int N;

//int final[8];
vector<int> final;
typedef struct _node{
    //int array[8];
    vector<int> array;
    short step;
    int pre;
    int pos;
    short op;
}node;

node states[MAXN];
int ptr = 0;

//vector<node> hash_table[PRIME];
vector< int > hash_table[PRIME];

int sizes[PRIME];
int convert(vector<int> &n){
    int sum = 0;
    for(int i=0; i<8; i++){
        sum=sum*10+n[i];
    }
    return sum;
}

int get_hash( vector<int> &n){
    int sum = 0;
    for(int i=0; i<8; i++){
        sum=sum*7+ n[i];
    }
    return sum%PRIME;
}

bool in_hash(node &n){
    int h_value = get_hash(n.array);
    int v = convert(n.array);
    if(sizes[h_value]==0)return false;
    
    for(int i=0; i<sizes[h_value]; i++){
        if(hash_table[h_value][i]==v)return true;
    }
    return false;

}

void hash_insert(node &n){
    int h_value = get_hash(n.array);
    hash_table[h_value].push_back(convert(n.array));
    sizes[h_value]+=1;
}
void print(vector<int> p){
    for(int i=0; i<4; i++){
        cout<<p[i]<<" ";
    }cout<<endl;
    for(int i=4; i<8; i++){
        cout<<p[i]<<" ";
    }cout<<endl;
}

void work(){
    queue<node> Q;
    node initial;
    for(int i=0; i<4; i++){
        initial.array.push_back( i+1 );
    } 
    for(int i=7; i>=4; i--){
        initial.array.push_back(i+1);
    }

    initial.step=0;
    initial.pre=-1;
    initial.op = -1;
    initial.pos = 0;

    states[0] = initial;
    Q.push(initial);
    
    hash_insert(initial);

    ptr+=1;

    while(!Q.empty()){
        node cur = Q.front();
        Q.pop();
        if(cur.array==final){
            vector<int> ans;
            int pre = cur.pos;
            fout<<cur.step<<endl;
            while(pre!=-1){
                ans.push_back(states[pre].op);
                pre = states[pre].pre;
            }
            for(int i=ans.size()-1; i>=0; i--){
                if(ans[i]==1){
                    fout<<'A';
                }else if(ans[i]==2){
                    fout<<"B";
                }else if(ans[i]==3){
                    fout<<"C";
                }
            }fout<<endl;
            break;
        }
    
        states[ptr] = cur;

        for(int i=0; i<4; i++){
            swap(states[ptr].array[i], states[ptr].array[i+4]);
        }
        if(! in_hash(states[ptr]) ){
            states[ptr].step = cur.step+1;
            states[ptr].op = 1;
            states[ptr].pre = cur.pos;
            states[ptr].pos = ptr;
            hash_insert(states[ptr]);
            Q.push(states[ptr]);
            ptr++;
        }
        /*
        cout<<"first change "<<endl;
        print(states[ptr].array);
        */
        
        states[ptr] = cur;
        int t = states[ptr].array[3];
        states[ptr].array.erase(states[ptr].array.begin()+3);
        states[ptr].array.insert(states[ptr].array.begin()+0, t);
        t = states[ptr].array[7];
        states[ptr].array.erase(states[ptr].array.begin()+7);
        states[ptr].array.insert(states[ptr].array.begin()+4, t);
        
        if( !in_hash(states[ptr] ) ){
            states[ptr].step = cur.step+1;
            states[ptr].op = 2;
            states[ptr].pre = cur.pos;
            states[ptr].pos = ptr;
            hash_insert(states[ptr]);
            Q.push(states[ptr]);
            ptr++;
        }
        /*
        cout<<"second change "<<endl;
        
        print(states[ptr].array);
        */
        states[ptr] = cur;
        t = states[ptr].array[1];
        states[ptr].array[1] = states[ptr].array[5];
        states[ptr].array[5] = states[ptr].array[6];
        states[ptr].array[6] = states[ptr].array[2];
        states[ptr].array[2] = t;
        if( !in_hash(states[ptr] ) ){
            states[ptr].step = cur.step+1;
            states[ptr].op = 3;
            states[ptr].pre = cur.pos;
            states[ptr].pos = ptr;
            hash_insert(states[ptr]);
            Q.push(states[ptr]);
            ptr++;
        }
        /*
        cout<<"last change "<<endl;
        print(states[ptr].array);
        */
    }

}


int main(){
    int t;
    int d[8];

    for(int i=0; i<8; i++){
        fin>>d[i];
    }
    for(int i=0; i<4; i++){
        final.push_back(d[i]);
    }
    for(int i=7; i>=4; i--){
        final.push_back(d[i]);
    }


    work();

    return 0;
}

