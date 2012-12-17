#include <iostream>

using namespace std;
int N,M,T;
int sum = 0;
void dfs(int pre, int left, int pos){
    if(pos>N){
        return ;
    }
    if(pos==N && left==0){
        sum++;
        return ;
    }
    for(int i= pre; i<=left; i++){
        dfs(i ,left-i, pos+1);
    }
}



void work(){
    sum=0;
    dfs(0, M,0);
    cout<<sum<<endl;
}


int main(){
    cin>>T;
    while(T--){
        cin>>M>>N;
        work();
    }
    return 0;
}

