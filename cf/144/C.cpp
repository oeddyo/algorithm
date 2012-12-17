#include <iostream>
#include <map>
#include <vector>

using namespace std;

const int MAXN = 101;
const int INF = 99999999;
bool g[MAXN][MAXN];
int N;

int solve(int num){
    for(int x=1; x<=100; x++){
        int t = x*(x-1)*(x-2)/6;
        if(x*(x-1)*(x-2)/6 < num){
            continue;
        }else if(t==num){
            return x;
        }else if(t>num){
            return x-1;
        }
    }
}


void work(){
    int x = solve(N);
    cout<<"x is "<<x<<endl;
    for(int i=0; i<x; i++){
        for(int j=0; j<x; j++){
            if(i==j)g[i][j] = 0;
            else{
                g[i][j] = 1;
            }
        }
    }
    int left = N-x*(x-1)*(x-2)/6;
    if(left>0){
        for(int i=x; i<=100; i++){
            g[i][0] = 1;
            g[0][i] = 1;
            for(int j=1; j<x; j++){
                g[i][j] = 1;
                g[j][i] = 1;
                left--;
                //cout<<"left is "<<left<<endl;
                if(left==0)return ;
            }
        }
    }
    //cout<<"final left is "<<left<<endl;
}

int main(){
    cin>>N;
    work();
    cout<<100<<endl;
    for(int i=0; i<100; i++){
        for(int j=0; j<100; j++){
            if(g[i][j])
                cout<<1;
            else{
                cout<<0;
            }
        }
        cout<<endl;
    }

    return 0;
}

