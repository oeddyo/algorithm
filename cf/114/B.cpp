#include <iostream>
#include <cmath>
#include <string>

using namespace std;

string text[

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

