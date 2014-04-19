#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>
#include <stack>
#include <map>
#include <set>
using namespace std;

const int MAXN = 150000;
int turn[MAXN], N;
int mymap[MAXN];

void work(){
    vector<int> empty;
    
    for(int i=1; i<=N; i++){
        mymap[turn[i] ] += 1;
    }

    for(int i=1; i<=N; i++){
        if(mymap[i]>=2){    
            for(int j=1; j<=N; j++){
                if(turn[j] == i){
                    cout<<j<<endl;
                    return ;
                }
            }
        } 
    }




}




int main(){

    cin>>N;
    for(int i=1; i<=N; i++){
        cin>>turn[i];
        if(turn[i] == 1){
            cout<<i<<endl;
            return 0;
        }
    }

    work();


    return 0;
}

