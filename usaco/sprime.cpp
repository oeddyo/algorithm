/*
ID: xieke.b1
PROG: sprime
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
ofstream fout("sprime.out");
ifstream fin ("sprime.in");
const int INF = 999999999;
int N;


int primes[10] = {1,2,3,5,7,9};
const int MAX_P = 100000;
bool prime[MAX_P];

vector<int> ans;

bool judge_prime(int number){
    int limit = sqrt(number);
    for(int i=2; i<=limit; i++){
        if(number%i==0)return false;
    }
    return true;
}

bool is_prime(int number){
    if(number<MAX_P){
        return prime[number];
    }else{
        return judge_prime(number);
    }
}


void dfs(int cur, int number){
    if(cur==N){        
        if(is_prime(number)){
            ans.push_back(number);
        }
        return ;
    }
    if( !is_prime(number) )return ;

    for(int i=0; i<6; i++){
        dfs(cur+1, number*10+primes[i]);
    }
}
void compute_prime(){
    prime[2] = 1;
    for(int i=3; i<MAX_P; i++){
        int limit = sqrt(i);
        bool ok = true;
        for(int j=2; j<=limit; j++){
            if( i%j == 0){
                ok=false;
                break;
            }
        }
        if(ok){
            prime[i] = true;
        }
    }
}


void work(){
    for(int i=0; i<6; i++){
        dfs(1, primes[i]);
    }
    
    for(int i=0; i<ans.size(); i++){
        fout<<ans[i]<<endl;
    }

}
int main(){
    fin>>N;
    compute_prime();
    work();
    return 0;
}

