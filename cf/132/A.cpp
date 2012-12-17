#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>

using namespace std;
const int MAXN = 51;

int as[MAXN];
int bs[MAXN];
int n1, n2;
const double eps = 1e-10;
int ok[100001];
int main(){
    memset(ok,0,sizeof(ok));
    cin>>n1;
    for(int i=0; i<n1; i++)cin>>as[i];
    cin>>n2;
    for(int i=0; i<n2; i++)cin>>bs[i];
    int ans = -1;
    for(int i=0; i<n1; i++){
        for(int j=0; j<n2; j++){
            double t = bs[j]*1.0/as[i];
            if( t==bs[j]/as[i]){
                ok[ bs[j]/as[i] ] += 1;
            }
        }
    }
    for(int i=100000; i>=0; i--){
        if(ok[i]){
            cout<<ok[i]<<endl;
            break;
        }
    }


    return 0;
}

