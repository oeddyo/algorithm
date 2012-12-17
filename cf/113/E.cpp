#include <iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    if(n==1){
        cout<<0<<endl;
        return 0;
    }

    long long pre = 0;
    int ok = 1;
    long long int now;
    long long m = 1000000007;
    while(n>1){
        if(ok){
            now = (pre+1)*3;
        }else{
            now = (pre-1)*3;
        }
        now%=m;
        pre = now;
        ok^=1;
        n--;
        //if(now>1000000007){
        //}
    }
    cout<<now<<endl;
    return 0;
}

