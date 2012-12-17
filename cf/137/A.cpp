#include <iostream>

using namespace std;

const int MAXN = 500000;
int N,K, data[MAXN];

void work(){
    bool ok = true;
    
    int t = data[K-1];
    for(int i=K; i<N; i++){
        if(data[i]!=t){
            ok = false;
            break;
        }
    }
    if(ok){
        int num = 0;
        for(int i=K-1-1; i>=0; i--){
            if(data[i]==t){
                num++;
            }
        }
        cout<<(K-1) - num<<endl;
    }else{
        cout<<-1<<endl;
    }

}


int main(){
    cin>>N>>K;
    for(int i=0; i<N; i++){
        cin>>data[i];
    }
    work();
    return 0;
}

