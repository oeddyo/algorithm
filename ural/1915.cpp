#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <list>
#include <stack>
#include <map>
#include <set>
using namespace std;
 
#define DEBUG
#define REP(i,a) for(i=0;i<a;i++)
#define FOR(i,a,b) for(i=a;i<b;i++)
#define VE vector<int>
#define SZ size()
#define PB push_back

const int MAXN = 1000010;
int op_count[MAXN], N, ops[MAXN];

int mystack[MAXN*2];
int s_p = 0;


int main(){

    cin>>N;
    for(int i=0; i<N; i++){
        int t;
        cin>>t;
        ops[i] = t;
    }

    for(int i=N; i>0; i--){
        //cout<<"look at "<<i<<endl;
        if(ops[i-1] == -1){
            op_count[i-1] += op_count[i] + 1;
            //cout<<"op_couunt["<<i-1<<" = "<<op_count[i-1]<<endl;
        }else{
            op_count[i-1] = op_count[i];
        }
    }

    for(int i=0; i<N; i++){
        if(ops[i] == 0){
            //cout<<"i = "<<i<<" op_count[i] = "<<op_count[i]<<" s_p = "<<s_p<<endl;
            if(op_count[i] < s_p){
                continue;
            }else{
            //cout<<"copying"<<endl;
                for(int i=0; i<s_p; i++){
                    mystack[i+s_p] = mystack[i];
                }
                s_p += s_p;
            }
        }else if(ops[i] == -1){
            //cout<<mystack[s_p-1]<<endl;
            printf("%d\n", mystack[s_p-1]);
            s_p -= 1;
        } else if(ops[i] > 0){
            mystack[s_p++] = ops[i];
        }
    }

    return 0;
}

