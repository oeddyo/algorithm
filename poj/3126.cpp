#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
int A,B,T;
int cnt = 0;
int primes[10000];

void preprocess(){
    for(int i=1000; i<=9999; i++){
        bool is_prime = true;;
        for(int k=2; k*k<=i; k++){
            if(i%k==0){
                is_prime = false;
                break;
            }
        }
        if(is_prime){
            primes[i] = 1;
        }
    }
}

bool vis[10000];
typedef pair<int, int> mypair;
void work(){
    memset(vis,0,sizeof(vis));
    vis[A] = 1;
    queue< mypair > Q;
    Q.push(mypair(A,0));
    mypair cur, next;
    int ans = -1;
    while(!Q.empty()){
        cur = Q.front();
        Q.pop();
        if(cur.first==B){
            ans = cur.second; 
            break;
        }
        //cout<<"cur is "<<cur.first<<endl;
        for(int i=1; i<=1000; i*=10){
            for(int j=0; j<=9; j++){
                int origi_num = (cur.first/i)%10;
                
                next.first = (cur.first - origi_num*i)+j*i;
                if(next.first>9999 && next.first<1000 ){
                    continue;
                }
                if(primes[next.first]==0){
                    continue;
                }
                //cout<<"next -> "<<next.first<<endl;;
                if(vis[next.first]==0){
                    vis[next.first]=1;
                    Q.push( mypair(next.first,cur.second+1  ));
                }
            }
        }
    }
    if(ans==-1){
        cout<<"Impossible"<<endl;
    }else{
        cout<<ans<<endl;
    }
}

int main(){
    cin>>T;
    memset(primes,0,sizeof(primes));
    preprocess();
    while(T--){
        cin>>A>>B;
        work();
    }

    return 0;
}

