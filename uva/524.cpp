#include <iostream>
#include <string.h>
using namespace std;

int N;

const int MAXN = 18;
bool used[MAXN];
bool prime[1000];
int numbers[MAXN];

void compute_prime(){
    prime[2] = true;
    for(int i=3; i<1000; i++){
        bool ok = true;
        for(int j = 2; j*j<=i; j++){
            if(i%j==0){
                ok = false;
                break;
            }
        }
        if(ok==true)prime[i] = true;
    }
}
int num_solution = 0;
void dfs(int cur, int pre_num){
    if(cur==N&&prime[pre_num+1]){
        for(int i=0; i<N-1; i++){
            cout<<numbers[i]<<" ";
        }cout<<numbers[N-1]<<endl;
        return ;
    }
    for(int i=1; i<=N; i++){
        if(used[i]==false && prime[pre_num+i]){
            numbers[cur] = i;
            used[i] = true;
            dfs(cur+1, i);
            used[i] = false;
        }
    }
}

void work(){
    compute_prime();
    //cout<<"8 is prime ? "<<prime[8]<<endl;
    memset(used,0,sizeof(used));
    numbers[0] = 1;
    used[1] = true;
    dfs(1, 1);
}

int main(){
    int cases = 0;
    int z = 0;
    while(cin>>N){
        if(z)cout<<endl;
        cout<<"Case "<<++cases<<":"<<endl;
        z++;
        work();
    }
    return 0;
}
