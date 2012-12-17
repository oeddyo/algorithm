#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string.h>

using namespace std;

const int M = 1100000;
bool mark[M];

int N;
long long int data[M];
int prime_nums[M];
int cnt = 0;

void sieve_prime(){
    memset(mark, true, sizeof(mark));
    mark[0] = mark[1] = false;
    for(int i=2; i<=sqrt(M); i++){
        if(mark[i]){
            for(int j=i*i; j<M; j+=i){
                mark[j]=false;
            }
        }
    }
}



void work(){
    sieve_prime();
    for(int i=0; i<M; i++){
        if(mark[i]){
            prime_nums[cnt++] = i;
        }
    }
    vector< long long int > nums;
    for(int i=0; i<cnt; i++){
        long long int t = prime_nums[i];
        nums.push_back( t*t );
    }
    sort(nums.begin(), nums.end());
    for(int i=0; i<N; i++){
        if(binary_search( nums.begin(), nums.end(), data[i])){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
}

int main(){
  
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>data[i];
    }

    work();
    
    return 0;
}

