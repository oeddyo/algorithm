#include <iostream>
using namespace std;

int main(){
    
    int k = 2;
    int cnt=0; 
    for(int i=2; i<=100000; i++){
        bool p = true;
        for(int j=2; j*j<(i); j++){
            if(i%j==0){
                p=false;
                break;
            }
        }
        if(p){
            cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}

