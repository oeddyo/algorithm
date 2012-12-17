#include <iostream>

using namespace std;
const int MAXN = 1000000;

long long int fib[MAXN],N;

bool is_prime(long long int k){
    
    for(int i=2; i*i<=k; i++){
        if( k%i==0 ){
            return false;
        }
    }
    return true;
}


int main(){
    cout<<"put the number"<<endl;
    fib[0]=1;
    fib[1]=1;
    cin>>N;
    for(int i=2; i<MAXN; i++){
        fib[i] = fib[i-1]+fib[i-2];
    }

    for(int i=0; i<MAXN; i++){
        if(fib[i]>N && is_prime( fib[i] ) ){
            cout<<"ans is "<<fib[i]<<endl;
            break;
        }
    }




    return 0;
}

