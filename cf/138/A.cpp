#include <iostream>
#include <cmath>


using namespace std;


int main(){
    int x,y,z;
    cin>>x>>y>>z;
    
    int ans = 0;

    ans = 4*(sqrt(x*z/y) + sqrt(x*y/z) + sqrt(y*z/x));
    cout<<ans<<endl;

    return 0;
}

