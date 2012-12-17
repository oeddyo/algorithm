#include <iostream>

using namespace std;

int main(){

    unsigned int x = 12;
    int cnt=0;
    while(x){
        x = x&(x-1);
        cnt++;
    }cout<<cnt<<endl;
    return 0;
}

