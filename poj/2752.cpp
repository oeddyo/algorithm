#include <iostream>
#include <string>


using namespace std;

const int MAXN = 500000;
string T;
int failure[MAXN];
bool mark[MAXN];
void work(){
    memset(mark,0,sizeof(mark));
    failure[0] = failure[1] = 0;
    int M = T.length();
    for(int i=2; i<=M; i++){
        int j = failure[i-1];
        for(;;){
            if(T[i-1]==T[j]){
                failure[i] = j+1;
                break;
            }
            if(j==0){
                failure[i] = 0;
                break;
            }
            j = failure[j];
        }
    }
    /*
    cout<<"print failure"<<endl;
    for(int i=0; i<=M; i++){
        cout<<failure[i]<<" ";
    }
    cout<<endl;
    */

    int t = M;
    while(1){
        if(t == 0)break;
        mark[t] = 1;
        t = failure[t];
    }

    for(int i=1; i<M; i++){
        if(mark[i]){
            cout<<i<<" ";
        }
    }
    cout<<M<<endl;
}


int main(){
    while(cin>>T){
        work();
    } 
    return 0;
}

