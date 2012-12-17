#include <iostream>

#define MAX_SIZE 200
using namespace std;
int n,m;
int data[MAX_SIZE][MAX_SIZE];

int get_max(int sub){
    int t_max = -99999999;
    for(int i=0; i<n; i++){
        if(data[i][sub]>t_max){
            t_max = data[i][sub];
        }
    }
    return t_max;
}


void work(){
    int stu=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            //cout<<j<<" "<<get_max(j)<<endl;
            if(get_max(j)==data[i][j]){
                stu+=1;
                break;
            }
        }
    }
    cout<<stu<<endl;

}


int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m ;j++){
            char c;
            //scanf("%c",&c);
            cin>>c;
            data[i][j] = c-'0';
            //cout<<data[i][j];
        }
        //cout<<endl;
    }
    work();



    return 0;
}

