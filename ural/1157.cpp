#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <string.h>

using namespace std;
 
#define DEBUG
#define REP(i,a) for(i=0;i<a;i++)
#define FOR(i,a,b) for(i=a;i<b;i++)
#define VE vector<int>
#define SZ size()
#define PB push_back

int M, N, K;
const int MAXN = 10001;
int my_count[MAXN];
vector<int> prime;
vector<int> numbers;
bool shown[MAXN];

void work(){
    for(int i=0; i<MAXN; i++)my_count[i] = 0;
    
    for(int i=2; i<MAXN; i++){
        int cnt = 0;
        bool ok = true;
        for(int j=2; j*j<=i; j++){
            if(i%j == 0){
                ok = false;
                break;
            }
        }
        if(ok)prime.push_back(i);
    }
    
    int p_size = prime.size();
    my_count[1] = 1;
    for(int i=1; i<MAXN; i++){
        int cur = i; 
        vector<int> pp;
        int res = 1;
        for(int j=0; j<p_size; j++){
            if(cur<j)break;
            if(cur % prime[j]==0){
                int tmp_cnt = 0;
                while(1){
                    if(cur < prime[j])break;
                    if(cur % prime[j] == 0){
                        pp.push_back(prime[j]);
                        cur /= prime[j];
                        tmp_cnt += 1;
                    }else{
                        break;
                    }
                }
                res *= tmp_cnt + 1;
            }
        }
        my_count[i] = (1 + res)/2;
    }


    bool ok = false;
    for(int i=1; i<MAXN; i++){
        if(my_count[i] == N && i - K>=1 && my_count[i-K] == M){
            ok = true;
            cout<<i<<endl;
            break;
        }
    }
    if(ok){
        return ;
    }else{
        cout<<0<<endl;
    }


}



int main(){
    cin>>M>>N>>K;
    work();
    return 0;
}

