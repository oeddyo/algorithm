#include <iostream>

#define MAX_SIZE 200
using namespace std;

char data[MAX_SIZE][MAX_SIZE];
int n,m;
void work(){
    long long int sum=1;
    for(int j=0; j<m; j++){
        int tmp[MAX_SIZE];
        for(int k =0; k<MAX_SIZE; k++)tmp[k]=0;
        int num=0;
        for(int i=0; i<n; i++){
            if(tmp[data[i][j] -'A']==0){
                tmp[data[i][j] - 'A']=1;
                num++;
            }else{
                continue;
            }
        }
        sum = sum*num % 1000000007;
    }
    cout<<sum<<endl;
}


int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m ;j++){
            char c;
            cin>>c;
            data[i][j] = c;
        }
    }
    work();



    return 0;
}

