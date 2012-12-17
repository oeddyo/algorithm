#include <iostream>

using namespace std;
int n,m;

int main(){
    cin>>n>>m;
    int count = 0;
    for(int a= 0; a<=1000; a++){
        for(int b=0; b<=1000; b++){
            if( a*a + b == n && a+b*b == m){
                count+=1;
            }
        }
    }
    cout<<count<<endl;

    return 0;
}

