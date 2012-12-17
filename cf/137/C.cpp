#include <iostream>
#include <string.h>
#include <cmath>

using namespace std;

const int MAXN = 100000;
const int MAXM = 10000000;

int N;
int up[MAXN], down[MAXN];
bool primes[MAXN];
vector<int> pns;

int de_up[MAXM], de_down[MAXM];

void work(){
    memset(de_up,0,sizeof(de_up));
    memset(de_down, 0, sizeof(de_down));
    int sz_prime = pns.size();
    for(int i=0; i<N; i++){
        int cur = up[i];
        int limit = sqrt(cur)+1;
        for(int j=0; j<sz_prime && pns[j]<=limit; j++){
            while(cur%pns[j]==0){
                cur/=pns[j];
                de_up[ pns[j] ] +=1;
            }
        }
    }

    for(int i=0; i<M; i++){
        int cur = down[i];
        int limit = sqrt(cur)+1;
        for(int j=0; j<sz_prime && pns[j]<=limit; j++){
            while(cur%pns[j]==0){
                cur/=pns[j];
                de_down[ pns[j] ] +=1;
            }
        }
    }
    vector<int> ans_up;
    vector<int> ans_down;
    for(int i=0; i<MAXM; i++){
        int tmp = min(de_up[i], de_down[i]);
        de_up[i] -= tmp;
        de_down[i] -= tmp;
    }

    for(int i=0; i<MAXM; i++){
        if(de_up[i]==0 && de_down[i]!=0){
            ans_down.push_back(i);
        }else if(de_up[i]!=0 && de_down[i]==0){
            ans_up.push_back(i);
        }

}


void get_prime(){
    memset(primes, 1 , sizeof(primes));
    primes[2] = true;
    pns.push_back(2);
    for(int i=3; i<MAXN; i++){
        for(int j=2; j*j<=i; j++){
            if( i%j == 0){
                primes[i] = false;
                break;
            }
        }
    }
    for(int i=3; i<MAXN; i++){
        if(primes[i]){
            pns.push_back(i);
        }
    }
}


int main(){
    get_prime(); 
    
    cin>>N>>M;
    for(int i=0; i<N; i++){
        cin>>up[i];
    }
    for(int i=0; i<M; i++){
        cin>>down[i];
    }
    work();
    
    return 0;
}

