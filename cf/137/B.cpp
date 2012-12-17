#include <iostream>

using namespace std;

const int MAXN = 1005;

int N,M,K, data[MAXN][MAXN];

int row[MAXN];
int col[MAXN];


void work(){
    for(int i=0; i<MAXN; i++){
        row[i] = i;
        col[i] = i;
    }

    for(int i=0; i<K; i++){
        char command;
        cin>>command;
        int x,y;
        cin>>x>>y;
        if(command=='c'){
            swap(col[x],col[y]);
        }else if(command=='r'){
            swap(row[x],row[y]);
        }else{
            cout<<data[row[x]][col[y]]<<endl;
        }
    }
}


int main(){
    cin>>N>>M>>K;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            cin>>data[i][j];
        }
    }
    work();
    return 0;
}

