#include <iostream>
#include <cmath>

using namespace std;

int n,x,y;

int main(){
    cin>>n>>x>>y;

    int ans = ceil((y*n)/100.0) - x;
    
    if(ans<=0){
        cout<<0<<endl;
    }else{
        cout<<ans<<endl;
    }
    
    return 0;
}

