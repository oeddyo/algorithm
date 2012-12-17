#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

const int INF = 999999999;
const int MAXN = 30;
int K;
string S;

int counts[MAXN];

void work(){
    int sz = S.size();
    if(sz%K!=0){
        cout<<-1<<endl;
        return ;
    }
    memset(counts,0,sizeof(counts));
    for(int i=0; i<sz; i++){
        counts[ S[i]-'a' ] +=1;
    }
    int n_type = 0;
    int should = -1;
    for(int i=0; i<MAXN; i++){
        if(counts[i]!=0){
            n_type+=1;
        }
        if(counts[i]!=0 && should!=-1){
            should = counts[i];
        }
    }

    for(int i=0; i<MAXN; i++){
        if(counts[i]%K != 0){
            cout<<-1<<endl;
            return ;
        }
    }
    
    int number = sz;
    for(int t=0; t<K; t++){
        for(int i=0; i<MAXN; i++){
            for(int j=0; j<counts[i]/K; j++){
                cout<<char(i+'a');
            }
        }
    }
    cout<<endl;
}

int main(){
    cin>>K;
    cin>>S;
    work();
    return 0;
}

