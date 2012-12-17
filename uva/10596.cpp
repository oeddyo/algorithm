#include <iostream>
#include <string.h>

using namespace std;

const int MAXN = 300;
int N,R;
int degree[MAXN];
int g[MAXN][MAXN];

int main(){
    while( cin>>N>>R){
        int a,b;
        memset(degree,0,sizeof(degree));
        for(int i=0; i<R; i++){
            cin>>a>>b;
            degree[a]++;
            degree[b]++;
            g[a][b]++;
            g[b][a]++;
        }
        int not_ok = 0;
        for(int i=0; i<N; i++){
            if(degree[i]%2!=0){
                not_ok++;
            }
        }
        if(not_ok<=2){
            cout<<"Possible"<<endl;
        }else{
            cout<<"Not Possible"<<endl;
        }

    }
    return 0;
}

