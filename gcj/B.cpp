#include <iostream>

using namespace std;
int T, M, N;
const int MAXN = 150;
int mydata[MAXN][MAXN];


bool checkRow(int i, int j){
    bool left = true, right = true;
    for(int k=0; k<j; k++){
        if(mydata[i][k]>mydata[i][j]){
            left = false;
        }
    }
    for(int k=M-1; k>j; k--){
        if(mydata[i][k]>mydata[i][j]){
            right = false;
        }
    }
    if(left && right){
        return true;
    }
    return false;
}

bool checkCol(int i, int j){
    bool up = true, down = true;
    for(int k=0; k<i; k++){
        if(mydata[k][j]>mydata[i][j]){
            up = false;
        }
    }
    for(int k=N-1; k>i; k--){
        if(mydata[k][j]>mydata[i][j]){
            down = false;
        }
    }
    if(up&& down){
        return true;
    }
    return false;
}


void  work(){
    bool ok = true;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if( checkRow(i,j)==false && checkCol(i,j)==false){
                ok = false;
            }
        }
    }
    if(ok){
        cout<<"Case #"<<T<<": YES"<<endl;
    }else{
        cout<<"Case #"<<T<<": NO"<<endl;
    }
}

int main(){

    int n_case;
    cin>>n_case;
    for(T=1; T<=n_case; T++){
        cin>>N>>M;
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                cin>>mydata[i][j];
            }
        }
        work();
    }
    return 0;
}

