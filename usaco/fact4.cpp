/*
ID: xieke.b1
PROB: fact4
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

ifstream fin("fact4.in");
ofstream fout("fact4.out");

typedef pair<int, int> pii;
const int MAXN = 5000;
const int INF = 2100000000;
int N;

bool prime[MAXN];
vector<int> primes;
void get_prime(){
    memset(prime, 0, sizeof(prime));
    prime[1] = 0;
    prime[2] = 1;
    primes.push_back(2);
    for(int i=3; i<MAXN; i++){
        bool is_prime = true;
        for(int j=2; j*j<=i; j++){
            if( i%j==0 ){
                is_prime = false;
                break;
            }
        }
        if(is_prime){
            prime[i] = 1;
            primes.push_back(i);
        }
    }
}

int count_fac[MAXN];

void factorize(int n){
    int sz = primes.size();
    int ptr = 0;
    /*
    for(int i=0; i<sz; i++){
        cout<<primes[i]<<" ";
    }cout<<endl;
*/
    while(1!=n){
        //cout<<"ptr at "<<ptr<<endl;
        if( 0 == n%primes[ptr] ){
            n/=primes[ptr];
            count_fac[primes[ptr]] ++;
            //cout<<primes[ptr]<<" ";
        }else{
            ptr++;
        }
    }
    //cout<<endl;
}

void work(){
    get_prime();
    for(int i=1; i<=N; i++){
        factorize(i);
    }

    int min_value = min(count_fac[2], count_fac[5]);
    count_fac[2]-=min_value;
    count_fac[5]-=min_value;
    
    int cur_value = 1;
    for(int i=0; i<MAXN; i++){
        for(int j=0; j<count_fac[i]; j++){
            cur_value*=i;
            cur_value%=10;
        }
    }
    fout<<cur_value<<endl;
}


int main(){
    fin>>N;
    work(); 
    


    return 0;
}

