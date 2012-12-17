#include <iostream>
#include <string.h>
#include <cmath>

using namespace std;

const int MAXN = 100001;
const int MAXM = 10000000;

int N,M;
int up[MAXN], down[MAXN];

int gcd(int a, int b){
    if( b== 0){
        return a;
    }else{
        return gcd(b, a%b);
    }
}

void work(){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(up[i]==1)break;
            //if(down[i]==1)continue;
            int d = gcd(up[i], down[j]);
            up[i]/=d;
            down[j]/=d;
        }
    }
    cout<<N<<" "<<M<<endl;
    cout<<up[0];
    for(int i=1; i<N; i++){
        cout<<" "<<up[i];
    }
    cout<<endl;
    
    cout<<down[0];
    for(int i=1; i<M; i++){
        cout<<" "<<down[i];
    }
    cout<<endl;
}

int main(){
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

