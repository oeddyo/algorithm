#include <iostream>
#include <string.h>
#include <vector>
#include <map>
#include <set>

using namespace std;


const int INF = 999999999;

int shoes[4];
void work(){
    set<int> S;
    for(int i=0; i<4; i++){
        S.insert(shoes[i]);
    }
    cout<<4-S.size()<<endl;

}


int main(){
    for(int i=0; i<4; i++){
        cin>>shoes[i];
    }
    work();

    return 0;
}

