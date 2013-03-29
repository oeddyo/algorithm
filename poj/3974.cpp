#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

string Str;
int test = 1;
const int MAXN = 100001;
int failure[MAXN];

void build_kmp(){
    failure[0] = failure[1] = 0;
    int M = Str.length();
    
    for(int i=2; i<=M; i++){
        int j = failure[i-1];
        
        for(;;){
            if(Str[i-1]==Str[j]){
                failure[i] = j+1;
                break;
            }
            if(j==0){
                failure[i] = 0;
                break;
            }
            j = failure[j];
        }
    }
    for(int i=0; i<=M; i++){
        cout<<failure[i]<<" ";
    }cout<<endl;

}

void work(){
    build_kmp();



}


int main(){
    while(cin>>Str){
    work();

    }

    return 0;
}

