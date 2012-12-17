#include <iostream>
#include <vector>
#include <string>
//#include <string.h>
using namespace std;

int K;
vector <int> L;
string letter;
int sz;
bool vis[13];

bool dfs(int num, int pos, int sum){
    
    vis[pos] = 1;
    for(int i=0; i<sz; i++){
        if(!vis[i]){
            dfs(i, sum+L[i]);



}


void work(){
    sz = L.size();



}


int main(){
    while(1){
    cin>>K;
    cin>>letter;
    if(K==0 && letter=="END"){
        break;
    }
    L.clear();
    for(int i=0; i<letter.size(); i++){
        L.push_back(letter[i]-'A'+1);
    }
    sort(L.begin(), L.end());
    work();
    }

    return 0;
}

